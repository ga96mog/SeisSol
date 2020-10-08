//
// Created by adrian on 17.09.20.
//

#ifndef SEISSOL_DR_SOLVER_LINEAR_H
#define SEISSOL_DR_SOLVER_LINEAR_H


#include "DR_solver_base.h"
#include "DR_math.h"
#include <yaml-cpp/yaml.h>

namespace seissol {
  namespace dr {
    namespace fr_law {
      class LinearSlipWeakeningSolver;
      class LinearSlipWeakeningSolverFL2;  //linear slip weakening
      class LinearSlipWeakeningSolverFL16; //Linear slip weakening forced time rapture
      class LinearSlipWeakSolverBimaterialFL6;
    }
  }
}

/*
 * Abstract Class implementing the general structure of linear slip weakening friction laws.
 * specific implementation is done by overriding and implementing the hook functions.
 */
class seissol::dr::fr_law::LinearSlipWeakeningSolver : public seissol::dr::fr_law::BaseFrictionSolver {
protected:
  real                    u_0  = 10e-14; //slip rate is considered as being zero for instaneous healing
  real                    (*d_c)[numOfPointsPadded];
  real                    (*mu_S)[numOfPointsPadded];
  real                    (*mu_D)[numOfPointsPadded];
  bool                    (*DS)[numOfPointsPadded];
  real                    (*dynStress_time)[numOfPointsPadded];

public:
  /*
   * copies all parameters from the DynamicRupture LTS to the local attributes
   */

  void copyLtsTreeToLocal(seissol::initializers::Layer&  layerData,
                          seissol::initializers::DynamicRupture *dynRup, real fullUpdateTime) override {
    //first copy all Variables from the Base Lts dynRup tree
    BaseFrictionSolver::copyLtsTreeToLocal(layerData, dynRup, fullUpdateTime);
    //TODO: change later to const_cast
    seissol::initializers::DR_FL_2 *ConcreteLts = dynamic_cast<seissol::initializers::DR_FL_2 *>(dynRup);
    d_c                                           = layerData.var(ConcreteLts->d_c);
    mu_S                                          = layerData.var(ConcreteLts->mu_S);
    mu_D                                          = layerData.var(ConcreteLts->mu_D);
    DS                                            = layerData.var(ConcreteLts->DS);
    averaged_Slip                                 = layerData.var(ConcreteLts->averaged_Slip);
    dynStress_time                                = layerData.var(ConcreteLts->dynStress_time);
  }

protected:
  /*
   * compute the fault strength
   */
  virtual void calcStrengthHook(
      std::array<real, numOfPointsPadded> &Strength,
      FaultStresses &faultStresses,
      unsigned int iTimeGP,
      unsigned int ltsFace
  ) = 0;

  /*
   *  compute the slip rate and the traction from the fault strength and fault stresses
   *  also updates the directional slip1 and slip2
   */
  virtual void calcSlipRateAndTraction(
      std::array<real, numOfPointsPadded> &Strength,
      FaultStresses &faultStresses,
      unsigned int iTimeGP,
      unsigned int ltsFace
  ){
    std::array<real, numOfPointsPadded> TotalShearStressYZ;
    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {
      //-------------------------------------
      //calculate TotalShearStress in Y and Z direction
      TotalShearStressYZ[iBndGP] = std::sqrt(
          seissol::dr::aux::power(initialStressInFaultCS[ltsFace][iBndGP][3] + faultStresses.XYStressGP[iTimeGP][iBndGP], 2) +
          seissol::dr::aux::power(initialStressInFaultCS[ltsFace][iBndGP][5] + faultStresses.XZStressGP[iTimeGP][iBndGP], 2));

      //-------------------------------------
      // calculate SlipRates
      locSlipRate[ltsFace][iBndGP] = std::max(0.0, (TotalShearStressYZ[iBndGP] - Strength[iBndGP]) * impAndEta[ltsFace].inv_eta_s);
      //TODO: remove code like it was before:
      //LocSlipRate[iBndGP] = std::max(0.0, (TotalShearStressYZ[iBndGP] - Strength[iBndGP]) / impAndEta[face].eta_s);


      slipRate1[ltsFace][iBndGP] = locSlipRate[ltsFace][iBndGP] * (initialStressInFaultCS[ltsFace][iBndGP][3] + faultStresses.XYStressGP[iTimeGP][iBndGP]) / TotalShearStressYZ[iBndGP];
      slipRate2[ltsFace][iBndGP]  = locSlipRate[ltsFace][iBndGP] * (initialStressInFaultCS[ltsFace][iBndGP][5] + faultStresses.XZStressGP[iTimeGP][iBndGP]) / TotalShearStressYZ[iBndGP];
      //TODO: remove code like it was before:
/*
      slipRate1[face][iBndGP] = LocSlipRate[iBndGP] * (initialStressInFaultCS[face][iBndGP][3] + faultStresses.XYStressGP[iTimeGP][iBndGP]) /
                                (std::max(TotalShearStressYZ[iBndGP], Strength[iBndGP]));
      slipRate2[face][iBndGP]  = LocSlipRate[iBndGP] * (initialStressInFaultCS[face][iBndGP][5] + faultStresses.XZStressGP[iTimeGP][iBndGP]) /
                                 (std::max(TotalShearStressYZ[iBndGP], Strength[iBndGP]));
*/
      //-------------------------------------
      //calculateTraction
      faultStresses.TractionGP_XY[iTimeGP][iBndGP] = faultStresses.XYStressGP[iTimeGP][iBndGP] - impAndEta[ltsFace].eta_s * slipRate1[ltsFace][iBndGP];
      faultStresses.TractionGP_XZ[iTimeGP][iBndGP] = faultStresses.XZStressGP[iTimeGP][iBndGP] - impAndEta[ltsFace].eta_s * slipRate2[ltsFace][iBndGP];
      tracXY[ltsFace][iBndGP] = faultStresses.TractionGP_XY[iTimeGP][iBndGP];
      tracXZ[ltsFace][iBndGP] = faultStresses.TractionGP_XY[iTimeGP][iBndGP];

      //-------------------------------------
      //update Directional Slip
      slip1[ltsFace][iBndGP] = slip1[ltsFace][iBndGP] + slipRate1[ltsFace][iBndGP] * deltaT[iTimeGP];
      slip2[ltsFace][iBndGP] = slip2[ltsFace][iBndGP] + slipRate2[ltsFace][iBndGP] * deltaT[iTimeGP];
    }
  }

  /*
   *  compute and output the state Variable:
   *  for linear slip weakening state variable = slip
   */
  virtual void calcStateVariableHook(
      std::array<real, numOfPointsPadded> &stateVariablePsi,
      std::array<real, numOfPointsPadded> &outputSlip,
      dynamicRupture::kernel::resampleParameter &resampleKrnl,
      unsigned int iTimeGP,
      unsigned int ltsFace) = 0;

/*
 * evaluate friction law: updated mu -> friction law
 * for example see Carsten Uphoff's thesis: Eq. 2.45
 */
  virtual void frictionFunctionHook(std::array<real, numOfPointsPadded> &stateVariablePsi, unsigned int ltsFace) = 0;

  /*
   * instantaneous healing option Reset Mu and Slip
   */
  virtual void instantaneousHealing(unsigned int ltsFace){
    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {
      if (locSlipRate[ltsFace][iBndGP] < u_0) {
        mu[ltsFace][iBndGP] = mu_S[ltsFace][iBndGP];
        slip[ltsFace][iBndGP] = 0.0;
      }
    }
  }

/*
 * output time when shear stress is equal to the dynamic stress after rupture arrived
 * currently only for linear slip weakening
 */
  virtual void outputDynamicStress(
      unsigned int ltsFace
  ){
    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {

      if (rupture_time[ltsFace][iBndGP] > 0.0 &&
          rupture_time[ltsFace][iBndGP] <= m_fullUpdateTime &&
          DS[iBndGP] &&
          std::fabs(slip[ltsFace][iBndGP]) >= d_c[ltsFace][iBndGP]) {
        dynStress_time[ltsFace][iBndGP] = m_fullUpdateTime;
        DS[ltsFace][iBndGP] = false;
      }
    }
  }

public:
  virtual void evaluate(seissol::initializers::Layer&  layerData,
                        seissol::initializers::DynamicRupture *dynRup,
                        real (*QInterpolatedPlus)[CONVERGENCE_ORDER][tensor::QInterpolated::size()],
                        real (*QInterpolatedMinus)[CONVERGENCE_ORDER][tensor::QInterpolated::size()],
                        real fullUpdateTime,
                        real timeWeights[CONVERGENCE_ORDER]) override {

    copyLtsTreeToLocal(layerData, dynRup, fullUpdateTime);

#ifdef _OPENMP
#pragma omp parallel for schedule(static)
#endif
    for (unsigned ltsFace = 0; ltsFace < layerData.getNumberOfCells(); ++ltsFace) {
      //initialize struct for in/outputs stresses
      FaultStresses faultStresses{};

      //declare local variables
      dynamicRupture::kernel::resampleParameter resampleKrnl;
      resampleKrnl.resampleM = init::resample::Values;

      std::array<real, numOfPointsPadded> outputSlip{0};
      std::array<real, numOfPointsPadded> stateVariablePsi{0};
      std::array<real, numOfPointsPadded> Strength{0};

      precomputeStressFromQInterpolated(faultStresses, QInterpolatedPlus[ltsFace], QInterpolatedMinus[ltsFace], ltsFace);

      for (int iTimeGP = 0; iTimeGP < CONVERGENCE_ORDER; iTimeGP++) {  //loop over time steps
        calcStrengthHook(Strength, faultStresses, iTimeGP, ltsFace);

        calcSlipRateAndTraction(Strength, faultStresses, iTimeGP , ltsFace);

        //function g, output: stateVariablePsi & outputSlip
        calcStateVariableHook(stateVariablePsi, outputSlip, resampleKrnl, iTimeGP, ltsFace);

        //function f, output: calculated mu
        frictionFunctionHook(stateVariablePsi, ltsFace);

        //instantaneous healing option Reset Mu and Slip
        if (m_Params->IsInstaHealingOn == true) {
          instantaneousHealing(ltsFace);
        }
      }//End of iTimeGP-Loop

      // output rupture front
      // outside of iTimeGP loop in order to safe an 'if' in a loop
      // this way, no subtimestep resolution possible
      outputRuptureFront(ltsFace);

      //output time when shear stress is equal to the dynamic stress after rupture arrived
      //currently only for linear slip weakening
      outputDynamicStress(ltsFace);

      //output peak slip rate
      calcPeakSlipRate(ltsFace);

      //---compute and store slip to determine the magnitude of an earthquake ---
      //    to this end, here the slip is computed and averaged per element
      //    in calc_seissol.f90 this value will be multiplied by the element surface
      //    and an output happened once at the end of the simulation
      calcAverageSlip(outputSlip, ltsFace);

      postcomputeImposedStateFromNewStress(
          QInterpolatedPlus[ltsFace], QInterpolatedMinus[ltsFace],
          faultStresses, timeWeights, ltsFace);
    }//End of Loop over Faces
  }//End of Function evaluate


  virtual void evaluateCurrentFace(real QInterpolatedPlus[CONVERGENCE_ORDER][tensor::QInterpolated::size()],
                              real QInterpolatedMinus[CONVERGENCE_ORDER][tensor::QInterpolated::size()],
                              real timeWeights[CONVERGENCE_ORDER],
                              unsigned int ltsFace) override {

    //initialize struct for in/outputs stresses
    FaultStresses faultStresses{};

    //declare local variables
    dynamicRupture::kernel::resampleParameter resampleKrnl;
    resampleKrnl.resampleM = init::resample::Values;

    std::array<real, numOfPointsPadded> outputSlip{0};
    std::array<real, numOfPointsPadded> stateVariablePsi{0};
    std::array<real, numOfPointsPadded> Strength{0};

    precomputeStressFromQInterpolated(faultStresses, QInterpolatedPlus, QInterpolatedMinus, ltsFace);

    for (int iTimeGP = 0; iTimeGP < CONVERGENCE_ORDER; iTimeGP++) {  //loop over time steps
      calcStrengthHook(Strength, faultStresses, iTimeGP, ltsFace);

      calcSlipRateAndTraction(Strength, faultStresses, iTimeGP , ltsFace);

      //function g, output: stateVariablePsi & outputSlip
      calcStateVariableHook(stateVariablePsi, outputSlip, resampleKrnl, iTimeGP, ltsFace);

      //function f, output: calculated mu
      frictionFunctionHook(stateVariablePsi, ltsFace);

      //instantaneous healing option Reset Mu and Slip
      if (m_Params->IsInstaHealingOn == true) {
        instantaneousHealing(ltsFace);
      }
    }//End of iTimeGP-Loop

    // output rupture front
    // outside of iTimeGP loop in order to safe an 'if' in a loop
    // this way, no subtimestep resolution possible
    outputRuptureFront(ltsFace);

    //output time when shear stress is equal to the dynamic stress after rupture arrived
    //currently only for linear slip weakening
    outputDynamicStress(ltsFace);

    //output peak slip rate
    calcPeakSlipRate(ltsFace);

    //---compute and store slip to determine the magnitude of an earthquake ---
    //    to this end, here the slip is computed and averaged per element
    //    in calc_seissol.f90 this value will be multiplied by the element surface
    //    and an output happened once at the end of the simulation
    calcAverageSlip(outputSlip, ltsFace);

    postcomputeImposedStateFromNewStress(
        QInterpolatedPlus, QInterpolatedMinus,
        faultStresses, timeWeights, ltsFace);

  }


};//End of Class

/*
*     !> friction case 16,17
*     !> Specific conditions for SCEC TPV16/17
*     !> basically, introduction of a time dependent forced rupture
*/
class seissol::dr::fr_law::LinearSlipWeakeningSolverFL2 : public seissol::dr::fr_law::LinearSlipWeakeningSolver {
protected:

  virtual void calcStrengthHook(
      std::array<real, numOfPointsPadded> &Strength,
      FaultStresses &faultStresses,
      unsigned int iTimeGP,
      unsigned int ltsFace
  ) override {
    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {
      //-------------------------------------
      //calculate Fault Strength
      //fault strength (Uphoff eq 2.44)
      Strength[iBndGP] = cohesion[ltsFace][iBndGP] - mu[ltsFace][iBndGP] * std::min(initialStressInFaultCS[ltsFace][iBndGP][0] + faultStresses.NorStressGP[iTimeGP][iBndGP], 0.0);
    }
  }

  virtual void calcStateVariableHook(
      std::array<real, numOfPointsPadded> &stateVariablePsi,
      std::array<real, numOfPointsPadded> &outputSlip,
      dynamicRupture::kernel::resampleParameter &resampleKrnl,
      unsigned int iTimeGP,
      unsigned int ltsFace) override {

    real resampledSlipRate[numberOfPoints];
    resampleKrnl.resamplePar = locSlipRate[ltsFace];
    resampleKrnl.resampledPar = resampledSlipRate;  //output from execute

    //Resample slip-rate, such that the state (Slip) lies in the same polynomial space as the degrees of freedom
    //resampleMatrix first projects LocSR on the two-dimensional basis on the reference triangle with
    //degree less or equal than CONVERGENCE_ORDER-1, and then evaluates the polynomial at the quadrature points
    resampleKrnl.execute();

    //TODO: does not work with padded Points bc of resampleMatrix is not padded
    for (int iBndGP = 0; iBndGP < numberOfPoints; iBndGP++) {
      //-------------------------------------
      //integrate Sliprate To Get Slip = State Variable
      slip[ltsFace][iBndGP] = slip[ltsFace][iBndGP] + resampledSlipRate[iBndGP] * deltaT[iTimeGP];
      outputSlip[iBndGP] = outputSlip[iBndGP] + locSlipRate[ltsFace][iBndGP] * deltaT[iTimeGP];

      //-------------------------------------
      //Modif T. Ulrich-> generalisation of tpv16/17 to 30/31
      //actually slip is already the stateVariable for this FL, but to simplify the next equations we divide it here by d_C
      stateVariablePsi[iBndGP] = std::min(std::fabs(slip[ltsFace][iBndGP]) / d_c[ltsFace][iBndGP], 1.0);
    }
  }

  //Carsten Thesis: Eq. 2.45
  //evaluate friction law: updated mu -> friction law
  void frictionFunctionHook(std::array<real, numOfPointsPadded> &stateVariablePsi, unsigned int ltsFace) override {
    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {
      mu[ltsFace][iBndGP] = mu_S[ltsFace][iBndGP] - (mu_S[ltsFace][iBndGP] - mu_D[ltsFace][iBndGP]) * stateVariablePsi[iBndGP];
    }
  }

};//End of Class



class seissol::dr::fr_law::LinearSlipWeakeningSolverFL16 : public seissol::dr::fr_law::LinearSlipWeakeningSolverFL2 {
protected:
  real                    (*forced_rupture_time)[numOfPointsPadded];
  real                    *tn;


  virtual void precomputeStressFromQInterpolated(
      FaultStresses &faultStresses,
      real QInterpolatedPlus[CONVERGENCE_ORDER][tensor::QInterpolated::size()],
      real QInterpolatedMinus[CONVERGENCE_ORDER][tensor::QInterpolated::size()],
      unsigned int ltsFace
  ) override {
    LinearSlipWeakeningSolverFL2::precomputeStressFromQInterpolated(faultStresses, QInterpolatedPlus, QInterpolatedMinus, ltsFace);
    tn[ltsFace] = m_fullUpdateTime;
  }

  /*
* copies all parameters from the DynamicRupture LTS to the local attributes
*/
  void copyLtsTreeToLocal(seissol::initializers::Layer&  layerData,
                          seissol::initializers::DynamicRupture *dynRup, real fullUpdateTime) override {
    //first copy all Variables from the Base Lts dynRup tree
    LinearSlipWeakeningSolverFL2::copyLtsTreeToLocal(layerData, dynRup, fullUpdateTime);
    //TODO: change later to const_cast
    seissol::initializers::DR_FL_16 *ConcreteLts = dynamic_cast<seissol::initializers::DR_FL_16 *>(dynRup);
    forced_rupture_time                           = layerData.var(ConcreteLts->forced_rupture_time);
    tn                                            = layerData.var(ConcreteLts->tn);
  }

  virtual void calcStateVariableHook(
      std::array<real, numOfPointsPadded> &stateVariablePsi,
      std::array<real, numOfPointsPadded> &outputSlip,
      dynamicRupture::kernel::resampleParameter &resampleKrnl,
      unsigned int iTimeGP,
      unsigned int ltsFace) override{
    LinearSlipWeakeningSolverFL2::calcStateVariableHook(stateVariablePsi, outputSlip, resampleKrnl, iTimeGP, ltsFace);
    tn[ltsFace] += deltaT[iTimeGP];

    for (int iBndGP = 0; iBndGP < numberOfPoints; iBndGP++) {
      real f2 = 0.0;
      if (m_Params->t_0 == 0) {
        if (tn[ltsFace] >= forced_rupture_time[ltsFace][iBndGP] ) {
          f2 = 1.0;
        } else {
          f2 = 0.0;
        }
      } else {
        f2 = std::max(0.0, std::min( 1.0, (m_fullUpdateTime - forced_rupture_time[ltsFace][iBndGP] ) / m_Params->t_0));
      }
      stateVariablePsi[iBndGP] = std::max(stateVariablePsi[iBndGP], f2);
    }
  }
};

class seissol::dr::fr_law::LinearSlipWeakSolverBimaterialFL6 : public seissol::dr::fr_law::LinearSlipWeakeningSolverFL2 {
protected:
  //Attributes
  real  (*strengthData)[numOfPointsPadded];

  /*
 * copies all parameters from the DynamicRupture LTS to the local attributes
 */
  void copyLtsTreeToLocal(seissol::initializers::Layer&  layerData,
                          seissol::initializers::DynamicRupture *dynRup, real fullUpdateTime) override {
    //first copy all Variables from the Base Lts dynRup tree
    LinearSlipWeakeningSolverFL2::copyLtsTreeToLocal(layerData, dynRup, fullUpdateTime);
    //TODO: change later to const_cast
    seissol::initializers::DR_FL_6 *ConcreteLts = dynamic_cast<seissol::initializers::DR_FL_6 *>(dynRup);
    strengthData = layerData.var(ConcreteLts->strengthData);
  }

  /*
   * calculates strength
   */
  void prak_clif_mod(real &strength, real &sigma, real &LocSlipRate, real &mu, real &dt){
    real expterm;
    expterm = std::exp(-(std::abs(LocSlipRate) + m_Params->v_star)*dt/ m_Params->prakash_length);
    strength =  strength*expterm - std::max(0.0,-mu*sigma)*(expterm-1.0);
  }

  virtual void calcStrengthHook(
      std::array<real, numOfPointsPadded> &Strength,
      FaultStresses &faultStresses,
      unsigned int iTimeGP,
      unsigned int ltsFace
  ) override{
    std::array<real, numOfPointsPadded> LocSlipRate;
    std::array<real, numOfPointsPadded> sigma;

    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {
      //  modify strength according to prakash clifton
      // literature e.g.: Pelties - Verification of an ADER-DG method for complex dynamic rupture problems
      LocSlipRate[iBndGP] = std::sqrt(slipRate1[ltsFace][iBndGP]*slipRate1[ltsFace][iBndGP] + slipRate2[ltsFace][iBndGP]*slipRate2[ltsFace][iBndGP]);
      sigma[iBndGP] = faultStresses.NorStressGP[iTimeGP][iBndGP]+initialStressInFaultCS[ltsFace][iBndGP][0];
      prak_clif_mod(strengthData[ltsFace][iBndGP], sigma[iBndGP], LocSlipRate[iBndGP], mu[ltsFace][iBndGP], deltaT[iTimeGP]);

      //TODO: add this line to make the FL6 actually functional: (this line is also missing in the master branch)
      //Strength[iBndGP] = strengthData[ltsFace][iBndGP];
    }
  }

  virtual void calcStateVariableHook(
      std::array<real, numOfPointsPadded> &stateVariablePsi,
      std::array<real, numOfPointsPadded> &outputSlip,
      dynamicRupture::kernel::resampleParameter &resampleKrnl,
      unsigned int iTimeGP,
      unsigned int ltsFace) override {
    for (int iBndGP = 0; iBndGP < numOfPointsPadded; iBndGP++) {
      slip[ltsFace][iBndGP] = slip[ltsFace][iBndGP] + locSlipRate[ltsFace][iBndGP]*deltaT[iTimeGP];
      outputSlip[iBndGP] = slip[ltsFace][iBndGP];

      //-------------------------------------
      //Modif T. Ulrich-> generalisation of tpv16/17 to 30/31
      //actually slip is already the stateVariable for this FL, but to simplify the next equations we divide it here by d_C
      stateVariablePsi[iBndGP] = std::min(std::fabs(slip[ltsFace][iBndGP]) / d_c[ltsFace][iBndGP], 1.0);
    }
  }
};


#endif //SEISSOL_DR_SOLVER_LINEAR_H

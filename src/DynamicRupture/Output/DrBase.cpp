#include <unordered_map>
#include "Solver/Interoperability.h"
#include "Initializer/tree/Layer.hpp"
#include "Initializer/DynamicRupture.h"
#include "SeisSol.h"
#include "DrBase.hpp"
#include "ResultWriter/common.hpp"


std::vector<double> getAllVertices(const seissol::dr::ReceiverPointsT& receiverPoints) {
  std::vector<double> vertices(3 * (3  * receiverPoints.size()), 0.0);

  for (size_t pointIndex{0}; pointIndex < receiverPoints.size(); ++pointIndex) {
    for (int vertexIndex{0}; vertexIndex < 3; ++vertexIndex) {
      const size_t globalVertexIndex = 3 * pointIndex + vertexIndex;

      vertices[3 * globalVertexIndex] = receiverPoints[pointIndex].globalSubTet.points[vertexIndex].x;
      vertices[3 * globalVertexIndex + 1] = receiverPoints[pointIndex].globalSubTet.points[vertexIndex].y;
      vertices[3 * globalVertexIndex + 2] = receiverPoints[pointIndex].globalSubTet.points[vertexIndex].z;
    }
  }
  return vertices;
}


std::vector<unsigned int> getCellConnectivity(const seissol::dr::ReceiverPointsT& receiverPoints) {
  std::vector<unsigned int> cells(3 * receiverPoints.size());

  for (size_t pointIndex{0}; pointIndex < receiverPoints.size(); ++pointIndex) {
    for (int vertexIndex{0}; vertexIndex < 3; ++vertexIndex) {
      const size_t globalVertexIndex = 3 * pointIndex + vertexIndex;
      cells[globalVertexIndex] = globalVertexIndex;
    }
  }
  return cells;
}


std::unique_ptr<int []> convertMaskFromBoolToInt(const std::array<bool, 12>& boolMask) {
  auto intMask = std::unique_ptr<int []>(new int[boolMask.size()]);

  for (size_t i = 0; i < boolMask.size(); ++i) {
    intMask[i] = static_cast<int>(boolMask[i]);
  }

  return intMask;
}


void seissol::dr::output::Base::init(const std::unordered_map<std::string, double*>& FaultParams) {
  if (ewOutputBuilder) {
    ewOutputBuilder->init(FaultParams);

    const auto& receiverPoints = ewOutputBuilder->receiverPoints;
    auto cellConnectivity = getCellConnectivity(receiverPoints);
    auto vertices = getAllVertices(receiverPoints);
    auto intMask = convertMaskFromBoolToInt(ewOutputBuilder->elementwiseParams.outputMask);

    std::string newFaultFilePrefix = generalParams.outputFilePrefix + std::string("-new");
    double printTime = ewOutputBuilder->elementwiseParams.printTimeIntervalSec;
    auto backendType = seissol::writer::backendType(generalParams.xdmfWriterBackend.c_str());

   std::vector<real*> dataPointers;
   auto recordPointers = [&dataPointers](auto& var, int) {
     if (var.isActive) {
       for (int dim = 0; dim < var.dim(); ++dim)
        dataPointers.push_back(var.data[dim]);
     }
   };
   aux::forEach(ewOutputBuilder->drVars, recordPointers);


   seissol::SeisSol::main.secondFaultWriter().init(cellConnectivity.data(),
                                                    vertices.data(),
                                                    static_cast<unsigned int>(receiverPoints.size()),
                                                    static_cast<unsigned int>(3 * receiverPoints.size()),
                                                    &intMask[0],
                                                    const_cast<const real**>(dataPointers.data()),
                                                    newFaultFilePrefix.data(),
                                                    printTime,
                                                    backendType);

    seissol::SeisSol::main.secondFaultWriter().setupCallbackObject(this);
  }

  if (ppOutputBuilder) {
    ppOutputBuilder->init();
  }
}

void seissol::dr::output::Base::initFaceToLtsMap() {

  faceToLtsMap.resize(drTree->getNumberOfCells(Ghost));
  for (auto it = drTree->beginLeaf(initializers::LayerMask(Ghost));
       it != drTree->endLeaf(); ++it) {

    DRFaceInformation* faceInformation = it->var(dynRup->faceInformation);
    for (size_t ltsFace = 0; ltsFace < it->getNumberOfCells(); ++ltsFace) {
      faceToLtsMap[faceInformation[ltsFace].meshFace] = std::make_pair(&(*it), ltsFace);
    }
  }
}

void seissol::dr::output::Base::writePickpointOutput() {

}


void seissol::dr::output::Base::updateElementwiseOutput() {
  calcFaultOutput(ewOutputState);
}


using DrPaddedArrayT = real (*)[seissol::init::QInterpolated::Stop[0]];
void seissol::dr::output::Base::calcFaultOutput(const OutputState& state) {

  {
    auto &functionAndState = std::get<VariableID::FunctionAndState>(ewOutputBuilder->drVars);
    if (functionAndState.isActive) {
      for (size_t i = 0; i < functionAndState.size; ++i) {
        auto ltsMap = faceToLtsMap[ewOutputBuilder->receiverPoints[i].faultFaceIndex];
        auto mu = reinterpret_cast<DrPaddedArrayT>(ltsMap.first->var(dynRup->mu));

        const auto nearestGp = ewOutputBuilder->receiverPoints[i].nearestGpIndex;
        functionAndState[ParamID::FUNCTION][i] = mu[ltsMap.second][nearestGp];
      }
    }
  }


  {
    auto &ruptureTime = std::get<VariableID::RuptureTime>(ewOutputBuilder->drVars);
    if (ruptureTime.isActive) {
      for (size_t i = 0; i < ruptureTime.size; ++i) {
        auto ltsMap = faceToLtsMap[ewOutputBuilder->receiverPoints[i].faultFaceIndex];
        auto rt = reinterpret_cast<DrPaddedArrayT>(ltsMap.first->var(dynRup->rupture_time));

        const auto nearestGp = ewOutputBuilder->receiverPoints[i].nearestGpIndex;
        ruptureTime[0][i] = rt[ltsMap.second][nearestGp];
      }
    }
  }


  {
    auto &absoluteSlip = std::get<VariableID::AbsoluteSlip>(ewOutputBuilder->drVars);
    if (absoluteSlip.isActive) {
      for (size_t i = 0; i < absoluteSlip.size; ++i) {
        auto ltsMap = faceToLtsMap[ewOutputBuilder->receiverPoints[i].faultFaceIndex];
        auto slip = reinterpret_cast<DrPaddedArrayT>(ltsMap.first->var(dynRup->slip));

        const auto nearestGp = ewOutputBuilder->receiverPoints[i].nearestGpIndex;
        absoluteSlip[0][i] = slip[ltsMap.second][nearestGp];
      }
    }
  }


  {
    auto &peakSlipsRate = std::get<VariableID::PeakSlipsRate>(ewOutputBuilder->drVars);
    if (peakSlipsRate.isActive) {
      for (size_t i = 0; i < peakSlipsRate.size; ++i) {
        auto ltsMap = faceToLtsMap[ewOutputBuilder->receiverPoints[i].faultFaceIndex];
        auto peakSR = reinterpret_cast<DrPaddedArrayT>(ltsMap.first->var(dynRup->peakSR));

        const auto nearestGp = ewOutputBuilder->receiverPoints[i].nearestGpIndex;
        peakSlipsRate[0][i] = peakSR[ltsMap.second][nearestGp];
      }
    }
  }
}
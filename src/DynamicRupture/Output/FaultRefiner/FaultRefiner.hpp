#ifndef SEISSOL_FAULTREFINER_HPP
#define SEISSOL_FAULTREFINER_HPP

#include "QuadFaultFaceRefiner.hpp"
#include "TripleFaultFaceRefiner.hpp"
#include <memory>

namespace seissol {
  namespace dr {
    namespace output {
      std::unique_ptr<FaultRefinerInterface> getRefiner(int strategy);
    }
  }
}


#endif //SEISSOL_FAULTREFINER_HPP
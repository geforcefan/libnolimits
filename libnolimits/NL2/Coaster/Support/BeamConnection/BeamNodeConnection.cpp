#include "BeamNodeConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        uint32_t BeamNodeConnection::getBeamIndex() const {
            return getIndex1();
        }

        void BeamNodeConnection::setBeamIndex(const uint32_t &value) {
            setIndex1(value);
        }

        uint32_t BeamNodeConnection::getBeamNodeIndex() const {
            return getIndex2();
        }

        void BeamNodeConnection::setBeamNodeIndex(const uint32_t &value) {
            setIndex2(value);
        }
    }
}

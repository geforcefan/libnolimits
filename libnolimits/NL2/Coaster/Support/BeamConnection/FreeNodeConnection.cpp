#include "FreeNodeConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        uint32_t FreeNodeConnection::getFreeNodeIndex() const {
            return getIndex1();
        }

        void FreeNodeConnection::setFreeNodeIndex(const uint32_t &value) {
            setIndex1(value);
        }
    }
}

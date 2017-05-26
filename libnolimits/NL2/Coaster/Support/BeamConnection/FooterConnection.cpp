#include "FooterConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        uint32_t FooterConnection::getFooterIndex() const {
            return getIndex1();
        }

        void FooterConnection::setFooterIndex(const uint32_t &value) {
            setIndex1(value);
        }
    }
}

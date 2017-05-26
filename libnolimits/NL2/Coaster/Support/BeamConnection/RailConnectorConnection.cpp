#include "RailConnectorConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        uint32_t RailConnectorConnection::getTrackIndex() const {
            return getIndex1();
        }

        void RailConnectorConnection::setTrackIndex(const uint32_t &value) {
            setIndex1(value);
        }

        uint32_t RailConnectorConnection::getRailConnectorIndex() const {
            return getIndex2();
        }

        void RailConnectorConnection::setRailConnectorIndex(const uint32_t &value) {
            setIndex2(value);
        }

        uint32_t RailConnectorConnection::getIndex() const {
            return getIndex3();
        }

        void RailConnectorConnection::setIndex(const uint32_t &value) {
            setIndex3(value);
        }
    }
}

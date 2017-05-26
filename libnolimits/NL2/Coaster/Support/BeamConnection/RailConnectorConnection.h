#ifndef LIB_NL2PARK_RAIL_CONNECTOR_CONNECTION_H
#define LIB_NL2PARK_RAIL_CONNECTOR_CONNECTION_H

#include "BeamConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        class RailConnectorConnection : public BeamConnection {
        public:
            RailConnectorConnection() : BeamConnection() {
                setType(BeamConnection::Type::RailConnector);
            }

            uint32_t getTrackIndex() const;
            void setTrackIndex(const uint32_t &value);

            uint32_t getRailConnectorIndex() const;
            void setRailConnectorIndex(const uint32_t &value);

            uint32_t getIndex() const;
            void setIndex(const uint32_t &value);
        };
    }
}

#endif // LIB_NL2PARK_RAIL_CONNECTOR_CONNECTION_H

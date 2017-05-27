#ifndef LIB_NL2PARK_BEAM_NODE_CONNECTION_H
#define LIB_NL2PARK_BEAM_NODE_CONNECTION_H

#include "BeamConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        class BeamNodeConnection : public BeamConnection {
        public:
            BeamNodeConnection() : BeamConnection() {
                setType(BeamConnection::Type::BeamNode);
            }

            BeamNodeConnection(uint32_t beamIndex, uint32_t beamNodeIndex) : BeamNodeConnection() {
                setBeamIndex(beamIndex);
                setBeamNodeIndex(beamNodeIndex);
            }

            uint32_t getBeamIndex() const;
            void setBeamIndex(const uint32_t &value);

            uint32_t getBeamNodeIndex() const;
            void setBeamNodeIndex(const uint32_t &value);
        };
    }
}

#endif // LIB_NL2PARK_BEAM_NODE_CONNECTION_H

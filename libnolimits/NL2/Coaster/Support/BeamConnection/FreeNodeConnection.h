#ifndef LIB_NL2PARK_FREE_NODE_CONNECTION_H
#define LIB_NL2PARK_FREE_NODE_CONNECTION_H

#include "BeamConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        class FreeNodeConnection : public BeamConnection {
        public:
            FreeNodeConnection() : BeamConnection() {
                setType(BeamConnection::Type::FreeNode);
            }

            FreeNodeConnection(uint32_t freeNodeIndex) : FreeNodeConnection() {
                setFreeNodeIndex(freeNodeIndex);
            }

            uint32_t getFreeNodeIndex() const;
            void setFreeNodeIndex(const uint32_t &value);
        };
    }
}

#endif // LIB_NL2PARK_FREE_NODE_CONNECTION_H

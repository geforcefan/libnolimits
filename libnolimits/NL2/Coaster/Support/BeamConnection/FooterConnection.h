#ifndef LIB_NL2PARK_FOOTER_CONNECTION_H
#define LIB_NL2PARK_FOOTER_CONNECTION_H

#include "BeamConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        class FooterConnection : public BeamConnection {
        public:
            FooterConnection() : BeamConnection() {
                setType(BeamConnection::Type::Footer);
            }

            FooterConnection(uint32_t footerIndex) : FooterConnection() {
                setFooterIndex(footerIndex);
            }

            uint32_t getFooterIndex() const;
            void setFooterIndex(const uint32_t &value);
        };
    }
}

#endif // LIB_NL2PARK_FOOTER_CONNECTION_H

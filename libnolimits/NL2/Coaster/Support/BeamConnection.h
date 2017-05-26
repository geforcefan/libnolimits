#ifndef LIB_NL2PARK_BEAMCONNECTION_H
#define LIB_NL2PARK_BEAMCONNECTION_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class BeamConnection : public Stream::Chunk {
        public:
            enum Type {
                None,
                FreeNode,
                Footer,
                RailConnector,
                BeamNode
            };

            BeamConnection() {
                setType(Type::None);
                setIndex(0);
                setIndexOnBeam(0);
                setIndexOnRailConnector(0);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "BeamConnection[getType]: " << getType() << std::endl;
                std::cout << "BeamConnection[getIndex]: " << getIndex() << std::endl;
                std::cout << "BeamConnection[getIndexOnBeam]: " << getIndexOnBeam() << std::endl;
                std::cout << "BeamConnection[getIndexOnRailConnector]: " << getIndexOnRailConnector() << std::endl;
            }

            Type getType() const;
            void setType(const Type &value);

            uint32_t getIndex() const;
            void setIndex(const uint32_t &value);

            uint32_t getIndexOnBeam() const;
            void setIndexOnBeam(const uint32_t &value);

            uint32_t getIndexOnRailConnector() const;
            void setIndexOnRailConnector(const uint32_t &value);
        private:
            Type type;
            uint32_t index;
            uint32_t indexOnBeam;
            uint32_t indexOnRailConnector;
        };
    }
}

#endif // LIB_NL2PARK_BEAMCONNECTION_H

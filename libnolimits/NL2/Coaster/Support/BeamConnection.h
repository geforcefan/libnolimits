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
                setIndex1(0);
                setIndex2(0);
                setIndex3(0);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "BeamConnection[getType]: " << getType() << std::endl;
                std::cout << "BeamConnection[getIndex1]: " << getIndex1() << std::endl;
                std::cout << "BeamConnection[getIndex2]: " << getIndex2() << std::endl;
                std::cout << "BeamConnection[getIndex3]: " << getIndex3() << std::endl;
            }

            Type getType() const;
            void setType(const Type &value);

            uint32_t getIndex1() const;
            void setIndex1(const uint32_t &value);

            uint32_t getIndex2() const;
            void setIndex2(const uint32_t &value);

            uint32_t getIndex3() const;
            void setIndex3(const uint32_t &value);
        private:
            Type type;
            uint32_t index1;
            uint32_t index2;
            uint32_t index3;
        };
    }
}

#endif // LIB_NL2PARK_BEAMCONNECTION_H

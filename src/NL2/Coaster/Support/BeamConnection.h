#ifndef LIB_NL2PARK_BEAMCONNECTION_H
#define LIB_NL2PARK_BEAMCONNECTION_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class BeamConnection : public Stream::Chunk {
        public:
            enum Type {
                FreeNode = 1,
                Footer = 2,
                RailConnector = 3,
                BeamNode = 4
            };

            BeamConnection() {}

            void read(File::File *file);
            void write(File::File *file);

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

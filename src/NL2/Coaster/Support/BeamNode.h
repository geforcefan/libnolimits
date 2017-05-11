#ifndef LIB_NL2PARK_BEAMNODE_H
#define LIB_NL2PARK_BEAMNODE_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class BeamNode : public Stream::Chunk {
        public:
            BeamNode() {}

            void read(File::File *file);
            void write(File::File *file);

            bool getIsFlange() const;
            void setIsFlange(bool value);

            float getPosition() const;
            void setPosition(float value);
        private:
            float position;
            bool isFlange;
        };
    }
}

#endif // LIB_NL2PARK_BEAMNODE_H

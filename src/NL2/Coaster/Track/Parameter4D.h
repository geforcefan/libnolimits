#ifndef LIB_NL2PARK_PARAMETER4d_H
#define LIB_NL2PARK_PARAMETER4d_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class Parameter4D : public Stream::Chunk {
        public:
            Parameter4D() {}
            void read(File::File *file);

            double getPosition() const;
            void setPosition(double value);

            double getAngle() const;
            void setAngle(double value);

        private:
            double position;
            double angle;
        };
    }
}

#endif // LIB_NL2PARK_PARAMETER4d_H

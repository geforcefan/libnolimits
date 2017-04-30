#ifndef LIB_NL2PARK_FRICTION_H
#define LIB_NL2PARK_FRICTION_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class CustomFriction: public Stream::Chunk {
        public:
            CustomFriction();
            void read(File::File *file);

            double getConstFrictionParameter() const;
            void setConstFrictionParameter(double value);

            double getAirResistanceParameter() const;
            void setAirResistanceParameter(double value);

        private:
            double constFrictionParameter;
            double airResistanceParameter;
        };
    }
}

#endif // LIB_NL2PARK_FRICTION_H

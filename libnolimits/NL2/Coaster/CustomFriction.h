#ifndef LIB_NL2PARK_FRICTION_H
#define LIB_NL2PARK_FRICTION_H

#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class CustomFriction: public Stream::Chunk {
        public:
            CustomFriction() {
                setConstFrictionParameter(0.03f);
                setAirResistanceParameter(0.0001f);
            }

            void debug() {
                std::cout << "CustomFriction[getConstFrictionParameter]: " << getConstFrictionParameter() << std::endl;
                std::cout << "CustomFriction[getAirResistanceParameter]: " << getAirResistanceParameter() << std::endl;
            }

            void write(File::File *file);
            void read(File::File *file);

            double getConstFrictionParameter() const;
            void setConstFrictionParameter(double value);

            double getAirResistanceParameter() const;
            void setAirResistanceParameter(double value);

            std::string getChunkName() { return "CUFR"; }
        private:
            double constFrictionParameter;
            double airResistanceParameter;
        };
    }
}

#endif // LIB_NL2PARK_FRICTION_H

#ifndef LIB_NL2PARK_BRAKEDEVICE_H
#define LIB_NL2PARK_BRAKEDEVICE_H

#include "../../../../Stream/Chunk.h"
#include "Brake.h"

namespace NoLimits {
    namespace NoLimits2 {
        class BrakeDevice {
        public:
            BrakeDevice() {
                setBrakeType(Brake::BrakeType::FrictionBrake);
                setDeceleration(Helper::GToNewton(0.8f));
            }

            void debug() {
                std::cout << "BrakeDevice[getDeceleration]: " << getDeceleration() << std::endl;
                std::cout << "BrakeDevice[getBrakeType]: " << getBrakeType() << std::endl;
            }

            double getDeceleration() const;
            void setDeceleration(double value);

            Brake::BrakeType getBrakeType() const;
            void setBrakeType(const Brake::BrakeType &value);
        private:
            double deceleration;
            Brake::BrakeType brakeType;
        };
    }
}

#endif // LIB_NL2PARK_BRAKEDEVICE_H

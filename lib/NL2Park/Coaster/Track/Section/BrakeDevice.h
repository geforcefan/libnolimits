#ifndef LIB_NL2PARK_BRAKEDEVICE_H
#define LIB_NL2PARK_BRAKEDEVICE_H

#include <Stream/Chunk.h>
#include "Brake.h"

namespace Library {
    namespace NL2Park {
        class BrakeDevice {
        public:
            BrakeDevice() {}

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

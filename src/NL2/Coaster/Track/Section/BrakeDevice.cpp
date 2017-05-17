#include "BrakeDevice.h"

#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        double BrakeDevice::getDeceleration() const {
            return deceleration;
        }

        void BrakeDevice::setDeceleration(double value) {
            deceleration = value;
        }

        Brake::BrakeType BrakeDevice::getBrakeType() const {
            return brakeType;
        }

        void BrakeDevice::setBrakeType(const Brake::BrakeType &value) {
            brakeType = value;
        }
    }
}

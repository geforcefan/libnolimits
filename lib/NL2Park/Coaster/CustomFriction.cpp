#include <NL2Park/Coaster/CustomFriction.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        CustomFriction::CustomFriction() {
        }

        void CustomFriction::read(File::File *file) {
            setConstFrictionParameter(file->readDouble());
            setAirResistanceParameter(file->readDouble());
        }

        double CustomFriction::getConstFrictionParameter() const {
            return constFrictionParameter;
        }

        void CustomFriction::setConstFrictionParameter(double value) {
            constFrictionParameter = value;
        }

        double CustomFriction::getAirResistanceParameter() const {
            return airResistanceParameter;
        }

        void CustomFriction::setAirResistanceParameter(double value) {
            airResistanceParameter = value;
        }
    }
}

#include <NL2Park/Coaster/CustomFriction.h>
#include <iostream>

namespace NoLimits {
    namespace NL2 {
        void CustomFriction::write(File::File *file) {
            file->writeDouble(getConstFrictionParameter());
            file->writeDouble(getAirResistanceParameter());

            file->writeNull(32);
        }

        void CustomFriction::read(File::File *file) {
            setConstFrictionParameter(file->readDouble());
            setAirResistanceParameter(file->readDouble());

            file->readNull(32);
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

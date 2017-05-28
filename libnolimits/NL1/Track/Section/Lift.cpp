#include "Lift.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Lift::readSection(File::File *file) {
            file->readNull(3);

            setLiftStyle((Lift::LiftStyle) file->readUnsigned8());

            setSpeed(file->readFloat());
            setAcceleration(file->readFloat());
            setDeceleration(file->readFloat());

            file->readNull(4);

            setRailingLeft(file->readBooleanLegacy());
            setRailingRight(file->readBooleanLegacy());

            setFlags2(file->readUnsignedInteger());

            file->readNull(10);
        }

        void Lift::writeSection(File::File *file) {
            file->writeNull(3);

            file->writeUnsigned8(getLiftStyle());

            file->writeFloat(getSpeed());
            file->writeFloat(getAcceleration());
            file->writeFloat(getDeceleration());

            file->writeNull(4);

            file->writeBooleanLegacy(getRailingLeft());
            file->writeBooleanLegacy(getRailingRight());

            file->writeUnsignedInteger(getFlags2());

            file->writeNull(10);
        }

        Lift::LiftStyle Lift::getLiftStyle() const {
            return liftStyle;
        }

        void Lift::setLiftStyle(Lift::LiftStyle value) {
            liftStyle = value;
        }

        float Lift::getSpeed() const {
            return speed;
        }

        void Lift::setSpeed(float value) {
            speed = value;
        }

        float Lift::getAcceleration() const {
            return acceleration;
        }

        void Lift::setAcceleration(float value) {
            acceleration = value;
        }

        float Lift::getDeceleration() const {
            return deceleration;
        }

        void Lift::setDeceleration(float value) {
            deceleration = value;
        }

        bool Lift::getRailingLeft() const {
            return railingLeft;
        }

        void Lift::setRailingLeft(bool value) {
            railingLeft = value;
        }

        bool Lift::getRailingRight() const {
            return railingRight;
        }

        void Lift::setRailingRight(bool value) {
            railingRight = value;
        }
    }
}

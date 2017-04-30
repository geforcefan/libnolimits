#include "Lift.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Lift::read(File::File *file) {
            file->readNull(3);
            setLiftType((LiftType)file->readUnsigned8());

            file->readNull(3);
            setMotorLocation((MotorLocation)file->readUnsigned8());
            setSpeed(file->readDouble());
            setAcceleration(file->readDouble());
            setDeceleration(file->readDouble());

            setHasAntiRollbackDevice(file->readBoolean());
            setShuttleModeGentle2ndPassRelease(file->readBoolean());
            setExtraBlockLength(file->readDouble());

            setDiveCoasterDropReleaseMode(file->readBoolean());
        }

        double Lift::getSpeed() const {
            return speed;
        }

        void Lift::setSpeed(double value) {
            speed = value;
        }

        double Lift::getAcceleration() const {
            return acceleration;
        }

        void Lift::setAcceleration(double value) {
            acceleration = value;
        }

        double Lift::getDeceleration() const {
            return deceleration;
        }

        void Lift::setDeceleration(double value) {
            deceleration = value;
        }

        Lift::LiftType Lift::getLiftType() const {
            return liftType;
        }

        void Lift::setLiftType(const Lift::LiftType &value) {
            liftType = value;
        }

        Lift::MotorLocation Lift::getMotorLocation() const {
            return motorLocation;
        }

        void Lift::setMotorLocation(const Lift::MotorLocation &value) {
            motorLocation = value;
        }

        bool Lift::getHasAntiRollbackDevice() const {
            return hasAntiRollbackDevice;
        }

        void Lift::setHasAntiRollbackDevice(bool value) {
            hasAntiRollbackDevice = value;
        }

        bool Lift::getShuttleModeGentle2ndPassRelease() const {
            return shuttleModeGentle2ndPassRelease;
        }

        void Lift::setShuttleModeGentle2ndPassRelease(bool value) {
            shuttleModeGentle2ndPassRelease = value;
        }

        bool Lift::getDiveCoasterDropReleaseMode() const {
            return diveCoasterDropReleaseMode;
        }

        void Lift::setDiveCoasterDropReleaseMode(bool value) {
            diveCoasterDropReleaseMode = value;
        }

        double Lift::getExtraBlockLength() const {
            return extraBlockLength;
        }

        void Lift::setExtraBlockLength(double value) {
            extraBlockLength = value;
        }
    }
}

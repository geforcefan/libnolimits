#include "Transport.h"

#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void Transport::read(File::File *file) {
            setTransportType((Transport::TransportType)file->readUnsigned8());
            setSpeed(file->readDouble());
            setAcceleration(file->readDouble());
            setDeceleration(file->readDouble());
            setSpeedingUpPasses(file->readUnsignedInteger());
            setSpeedingDown(file->readBoolean());
            setMinSpeed(file->readDouble());

            file->readNull(26);
        }

        void Transport::write(File::File *file) {
            file->writeUnsigned8(getTransportType());
            file->writeDouble(getSpeed());
            file->writeDouble(getAcceleration());
            file->writeDouble(getDeceleration());
            file->writeUnsignedInteger(getSpeedingUpPasses());
            file->writeBoolean(getSpeedingDown());
            file->writeDouble(getMinSpeed());

            file->writeNull(26);
        }

        double Transport::getSpeed() const {
            return speed;
        }

        void Transport::setSpeed(double value) {
            speed = value;
        }

        double Transport::getAcceleration() const {
            return acceleration;
        }

        void Transport::setAcceleration(double value) {
            acceleration = value;
        }

        double Transport::getDeceleration() const {
            return deceleration;
        }

        void Transport::setDeceleration(double value) {
            deceleration = value;
        }

        uint32_t Transport::getSpeedingUpPasses() const {
            return speedingUpPasses;
        }

        void Transport::setSpeedingUpPasses(const uint32_t &value) {
            speedingUpPasses = value;
        }

        bool Transport::getSpeedingDown() const {
            return speedingDown;
        }

        void Transport::setSpeedingDown(bool value) {
            speedingDown = value;
        }

        double Transport::getMinSpeed() const {
            return minSpeed;
        }

        void Transport::setMinSpeed(double value) {
            minSpeed = value;
        }

        Transport::TransportType Transport::getTransportType() const {
            return transportType;
        }

        void Transport::setTransportType(const Transport::TransportType &value) {
            transportType = value;
        }
    }
}

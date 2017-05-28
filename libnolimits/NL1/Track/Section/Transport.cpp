#include "Transport.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Transport::readSection(File::File *file) {
            setSpeed(file->readFloat());
            setAcceleration(file->readFloat());
            setDeceleration(file->readFloat());

            file->readNull(3);
            setTransportType((Transport::TransportType) file->readUnsigned8());

            setRailingLeft(file->readBooleanLegacy());
            setRailingRight(file->readBooleanLegacy());

            setSpeedUpPasses(file->readUnsigned8());
            setSpeedDown((Transport::SpeedDown) file->readUnsigned8());
            setSpeedDownSpeedLimit(file->readFloat());

            file->readNull(4);
        }

        void Transport::writeSection(File::File *file) {
            file->writeFloat(getSpeed());
            file->writeFloat(getAcceleration());
            file->writeFloat(getDeceleration());

            file->writeNull(3);
            file->writeUnsigned8(getTransportType());

            file->writeBooleanLegacy(getRailingLeft());
            file->writeBooleanLegacy(getRailingRight());

            file->writeUnsigned8(getSpeedUpPasses());
            file->writeUnsigned8(getSpeedDown());
            file->writeFloat(getSpeedDownSpeedLimit());

            file->writeNull(4);
        }

        Transport::TransportType Transport::getTransportType() const {
            return transportType;
        }

        void Transport::setTransportType(Transport::TransportType value) {
            transportType = value;
        }

        Transport::SpeedDown Transport::getSpeedDown() const {
            return speedDown;
        }

        void Transport::setSpeedDown(Transport::SpeedDown value) {
            speedDown = value;
        }

        float Transport::getSpeed() const {
            return speed;
        }

        void Transport::setSpeed(float value) {
            speed = value;
        }

        float Transport::getAcceleration() const {
            return acceleration;
        }

        void Transport::setAcceleration(float value) {
            Transport::acceleration = value;
        }

        float Transport::getDeceleration() const {
            return deceleration;
        }

        void Transport::setDeceleration(float value) {
            deceleration = value;
        }

        bool Transport::getRailingLeft() const {
            return railingLeft;
        }

        void Transport::setRailingLeft(bool value) {
            railingLeft = value;
        }

        bool Transport::getRailingRight() const {
            return railingRight;
        }

        void Transport::setRailingRight(bool value) {
            railingRight = value;
        }

        uint8_t Transport::getSpeedUpPasses() const {
            return speedUpPasses;
        }

        void Transport::setSpeedUpPasses(uint8_t value) {
            speedUpPasses = value;
        }

        float Transport::getSpeedDownSpeedLimit() const {
            return speedDownSpeedLimit;
        }

        void Transport::setSpeedDownSpeedLimit(float value) {
            speedDownSpeedLimit = value;
        }
    }
}

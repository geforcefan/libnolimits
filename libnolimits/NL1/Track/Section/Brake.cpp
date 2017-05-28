#include "Brake.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Brake::readSection(File::File *file) {
            setSpeedLimit(file->readFloat());
            setDeceleration(file->readFloat());
            setHysteresis(file->readFloat());
            file->readNull(4);

            setTriggerPosition(file->readFloat());
            setBlockSegment(file->readBooleanLegacy());
            setEnableTransport(file->readBooleanLegacy());

            getTransportDevice()->setSpeed(file->readFloat());
            getTransportDevice()->setAcceleration(file->readFloat());
            getTransportDevice()->setDeceleration(file->readFloat());

            setRailingLeft(file->readBooleanLegacy());
            setRailingRight(file->readBooleanLegacy());

            setCompleteStop(file->readBooleanLegacy());
            getTransportDevice()->setTransportStyle((Transport::TransportType) file->readUnsignedInteger());

            setStopWaitTime(file->readUnsigned8());

            getTransportDevice()->setEnableLaunch(file->readBooleanLegacy());
            getTransportDevice()->setLaunchAcceleration(file->readFloat());

            setTriggerBehaviour(file->readBooleanLegacy() ? Brake::TriggerBehaviour::CenterCar : Brake::TriggerBehaviour::FrontCar);

            file->readNull(2);
        }

        void Brake::writeSection(File::File *file) {
            file->writeFloat(getSpeedLimit());
            file->writeFloat(getDeceleration());
            file->writeFloat(getHysteresis());
            file->writeNull(4);

            file->writeFloat(getTriggerPosition());
            file->writeBooleanLegacy(getBlockSegment());
            file->writeBooleanLegacy(getEnableTransport());

            file->writeFloat(getTransportDevice()->getSpeed());
            file->writeFloat(getTransportDevice()->getAcceleration());
            file->writeFloat(getTransportDevice()->getDeceleration());

            file->writeBooleanLegacy(getRailingLeft());
            file->writeBooleanLegacy(getRailingRight());

            file->writeBooleanLegacy(getCompleteStop());
            file->writeUnsignedInteger(getTransportDevice()->getTransportStyle());

            file->writeUnsigned8(getStopWaitTime());

            file->writeBooleanLegacy(getTransportDevice()->getEnableLaunch());
            file->writeFloat(getTransportDevice()->getLaunchAcceleration());

            file->writeBooleanLegacy(getTriggerBehaviour() == Brake::TriggerBehaviour::CenterCar ? true : false);

            file->writeNull(2);
        }

        bool Brake::getEnableTransport() const {
            return enableTransport;
        }

        void Brake::setEnableTransport(bool value) {
            enableTransport = value;
        }

        TransportDevice *Brake::getTransportDevice() const {
            return transportDevice;
        }

        void Brake::setTransportDevice(TransportDevice *value) {
            transportDevice = value;
        }

        bool Brake::getBlockSegment() const {
            return blockSegment;
        }

        void Brake::setBlockSegment(bool value) {
            blockSegment = value;
        }

        bool Brake::getCompleteStop() const {
            return completeStop;
        }

        void Brake::setCompleteStop(bool value) {
            completeStop = value;
        }

        uint8_t Brake::getStopWaitTime() const {
            return stopWaitTime;
        }

        void Brake::setStopWaitTime(uint8_t value) {
            stopWaitTime = value;
        }

        float Brake::getSpeedLimit() const {
            return speedLimit;
        }

        void Brake::setSpeedLimit(float value) {
            speedLimit = value;
        }

        float Brake::getHysteresis() const {
            return hysteresis;
        }

        void Brake::setHysteresis(float value) {
            hysteresis = value;
        }

        float Brake::getDeceleration() const {
            return deceleration;
        }

        void Brake::setDeceleration(float value) {
            deceleration = value;
        }

        bool Brake::getRailingLeft() const {
            return railingLeft;
        }

        void Brake::setRailingLeft(bool value) {
            railingLeft = value;
        }

        bool Brake::getRailingRight() const {
            return railingRight;
        }

        void Brake::setRailingRight(bool value) {
            railingRight = value;
        }

        float Brake::getTriggerPosition() const {
            return triggerPosition;
        }

        void Brake::setTriggerPosition(float value) {
            triggerPosition = value;
        }

        Brake::TriggerBehaviour Brake::getTriggerBehaviour() const {
            return triggerBehaviour;
        }

        void Brake::setTriggerBehaviour(Brake::TriggerBehaviour value) {
            triggerBehaviour = value;
        }
    }
}

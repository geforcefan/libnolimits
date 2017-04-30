#include "Brake.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Brake::read(File::File *file) {
            setMode((Brake::BrakeMode)file->readUnsigned8());
            setBrakeType((Brake::BrakeType)file->readUnsigned8());
            setDeceleration(file->readDouble());
            setSpeedLimit(file->readDouble());
            setHysteresis(file->readDouble());

            file->readNull(9);

            setCompleteStop(file->readBoolean());
            setWaitTime(file->readDouble());

            file->readNull(66);
            setExtraBlockLength(file->readDouble());

            file->seek(71, SEEK_SET);
            setEnableTransport(file->readBoolean());

            getTransportDevice()->setTransportType((Transport::TransportType)file->readUnsigned8());
            getTransportDevice()->setSpeed(file->readDouble());
            getTransportDevice()->setAcceleration(file->readDouble());
            getTransportDevice()->setDeceleration(file->readDouble());
            getTransportDevice()->setLaunch(file->readBoolean());
            getTransportDevice()->setLaunchAcceleration(file->readDouble());
            getTransportDevice()->setLaunchMaxSpeed(file->readDouble());

            file->seek(30, SEEK_SET);
            setPositionOnTrain((Brake::Position)file->readUnsigned8());
            setPositionOnSection(file->readDouble());
        }

        double Brake::getExtraBlockLength() const {
            return extraBlockLength;
        }

        void Brake::setExtraBlockLength(double value) {
            extraBlockLength = value;
        }

        Brake::BrakeMode Brake::getMode() const {
            return mode;
        }

        void Brake::setMode(const Brake::BrakeMode &value) {
            mode = value;
        }

        bool Brake::getCompleteStop() const {
            return completeStop;
        }

        void Brake::setCompleteStop(bool value) {
            completeStop = value;
        }

        double Brake::getWaitTime() const {
            return waitTime;
        }

        void Brake::setWaitTime(double value) {
            waitTime = value;
        }

        Brake::BrakeType Brake::getBrakeType() const {
            return brakeType;
        }

        void Brake::setBrakeType(const Brake::BrakeType &value) {
            brakeType = value;
        }

        double Brake::getSpeedLimit() const {
            return speedLimit;
        }

        void Brake::setSpeedLimit(double value) {
            speedLimit = value;
        }

        double Brake::getHysteresis() const {
            return hysteresis;
        }

        void Brake::setHysteresis(double value) {
            hysteresis = value;
        }

        double Brake::getDeceleration() const {
            return deceleration;
        }

        void Brake::setDeceleration(double value) {
            deceleration = value;
        }

        Brake::Position Brake::getPositionOnTrain() const {
            return positionOnTrain;
        }

        void Brake::setPositionOnTrain(const Brake::Position &value) {
            positionOnTrain = value;
        }

        double Brake::getPositionOnSection() const {
            return positionOnSection;
        }

        void Brake::setPositionOnSection(double value) {
            positionOnSection = value;
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
    }
}

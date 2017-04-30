#include "Station.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Station::read(File::File *file) {
            setUseTransportDevice(file->readBoolean());
            getTransportDevice()->setTransportType((Transport::TransportType)file->readUnsigned8());
            getTransportDevice()->setSpeed(file->readDouble());
            getTransportDevice()->setAcceleration(file->readDouble());
            getTransportDevice()->setDeceleration(file->readDouble());

            getBrakeDevice()->setDeceleration(file->readDouble());
            getWaitTime()->setAvarage(file->readDouble());
            getWaitTime()->setMinimum(file->readDouble());
            getWaitTime()->setMaximum(file->readDouble());
            getWaitTime()->setDeviation(file->readDouble());

            getTransportDevice()->setLaunch(file->readBoolean());
            getTransportDevice()->setLaunchAcceleration(file->readDouble());
            getTransportDevice()->setLaunchMaxSpeed(file->readDouble());

            setUnloadingOnly(file->readBoolean());

            file->readNull(3);

            setPasses(file->readUnsigned8());
            setShuttleBackwardsStart(file->readBoolean());
            setStationNumber(file->readUnsignedInteger());

            file->readNull(3);

            uint8_t numSynchronizeDispatchWith = file->readUnsigned8();

            for(uint8_t i = 0; i < numSynchronizeDispatchWith; i++) {
                getWaitTime()->insertSynchronizeDispatchWith(file->readUnsignedInteger());
            }

            setExtraBlockLength(file->readDouble());

            getBrakeDevice()->setBrakeType((Brake::BrakeType)file->readUnsigned8());
            setGateDirection((Station::GateDirection)file->readUnsigned8());
            setDisplay((Station::Display)file->readUnsigned8());
            setEntranceStairs((Station::Stairs)file->readUnsigned8());
            setExitStairs((Station::Stairs)file->readUnsigned8());

            file->readNull(1);

            setGatesColor(file->readColor());
            setRailingsColor(file->readColor());
            setStructureColor(file->readColor());

            file->readNull(137);
        }

        double Station::getExtraBlockLength() const {
            return extraBlockLength;
        }

        void Station::setExtraBlockLength(double value) {
            extraBlockLength = value;
        }

        bool Station::getUnloadingOnly() const {
            return unloadingOnly;
        }

        void Station::setUnloadingOnly(bool value) {
            unloadingOnly = value;
        }

        Station::Display Station::getDisplay() const {
            return display;
        }

        void Station::setDisplay(const Station::Display &value) {
            display = value;
        }

        Station::GateDirection Station::getGateDirection() const {
            return gateDirection;
        }

        void Station::setGateDirection(const Station::GateDirection &value) {
            gateDirection = value;
        }

        Station::Stairs Station::getEntranceStairs() const {
            return entranceStairs;
        }

        void Station::setEntranceStairs(const Station::Stairs &value) {
            entranceStairs = value;
        }

        Station::Stairs Station::getExitStairs() const {
            return exitStairs;
        }

        void Station::setExitStairs(const Station::Stairs &value) {
            exitStairs = value;
        }

        uint8_t Station::getPasses() const {
            return passes;
        }

        void Station::setPasses(const uint8_t &value) {
            passes = value;
        }

        bool Station::getShuttleBackwardsStart() const {
            return shuttleBackwardsStart;
        }

        void Station::setShuttleBackwardsStart(bool value) {
            shuttleBackwardsStart = value;
        }

        glm::vec3 Station::getStructureColor() const {
            return structureColor;
        }

        void Station::setStructureColor(const glm::vec3 &value) {
            structureColor = value;
        }

        glm::vec3 Station::getRailingsColor() const {
            return railingsColor;
        }

        void Station::setRailingsColor(const glm::vec3 &value) {
            railingsColor = value;
        }

        glm::vec3 Station::getGatesColor() const {
            return gatesColor;
        }

        void Station::setGatesColor(const glm::vec3 &value) {
            gatesColor = value;
        }

        WaitTime *Station::getWaitTime() const {
            return waitTime;
        }

        void Station::setWaitTime(WaitTime *value) {
            waitTime = value;
        }

        BrakeDevice *Station::getBrakeDevice() const {
            return brakeDevice;
        }

        void Station::setBrakeDevice(BrakeDevice *value) {
            brakeDevice = value;
        }

        bool Station::getUseTransportDevice() const {
            return useTransportDevice;
        }

        void Station::setUseTransportDevice(bool value) {
            useTransportDevice = value;
        }

        TransportDevice *Station::getTransportDevice() const {
            return transportDevice;
        }

        void Station::setTransportDevice(TransportDevice *value) {
            transportDevice = value;
        }

        uint32_t Station::getStationNumber() const {
            return stationNumber;
        }

        void Station::setStationNumber(const uint32_t &value) {
            stationNumber = value;
        }
    }
}

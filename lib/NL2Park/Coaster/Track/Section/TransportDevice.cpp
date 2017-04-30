#include "TransportDevice.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        Transport::TransportType TransportDevice::getTransportType() const {
            return transportType;
        }

        void TransportDevice::setTransportType(const Transport::TransportType &value) {
            transportType = value;
        }

        double TransportDevice::getSpeed() const {
            return speed;
        }

        void TransportDevice::setSpeed(double value) {
            speed = value;
        }

        double TransportDevice::getAcceleration() const {
            return acceleration;
        }

        void TransportDevice::setAcceleration(double value) {
            acceleration = value;
        }

        double TransportDevice::getDeceleration() const {
            return deceleration;
        }

        void TransportDevice::setDeceleration(double value) {
            deceleration = value;
        }

        bool TransportDevice::getLaunch() const {
            return launch;
        }

        void TransportDevice::setLaunch(bool value) {
            launch = value;
        }

        double TransportDevice::getLaunchAcceleration() const {
            return launchAcceleration;
        }

        void TransportDevice::setLaunchAcceleration(double value) {
            launchAcceleration = value;
        }

        double TransportDevice::getLaunchMaxSpeed() const {
            return launchMaxSpeed;
        }

        void TransportDevice::setLaunchMaxSpeed(double value) {
            launchMaxSpeed = value;
        }
    }
}

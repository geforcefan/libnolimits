#include "TransportDevice.h"

namespace NoLimits {
    namespace NoLimits1 {

        Transport::TransportType TransportDevice::getTransportStyle() const {
            return transportStyle;
        }

        void TransportDevice::setTransportStyle(Transport::TransportType value) {
            transportStyle = value;
        }

        float TransportDevice::getSpeed() const {
            return speed;
        }

        void TransportDevice::setSpeed(float value) {
            speed = value;
        }

        float TransportDevice::getAcceleration() const {
            return acceleration;
        }

        void TransportDevice::setAcceleration(float value) {
            acceleration = value;
        }

        float TransportDevice::getDeceleration() const {
            return deceleration;
        }

        void TransportDevice::setDeceleration(float value) {
            deceleration = value;
        }

        bool TransportDevice::getHideTransportDevice() const {
            return hideTransportDevice;
        }

        void TransportDevice::setHideTransportDevice(bool value) {
            hideTransportDevice = value;
        }

        float TransportDevice::getLaunchAcceleration() const {
            return launchAcceleration;
        }

        void TransportDevice::setLaunchAcceleration(float value) {
            launchAcceleration = value;
        }

        bool TransportDevice::getEnableLaunch() const {
            return enableLaunch;
        }

        void TransportDevice::setEnableLaunch(bool value) {
            enableLaunch = value;
        }
    }
}
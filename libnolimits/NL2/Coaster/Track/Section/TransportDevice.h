#ifndef LIB_NL2PARK_TRANSPORTDEVICE_H
#define LIB_NL2PARK_TRANSPORTDEVICE_H

#include "Transport.h"
#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class TransportDevice {
        public:
            TransportDevice() {
                setTransportType(Transport::TransportType::FrictionWheels);
                setSpeed(Helper::kphToMs(8.0f));
                setAcceleration(Helper::GToNewton(0.5f));
                setAcceleration(Helper::GToNewton(0.3f));
                setLaunch(false);
                setLaunchAcceleration(Helper::GToNewton(0.8f));
                setLaunchMaxSpeed(Helper::kphToMs(100.0f));
            }

            void debug() {
                std::cout << "TransportDevice[getTransportType]: " << getTransportType() << std::endl;
                std::cout << "TransportDevice[getSpeed]: " << getSpeed() << std::endl;
                std::cout << "TransportDevice[getAcceleration]: " << getAcceleration() << std::endl;
                std::cout << "TransportDevice[getDeceleration]: " << getDeceleration() << std::endl;
                std::cout << "TransportDevice[getLaunch]: " << getLaunch() << std::endl;
                std::cout << "TransportDevice[getLaunchAcceleration]: " << getLaunchAcceleration() << std::endl;
                std::cout << "TransportDevice[getLaunchMaxSpeed]: " << getLaunchMaxSpeed() << std::endl;
            }

            Transport::TransportType getTransportType() const;
            void setTransportType(const Transport::TransportType &value);

            double getSpeed() const;
            void setSpeed(double value);

            double getAcceleration() const;
            void setAcceleration(double value);

            double getDeceleration() const;
            void setDeceleration(double value);

            bool getLaunch() const;
            void setLaunch(bool value);

            double getLaunchAcceleration() const;
            void setLaunchAcceleration(double value);

            double getLaunchMaxSpeed() const;
            void setLaunchMaxSpeed(double value);
        private:
            Transport::TransportType transportType;

            double speed;

            double acceleration;
            double deceleration;

            bool launch;
            double launchAcceleration;
            double launchMaxSpeed;
        };
    }
}

#endif // LIB_NL2PARK_TRANSPORTDEVICE_H

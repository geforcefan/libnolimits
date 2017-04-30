#ifndef LIB_NL2PARK_TRANSPORTDEVICE_H
#define LIB_NL2PARK_TRANSPORTDEVICE_H

#include "Transport.h"
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class TransportDevice {
        public:
            TransportDevice() {}

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

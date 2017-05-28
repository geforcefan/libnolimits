#ifndef LIB_NOLIMITS_NL1_TRANSPORTDEVICE_H
#define LIB_NOLIMITS_NL1_TRANSPORTDEVICE_H

#include "Transport.h"

namespace NoLimits {
    namespace NoLimits1 {
        class TransportDevice {
        public:
            Transport::TransportType getTransportStyle() const;
            void setTransportStyle(Transport::TransportType value);

            float getSpeed() const;
            void setSpeed(float value);

            float getAcceleration() const;
            void setAcceleration(float value);

            float getDeceleration() const;
            void setDeceleration(float value);

            bool getHideTransportDevice() const;
            void setHideTransportDevice(bool value);

            bool getEnableLaunch() const;
            void setEnableLaunch(bool value);

            float getLaunchAcceleration() const;
            void setLaunchAcceleration(float value);

        private:
            Transport::TransportType transportStyle;

            float speed;
            float acceleration;
            float deceleration;

            bool hideTransportDevice;

            bool enableLaunch;
            float launchAcceleration;
        };
    }
}


#endif //LIB_NOLIMITS_NL1_TRANSPORTDEVICE_H

#ifndef LIB_NOLIMITS_NL1_TRANSPORT_H
#define LIB_NOLIMITS_NL1_TRANSPORT_H

#include "Section.h"

namespace NoLimits {
    namespace NoLimits1 {
        class Transport : public Section {
        public:
            enum TransportType {
                FrictionWheels,
                LIM
            };

            enum SpeedDown {
                Off,
                On
            };

            Transport() {
                setSectionType(Section::SectionType::Transport);
            }

            TransportType getTransportType() const;
            void setTransportType(TransportType value);

            SpeedDown getSpeedDown() const;
            void setSpeedDown(SpeedDown value);

            float getSpeed() const;
            void setSpeed(float value);

            float getAcceleration() const;
            void setAcceleration(float value);

            float getDeceleration() const;
            void setDeceleration(float value);

            bool getRailingLeft() const;
            void setRailingLeft(bool value);

            bool getRailingRight() const;
            void setRailingRight(bool value);

            uint8_t getSpeedUpPasses() const;
            void setSpeedUpPasses(uint8_t value);

            float getSpeedDownSpeedLimit() const;
            void setSpeedDownSpeedLimit(float value);

            /*! \cond INTERNAL */
            void readSection(File::File *file);
            void writeSection(File::File *file);
            /*! \endcond */
        private:
            TransportType transportType;
            SpeedDown speedDown;

            float speed;
            float acceleration;
            float deceleration;

            bool railingLeft;
            bool railingRight;

            uint8_t speedUpPasses;
            float speedDownSpeedLimit;
        };
    }
}


#endif //LIB_NOLIMITS_NL1_TRANSPORT_H

#ifndef LIB_NOLIMITS_NL1_BRAKE_H
#define LIB_NOLIMITS_NL1_BRAKE_H

#include "Section.h"
#include "TransportDevice.h"

namespace NoLimits {
    namespace NoLimits1 {
        class Brake : public Section {
        public:
            enum TriggerBehaviour {
                CenterCar,
                FrontCar
            };

            Brake() {
                setSectionType(Section::SectionType::Brake);
                setTransportDevice(new TransportDevice());
            }

            /*! \cond INTERNAL */
            void readSection(File::File *file);
            void writeSection(File::File *file);
            /*! \endcond */

            bool getEnableTransport() const;
            void setEnableTransport(bool value);

            TransportDevice *getTransportDevice() const;
            void setTransportDevice(TransportDevice *value);

            bool getBlockSegment() const;
            void setBlockSegment(bool value);

            bool getCompleteStop() const;
            void setCompleteStop(bool value);

            uint8_t getStopWaitTime() const;
            void setStopWaitTime(uint8_t value);

            float getSpeedLimit() const;
            void setSpeedLimit(float value);

            float getHysteresis() const;
            void setHysteresis(float value);

            float getDeceleration() const;
            void setDeceleration(float value);

            bool getRailingLeft() const;
            void setRailingLeft(bool value);

            bool getRailingRight() const;
            void setRailingRight(bool value);

            float getTriggerPosition() const;
            void setTriggerPosition(float value);

            TriggerBehaviour getTriggerBehaviour() const;
            void setTriggerBehaviour(TriggerBehaviour value);

        private:
            bool enableTransport;
            TransportDevice *transportDevice;

            bool blockSegment;
            bool completeStop;

            uint8_t stopWaitTime;

            float speedLimit;
            float hysteresis;
            float deceleration;

            bool railingLeft;
            bool railingRight;

            float triggerPosition;
            TriggerBehaviour triggerBehaviour;
        };
    }
}


#endif //LIB_NOLIMITS_NL1_BRAKE_H

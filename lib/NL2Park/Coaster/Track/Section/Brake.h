#ifndef LIB_NL2PARK_BRKAE_H
#define LIB_NL2PARK_BRKAE_H

#include "Section.h"
#include "TransportDevice.h"
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Brake : public Section {
        public:
            enum BrakeType {
                FrictionBrake,
                MagneticBrake,
                HideBrakeDevice
            };

            enum BrakeMode {
                TrimBrake,
                BlockBrake
            };

            enum Position {
                FirstCar,
                MiddleCar
            };

            Brake() : Section(Section::SectionType::Brake) {
                transportDevice = new TransportDevice();
            }
            void read(File::File *file);

            double getExtraBlockLength() const;
            void setExtraBlockLength(double value);

            BrakeMode getMode() const;
            void setMode(const BrakeMode &value);

            bool getCompleteStop() const;
            void setCompleteStop(bool value);

            double getWaitTime() const;
            void setWaitTime(double value);

            BrakeType getBrakeType() const;
            void setBrakeType(const BrakeType &value);

            double getSpeedLimit() const;
            void setSpeedLimit(double value);

            double getHysteresis() const;
            void setHysteresis(double value);

            double getDeceleration() const;
            void setDeceleration(double value);

            Position getPositionOnTrain() const;
            void setPositionOnTrain(const Position &value);

            double getPositionOnSection() const;
            void setPositionOnSection(double value);

            bool getEnableTransport() const;
            void setEnableTransport(bool value);

            TransportDevice *getTransportDevice() const;
            void setTransportDevice(TransportDevice *value);

        private:
            double extraBlockLength;

            BrakeMode mode;

            bool completeStop;
            double waitTime;

            BrakeType brakeType;

            double speedLimit;
            double hysteresis;
            double deceleration;

            Position positionOnTrain;
            double positionOnSection;

            bool enableTransport;
            TransportDevice *transportDevice;
        };
    }
}

#endif // LIB_NL2PARK_BRKAE_H

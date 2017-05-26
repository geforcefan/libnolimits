#ifndef LIB_NL2PARK_BRKAE_H
#define LIB_NL2PARK_BRKAE_H

#include "Section.h"
#include "TransportDevice.h"
#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
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

                setExtraBlockLength(0.0f);
                setMode(BrakeMode::BlockBrake);
                setCompleteStop(false);
                setWaitTime(0.0f);
                setBrakeType(BrakeType::FrictionBrake);
                setSpeedLimit(Helper::kphToMs(36.0f));
                setHysteresis(Helper::kphToMs(5.0f));
                setDeceleration(Helper::GToNewton(0.8f));
                setPositionOnTrain(Position::FirstCar);
                setPositionOnSection(0.0f);
                setEnableTransport(false);
            }

            void debug() {
                Section::debug();

                std::cout << "Brake[getExtraBlockLength]: " << getExtraBlockLength() << std::endl;
                std::cout << "Brake[getMode]: " << getMode() << std::endl;
                std::cout << "Brake[getCompleteStop]: " << getCompleteStop() << std::endl;
                std::cout << "Brake[getWaitTime]: " << getWaitTime() << std::endl;
                std::cout << "Brake[getBrakeType]: " << getBrakeType() << std::endl;
                std::cout << "Brake[getSpeedLimit]: " << getSpeedLimit() << std::endl;
                std::cout << "Brake[getHysteresis]: " << getHysteresis() << std::endl;
                std::cout << "Brake[getDeceleration]: " << getDeceleration() << std::endl;
                std::cout << "Brake[getPositionOnTrain]: " << getPositionOnTrain() << std::endl;
                std::cout << "Brake[getPositionOnSection]: " << getPositionOnSection() << std::endl;
                std::cout << "Brake[getEnableTransport]: " << getEnableTransport() << std::endl;

                getTransportDevice()->debug();
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

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

            /*! \cond INTERNAL */
            std::string getChunkName() { return "BRKE"; }
            /*! \endcond */
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

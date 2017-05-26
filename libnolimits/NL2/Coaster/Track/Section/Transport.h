#ifndef LIB_NL2PARK_TRANSPORT_H
#define LIB_NL2PARK_TRANSPORT_H

#include "Section.h"
#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Transport : public Section {
        public:
            enum TransportType {
                FrictionWheels = 0,
                LinearMotor = 1,
                HideDevice = 2
            };

            Transport() : Section(Section::SectionType::Transport) {
                setSpeed(Helper::kphToMs(8.0f));
                setAcceleration(Helper::GToNewton(0.5f));
                setDeceleration(Helper::GToNewton(0.3f));
                setSpeedingUpPasses(0);
                setMinSpeed(Helper::kphToMs(0.0f));
                setTransportType(TransportType::FrictionWheels);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                Section::debug();

                std::cout << "Transport[getSpeed]: " << getSpeed() << std::endl;
                std::cout << "Transport[getAcceleration]: " << getAcceleration() << std::endl;
                std::cout << "Transport[getDeceleration]: " << getDeceleration() << std::endl;
                std::cout << "Transport[getSpeedingUpPasses]: " << getSpeedingUpPasses() << std::endl;
                std::cout << "Transport[getSpeedingDown]: " << getSpeedingDown() << std::endl;
                std::cout << "Transport[getMinSpeed]: " << getMinSpeed() << std::endl;
                std::cout << "Transport[getTransportType]: " << getTransportType() << std::endl;
            }

            double getSpeed() const;
            void setSpeed(double value);

            double getAcceleration() const;
            void setAcceleration(double value);

            double getDeceleration() const;
            void setDeceleration(double value);

            uint32_t getSpeedingUpPasses() const;
            void setSpeedingUpPasses(const uint32_t &value);

            bool getSpeedingDown() const;
            void setSpeedingDown(bool value);

            double getMinSpeed() const;
            void setMinSpeed(double value);

            TransportType getTransportType() const;
            void setTransportType(const TransportType &value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "TRNS"; }
            /*! \endcond */
        private:
            double speed;

            double acceleration;
            double deceleration;

            uint32_t speedingUpPasses;
            bool speedingDown;

            double minSpeed;
            TransportType transportType;
        };
    }
}

#endif // LIB_NL2PARK_TRANSPORT_H

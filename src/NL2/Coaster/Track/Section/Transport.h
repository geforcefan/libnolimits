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

            Transport() : Section(Section::SectionType::Transport) {}
            void read(File::File *file);
            void write(File::File *file);

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

            std::string getChunkName() { return "TRNS"; }
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

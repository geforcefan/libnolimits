#ifndef LIB_NL2PARK_STOARGE_H
#define LIB_NL2PARK_STOARGE_H

#include "Section.h"
#include "Transport.h"
#include "TransportDevice.h"
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Storage : public Section {
        public:
            enum Building {
                None,
                Simple
            };

            Storage() : Section(Section::SectionType::Storage) {
                transportDevice = new TransportDevice();
            }
            void read(File::File *file);

            bool getEnableTransportDevice() const;
            void setEnableTransportDevice(bool value);

            TransportDevice *getTransportDevice() const;
            void setTransportDevice(TransportDevice *value);

            Transport::TransportType getTransportType() const;
            void setTransportType(const Transport::TransportType &value);

            Building getBuilding() const;
            void setBuilding(const Building &value);

            glm::vec3 getSideColor() const;
            void setSideColor(const glm::vec3 &value);

            glm::vec3 getRoofColor() const;
            void setRoofColor(const glm::vec3 &value);

            glm::vec3 getFrameColor() const;
            void setFrameColor(const glm::vec3 &value);

        private:
            bool enableTransportDevice;

            TransportDevice *transportDevice;
            Transport::TransportType transportType;

            Building building;

            glm::vec3 sideColor;
            glm::vec3 roofColor;
            glm::vec3 frameColor;
        };
    }
}

#endif // LIB_NL2PARK_LIFT_H

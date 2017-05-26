#ifndef LIB_NL2PARK_STOARGE_H
#define LIB_NL2PARK_STOARGE_H

#include "Section.h"
#include "Transport.h"
#include "TransportDevice.h"
#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Storage : public Section {
        public:
            enum Building {
                None,
                Simple
            };

            Storage() : Section(Section::SectionType::Storage) {
                transportDevice = new TransportDevice();

                setEnableTransportDevice(true);
                setTransportType(Transport::TransportType::FrictionWheels);
                setBuilding(Building::None);

                setSideColor(glm::vec3(128.0f, 0.0f, 64.0f));
                setRoofColor(glm::vec3(160.0f, 160.0f, 160.0f));
                setFrameColor(glm::vec3(127.0f, 127.0f, 127.0f));
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                Section::debug();

                std::cout << "Storage[getEnableTransportDevice]: " << getEnableTransportDevice() << std::endl;
                std::cout << "Storage[getTransportType]: " << getTransportType() << std::endl;
                std::cout << "Storage[getBuilding]: " << getBuilding() << std::endl;
                std::cout << "Storage[getSideColor]: " << Helper::debug(getSideColor()) << std::endl;
                std::cout << "Storage[getRoofColor]: " << Helper::debug(getRoofColor()) << std::endl;
                std::cout << "Storage[getFrameColor]: " << Helper::debug(getFrameColor()) << std::endl;

                getTransportDevice()->debug();
            }

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

            /*! \cond INTERNAL */
            std::string getChunkName() { return "STOR"; }
            /*! \endcond */
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

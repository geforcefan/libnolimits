#include "Storage.h"

#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void Storage::read(File::File *file) {
            setEnableTransportDevice(file->readBoolean());
            setTransportType((Transport::TransportType)file->readUnsigned8());
            setBuilding((Storage::Building)file->readUnsigned8());
            setRoofColor(file->readColor());
            setSideColor(file->readColor());
            setFrameColor(file->readColor());

            file->readNull(20);
        }

        void Storage::write(File::File *file) {
            file->writeBoolean(getEnableTransportDevice());
            file->writeUnsigned8(getTransportType());
            file->writeUnsigned8(getBuilding());
            file->writeColor(getRoofColor());
            file->writeColor(getSideColor());
            file->writeColor(getFrameColor());

            file->writeNull(20);
        }

        bool Storage::getEnableTransportDevice() const {
            return enableTransportDevice;
        }

        void Storage::setEnableTransportDevice(bool value) {
            enableTransportDevice = value;
        }

        TransportDevice *Storage::getTransportDevice() const {
            return transportDevice;
        }

        void Storage::setTransportDevice(TransportDevice *value) {
            transportDevice = value;
        }

        Transport::TransportType Storage::getTransportType() const {
            return transportType;
        }

        void Storage::setTransportType(const Transport::TransportType &value) {
            transportType = value;
        }

        Storage::Building Storage::getBuilding() const {
            return building;
        }

        void Storage::setBuilding(const Storage::Building &value) {
            building = value;
        }

        glm::vec3 Storage::getSideColor() const {
            return sideColor;
        }

        void Storage::setSideColor(const glm::vec3 &value) {
            sideColor = value;
        }

        glm::vec3 Storage::getRoofColor() const {
            return roofColor;
        }

        void Storage::setRoofColor(const glm::vec3 &value) {
            roofColor = value;
        }

        glm::vec3 Storage::getFrameColor() const {
            return frameColor;
        }

        void Storage::setFrameColor(const glm::vec3 &value) {
            frameColor = value;
        }
    }
}

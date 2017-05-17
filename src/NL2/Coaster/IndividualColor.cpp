#include "IndividualColor.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void IndividualColor::write(File::File *file) {
            file->writeBoolean(getHasIndividualColor());

            file->writeColor(getCarColor());
            file->writeColor(getSeatColor());
            file->writeColor(getHarnessColor());
            file->writeColor(getBogieColor());
            file->writeColor(getChassisColor());

            file->writeNull(16);

            file->writeUnsignedInteger(carTexture.size());
            for(uint32_t i = 0; i < carTexture.size(); i++) {
                file->writeUnsignedInteger(i);
                file->writeString(carTexture[i]);
                file->writeNull(8);
            }
        }

        void IndividualColor::read(File::File *file) {
            setHasIndividualColor(file->readBoolean());

            setCarColor(file->readColor());
            setSeatColor(file->readColor());
            setHarnessColor(file->readColor());
            setBogieColor(file->readColor());
            setChassisColor(file->readColor());

            file->readNull(16);

            uint32_t numberOfTextures = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfTextures; i++) {
                file->readNull(4);
                insertCarTexture(file->readString());
                file->readNull(8);
            }
        }

        bool IndividualColor::getHasIndividualColor() const {
            return hasIndividualColor;
        }

        void IndividualColor::setHasIndividualColor(bool value) {
            hasIndividualColor = value;
        }

        glm::vec3 IndividualColor::getCarColor() const {
            return carColor;
        }

        void IndividualColor::setCarColor(const glm::vec3 &value) {
            carColor = value;
        }

        glm::vec3 IndividualColor::getSeatColor() const {
            return seatColor;
        }

        void IndividualColor::setSeatColor(const glm::vec3 &value) {
            seatColor = value;
        }

        glm::vec3 IndividualColor::getHarnessColor() const {
            return harnessColor;
        }

        void IndividualColor::setHarnessColor(const glm::vec3 &value) {
            harnessColor = value;
        }

        glm::vec3 IndividualColor::getBogieColor() const {
            return bogieColor;
        }

        void IndividualColor::setBogieColor(const glm::vec3 &value) {
            bogieColor = value;
        }

        glm::vec3 IndividualColor::getChassisColor() const {
            return chassisColor;
        }

        void IndividualColor::setChassisColor(const glm::vec3 &value) {
            chassisColor = value;
        }

        std::vector<std::string> IndividualColor::getCarTexture() const {
            return carTexture;
        }

        void IndividualColor::insertCarTexture(std::string value) {
            carTexture.push_back(value);
        }
    }
}

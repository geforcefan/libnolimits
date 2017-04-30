#include <NL2Park/Coaster/IndividualColor.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void IndividualColor::read(File::File *file) {
            setHasIndividualColor(file->readBoolean());

            setCarColor(file->readColor());
            setSeatColor(file->readColor());
            setHarnessColor(file->readColor());
            setBogieColor(file->readColor());
            setChassisColor(file->readColor());

            file->readNull(24);
            setCarTexture1(file->readString());
            file->readNull(12);
            setCarTexture2(file->readString());
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

        std::string IndividualColor::getCarTexture1() const {
            return carTexture1;
        }

        void IndividualColor::setCarTexture1(const std::string &value) {
            carTexture1 = value;
        }

        std::string IndividualColor::getCarTexture2() const {
            return carTexture2;
        }

        void IndividualColor::setCarTexture2(const std::string &value) {
            carTexture2 = value;
        }
    }
}

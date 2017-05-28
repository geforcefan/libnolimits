#include "IndividualColor.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits1 {
        void IndividualColor::read(File::File *file) {
            setHasIndividualColor(file->readBooleanLegacy());
            file->writeNull(7);
            file->writeStringLegacy(getTexture());
            file->writeColorLegacy(getSeatColor());
            file->writeColorLegacy(getRestraintColor());
            file->writeColorLegacy(getTrainColor());
            file->writeColorLegacy(getGearColor());
        }

        void IndividualColor::write(File::File *file) {
            file->writeBooleanLegacy(getHasIndividualColor());
            file->readNull(7);
            setTexture(file->readStringLegacy());
            setSeatColor(file->readColorLegacy());
            setRestraintColor(file->readColorLegacy());
            setTrainColor(file->readColorLegacy());
            setGearColor(file->readColorLegacy());
        }

        bool IndividualColor::getHasIndividualColor() const {
            return hasIndividualColor;
        }

        void IndividualColor::setHasIndividualColor(bool value) {
            hasIndividualColor = value;
        }

        const glm::vec3 &IndividualColor::getSeatColor() const {
            return seatColor;
        }

        void IndividualColor::setSeatColor(const glm::vec3 &value) {
            seatColor = value;
        }

        const glm::vec3 &IndividualColor::getRestraintColor() const {
            return restraintColor;
        }

        void IndividualColor::setRestraintColor(const glm::vec3 &value) {
            restraintColor = value;
        }

        const glm::vec3 &IndividualColor::getTrainColor() const {
            return trainColor;
        }

        void IndividualColor::setTrainColor(const glm::vec3 &value) {
            trainColor = value;
        }

        const glm::vec3 &IndividualColor::getGearColor() const {
            return gearColor;
        }

        void IndividualColor::setGearColor(const glm::vec3 &value) {
            gearColor = value;
        }

        const std::string &IndividualColor::getTexture() const {
            return texture;
        }

        void IndividualColor::setTexture(const std::string &value) {
            texture = value;
        }
    }
}

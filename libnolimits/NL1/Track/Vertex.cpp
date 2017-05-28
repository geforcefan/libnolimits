#include "Vertex.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Vertex::read(File::File *file) {
            setPosition(file->readFloatVec3());
            setControlPoint1(file->readFloatVec3());
            setControlPoint2(file->readFloatVec3());
            setRoll(file->readFloat());
            setContinuousRoll(file->readBooleanLegacy());
            setEqualDistance(file->readBooleanLegacy());
            setRelativeRoll(file->readBooleanLegacy());
            file->readNull(17);
        }

        void Vertex::write(File::File *file) {
            file->writeFloatVec3(getPosition());
            file->writeFloatVec3(getControlPoint1());
            file->writeFloatVec3(getControlPoint2());
            file->writeFloat(getRoll());
            file->writeBooleanLegacy(getContinuousRoll());
            file->writeBooleanLegacy(getEqualDistance());
            file->writeBooleanLegacy(getRelativeRoll());
            file->writeNull(17);
        }

        const glm::vec3 &Vertex::getPosition() const {
            return position;
        }

        void Vertex::setPosition(const glm::vec3 &value) {
            position = value;
        }

        float Vertex::getRoll() const {
            return roll;
        }

        void Vertex::setRoll(float value) {
            roll = value;
        }

        bool Vertex::getContinuousRoll() const {
            return continuousRoll;
        }

        void Vertex::setContinuousRoll(bool value) {
            continuousRoll = value;
        }

        bool Vertex::getRelativeRoll() const {
            return relativeRoll;
        }

        void Vertex::setRelativeRoll(bool value) {
            relativeRoll = value;
        }

        bool Vertex::getEqualDistance() const {
            return equalDistance;
        }

        void Vertex::setEqualDistance(bool value) {
            equalDistance = value;
        }

        const glm::vec3 &Vertex::getControlPoint1() const {
            return controlPoint1;
        }

        void Vertex::setControlPoint1(const glm::vec3 &value) {
            controlPoint1 = value;
        }

        const glm::vec3 &Vertex::getControlPoint2() const {
            return controlPoint2;
        }

        void Vertex::setControlPoint2(const glm::vec3 &value) {
            controlPoint2 = value;
        }
    }
}

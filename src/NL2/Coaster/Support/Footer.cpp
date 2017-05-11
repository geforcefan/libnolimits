#include "Footer.h"

namespace NoLimits {
    namespace NL2 {
        void Footer::read(File::File *file) {
            setPosition(file->readDoubleVec3());
            setRotationAngle(file->readFloat());
            setAboveGround(file->readFloat());

            file->readNull(3);

            setConnectionStyle((Footer::ConnectionStyle)file->readUnsigned8());

            file->readNull(3);

            setColorMode((Footer::ColorMode)file->readUnsigned8());
            setCustomColor(file->readColor());

            file->readNull(3);

            setBaseStyle((Footer::BaseStyle)file->readUnsigned8());

            file->readNull(9);
        }

        void Footer::write(File::File *file) {
            file->writeDoubleVec3(getPosition());
            file->writeFloat(getRotationAngle());
            file->writeFloat(getAboveGround());

            file->writeNull(3);

            file->writeUnsigned8(getConnectionStyle());

            file->writeNull(3);

            file->writeUnsigned8(getColorMode());
            file->writeColor(getCustomColor());

            file->writeNull(3);

            file->writeUnsigned8(getBaseStyle());

            file->writeNull(9);
        }

        glm::vec3 Footer::getPosition() const {
            return position;
        }

        void Footer::setPosition(const glm::vec3 &value) {
            position = value;
        }

        float Footer::getRotationAngle() const {
            return rotationAngle;
        }

        void Footer::setRotationAngle(float value) {
            rotationAngle = value;
        }

        float Footer::getAboveGround() const {
            return aboveGround;
        }

        void Footer::setAboveGround(float value) {
            aboveGround = value;
        }

        Footer::BaseStyle Footer::getBaseStyle() const {
            return baseStyle;
        }

        void Footer::setBaseStyle(const Footer::BaseStyle &value) {
            baseStyle = value;
        }

        Footer::ConnectionStyle Footer::getConnectionStyle() const {
            return connectionStyle;
        }

        void Footer::setConnectionStyle(const Footer::ConnectionStyle &value) {
            connectionStyle = value;
        }

        Footer::ColorMode Footer::getColorMode() const {
            return colorMode;
        }

        void Footer::setColorMode(const Footer::ColorMode &value) {
            colorMode = value;
        }

        glm::vec3 Footer::getCustomColor() const {
            return customColor;
        }

        void Footer::setCustomColor(const glm::vec3 &value) {
            customColor = value;
        }
    }
}

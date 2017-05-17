#include "Info.h"
#include <iostream>
#include <string>
#include <sstream>

namespace NoLimits {
    namespace NoLimits2 {
        void Info::read(File::File *file) {
            getVersion()->read(file);

            file->readNull(27);

            getWeather()->read(file);

            file->readNull(6);

            setAuthor(file->readString());
            setDescription(file->readString());
            setPreview(file->readString());
            setEnvironment(file->readString());

            file->readNull(10);

            getSky()->read(file);

            setInitialPositionAndRotationEnabled(file->readBoolean());
            setInitialPosition(file->readFloatVec3());
            setInitialRotation(file->readFloatVec2());

            setInitialView((Info::RideView)file->readUnsigned8());

            file->readNull(21);
        }

        void Info::write(File::File *file) {
            getVersion()->write(file);

            file->writeNull(27);

            getWeather()->write(file);

            file->writeNull(6);

            file->writeString(getAuthor());
            file->writeString(getDescription());
            file->writeString(getPreview());
            file->writeString(getEnvironment());

            file->writeNull(10);

            getSky()->write(file);

            file->writeBoolean(getInitialPositionAndRotationEnabled());
            file->writeFloatVec3(getInitialPosition());
            file->writeFloatVec2(getInitialRotation());

            file->writeUnsigned8(getInitialView());

            file->writeNull(21);
        }

        Sky *Info::getSky() const {
            return sky;
        }

        Info::RideView Info::getInitialView() {
            return initialView;
        }

        void Info::setInitialView(Info::RideView value) {
            initialView = value;
        }

        Version *Info::getVersion() const {
            return version;
        }

        void Info::setVersion(Version *value) {
            version = value;
        }

        bool Info::getInitialPositionAndRotationEnabled() const {
            return initialPositionAndRotationEnabled;
        }

        void Info::setInitialPositionAndRotationEnabled(bool value) {
            initialPositionAndRotationEnabled = value;
        }

        glm::vec2 Info::getInitialRotation() const {
            return initialRotation;
        }

        void Info::setInitialRotation(const glm::vec2 &value) {
            initialRotation = value;
        }

        glm::vec3 Info::getInitialPosition() const {
            return initialPosition;
        }

        void Info::setInitialPosition(const glm::vec3 &value) {
            initialPosition = value;
        }

        std::string Info::getEnvironment() const {
            return environment;
        }

        void Info::setEnvironment(const std::string &value) {
            environment = value;
        }

        std::string Info::getPreview() const {
            return preview;
        }

        void Info::setPreview(const std::string &value) {
            preview = value;
        }

        std::string Info::getDescription() const {
            return description;
        }

        void Info::setDescription(const std::string &value) {
            description = value;
        }

        std::string Info::getAuthor() const {
            return author;
        }

        void Info::setAuthor(const std::string &value) {
            author = value;
        }

        Weather *Info::getWeather() const {
            return weather;
        }
    }
}

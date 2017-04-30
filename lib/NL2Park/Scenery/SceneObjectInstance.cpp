#include "SceneObjectInstance.h"
#include <iostream>

namespace Library {
    namespace NL2Park {
        void SceneObjectInstance::read(File::File *file) {
            setSceneObjectIndex(file->readUnsignedInteger());

            setPosition(file->readFloatVec3());
            setRotation(file->readFloatVec3());
            setScale(file->readFloatVec3());

            setName(file->readString());
            setDimObject(file->readBoolean());
            setLock(file->readBoolean());

            file->readNull(29);

            setLockOnTerrain(file->readBoolean());
        }

        void SceneObjectInstance::write(File::File *file) {
            file->writeUnsignedInteger(getSceneObjectIndex());

            file->writeFloatVec3(getPosition());
            file->writeFloatVec3(getRotation());
            file->writeFloatVec3(getScale());

            file->writeString(getName());
            file->writeBoolean(getDimObject());
            file->writeBoolean(getLock());

            file->writeNull(29);

            file->writeBoolean(getLockOnTerrain());
        }

        std::string SceneObjectInstance::getName() const {
            return name;
        }

        void SceneObjectInstance::setName(const std::string &value) {
            name = value;
        }

        uint32_t SceneObjectInstance::getSceneObjectIndex() const
        {
            return sceneObjectIndex;
        }

        void SceneObjectInstance::setSceneObjectIndex(const uint32_t &value)
        {
            sceneObjectIndex = value;
        }

        glm::vec3 SceneObjectInstance::getPosition() const
        {
            return position;
        }

        void SceneObjectInstance::setPosition(const glm::vec3 &value)
        {
            position = value;
        }

        glm::vec3 SceneObjectInstance::getScale() const
        {
            return scale;
        }

        void SceneObjectInstance::setScale(const glm::vec3 &value)
        {
            scale = value;
        }

        glm::vec3 SceneObjectInstance::getRotation() const
        {
            return rotation;
        }

        void SceneObjectInstance::setRotation(const glm::vec3 &value)
        {
            rotation = value;
        }

        bool SceneObjectInstance::getLock() const
        {
            return lock;
        }

        void SceneObjectInstance::setLock(bool value)
        {
            lock = value;
        }

        bool SceneObjectInstance::getLockOnTerrain() const
        {
            return lockOnTerrain;
        }

        void SceneObjectInstance::setLockOnTerrain(bool value)
        {
            lockOnTerrain = value;
        }

        bool SceneObjectInstance::getDimObject() const
        {
            return dimObject;
        }

        void SceneObjectInstance::setDimObject(bool value)
        {
            dimObject = value;
        }
    }
}

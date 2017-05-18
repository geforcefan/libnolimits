#ifndef LIB_NL2PARK_SCENEOBJECTINSTANCE_H
#define LIB_NL2PARK_SCENEOBJECTINSTANCE_H

#include "../../Stream/Chunk.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
        class SceneObjectInstance: public Stream::Chunk {
        public:
            SceneObjectInstance() {
                setName("");
                setSceneObjectIndex(0);
                setPosition(glm::vec3(0.0f));
                setScale(glm::vec3(0.0f));
                setRotation(glm::vec3(0.0f));
                setLock(false);
                setLockOnTerrain(false);
                setDimObject(false);
            }

            void debug() {
                std::cout << "SceneObjectInstance[getName]: " << getName() << std::endl;
                std::cout << "SceneObjectInstance[getSceneObjectIndex]: " << getSceneObjectIndex() << std::endl;
                std::cout << "SceneObjectInstance[getPosition]: " << Helper::debug(getPosition()) << std::endl;
                std::cout << "SceneObjectInstance[getScale]: " << Helper::debug(getScale()) << std::endl;
                std::cout << "SceneObjectInstance[getRotation]: " << Helper::debug(getRotation()) << std::endl;
                std::cout << "SceneObjectInstance[getLock]: " << getLock() << std::endl;
                std::cout << "SceneObjectInstance[getLockOnTerrain]: " << getLockOnTerrain() << std::endl;
                std::cout << "SceneObjectInstance[getDimObject]: " << getDimObject() << std::endl;
            }

            void read(File::File *file);
            void write(File::File *file);

            std::string getName() const;
            void setName(const std::string &value);

            uint32_t getSceneObjectIndex() const;
            void setSceneObjectIndex(const uint32_t &value);

            glm::vec3 getPosition() const;
            void setPosition(const glm::vec3 &value);

            glm::vec3 getScale() const;
            void setScale(const glm::vec3 &value);

            glm::vec3 getRotation() const;
            void setRotation(const glm::vec3 &value);

            bool getLock() const;
            void setLock(bool value);

            bool getLockOnTerrain() const;
            void setLockOnTerrain(bool value);

            bool getDimObject() const;
            void setDimObject(bool value);

        private:
            std::string name;
            uint32_t sceneObjectIndex;

            glm::vec3 position;
            glm::vec3 scale;
            glm::vec3 rotation;

            bool lock;
            bool lockOnTerrain;
            bool dimObject;
        };
    }
}

#endif // LIB_NL2PARK_SCENEOBJECTINSTANCE_H

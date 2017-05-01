#include "Scenery.h"
#include <iostream>

namespace NoLimits {
    namespace NL2 {
        void Scenery::read(File::File *file) {
            sceneObject.clear();
            sceneObjectInstance.clear();

            file->readNull(64);

            uint32_t numberOfSceneObjects = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfSceneObjects; i++) {
                insertSceneObject(file->readString());
                file->readNull(128);
            }

            file->readNull(64);

            uint32_t numberOfSceneObjectInstances = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfSceneObjectInstances; i++) {
                SceneObjectInstance *soi = new SceneObjectInstance();
                insertSceneObjectInstance(soi);

                soi->read(file);
            }

            file->readNull(64);
        }

        void Scenery::write(File::File *file) {
            file->writeNull(64);

            file->writeUnsignedInteger(sceneObject.size());
            for(uint32_t i = 0; i < sceneObject.size(); i++) {
                file->writeString(sceneObject[i]);
                file->writeNull(128);
            }

            file->writeNull(64);

            file->writeUnsignedInteger(sceneObjectInstance.size());
            for(uint32_t i = 0; i < sceneObjectInstance.size(); i++) {
                sceneObjectInstance[i]->write(file);
            }

            file->writeNull(64);
        }

        std::vector<std::string> Scenery::getSceneObject() const {
            return sceneObject;
        }

        void Scenery::insertSceneObject(std::string value) {
            sceneObject.push_back(value);
        }

        std::vector<SceneObjectInstance *> Scenery::getSceneObjectInstance() const {
            return sceneObjectInstance;
        }

        SceneObjectInstance *Scenery::getSceneObjectInstance(std::string name) {
            for(int i = sceneObjectInstance.size() - 1; i >= 0; i--) {
                if(sceneObjectInstance[i]->getName() == name)
                    return sceneObjectInstance[i];
            }

            return nullptr;
        }

        void Scenery::insertSceneObjectInstance(SceneObjectInstance* value) {
            sceneObjectInstance.push_back(value);
        }
    }
}

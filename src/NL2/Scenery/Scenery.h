#ifndef LIB_NL2PARK_SCEN_H
#define LIB_NL2PARK_SCEN_H

#include "../../Stream/Chunk.h"
#include <vector>
#include "SceneObjectInstance.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Scenery: public Stream::Chunk {
        public:
            Scenery() {}

            void debug() {
                std::cout << "Scenery[getSceneObject.size]: " << sceneObject.size() << std::endl;
                if(sceneObject.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < sceneObject.size(); i++) {
                    std::cout << "SceneryObject: " << sceneObject[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Scenery[getSceneObjectInstance.size]: " << sceneObject.size() << std::endl;
                if(sceneObjectInstance.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < sceneObjectInstance.size(); i++) {
                    sceneObjectInstance[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            void read(File::File *file);
            void write(File::File *file);

            std::vector<std::string> getSceneObject() const;
            void insertSceneObject(std::string value);

            std::vector<SceneObjectInstance *> getSceneObjectInstance() const;
            SceneObjectInstance* getSceneObjectInstance(std::string name);
            void insertSceneObjectInstance(SceneObjectInstance * value);

            std::string getChunkName() { return "SCEN"; }
        private:
            std::vector<std::string> sceneObject;
            std::vector<SceneObjectInstance*> sceneObjectInstance;
        };
    }
}

#endif // LIB_NL2PARK_SCEN_H

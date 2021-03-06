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

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            std::vector<std::string> getSceneObject() const;
            uint32_t insertSceneObject(std::string value);

            std::vector<SceneObjectInstance *> getSceneObjectInstance() const;
            SceneObjectInstance* getSceneObjectInstance(std::string name);
            uint32_t insertSceneObjectInstance(SceneObjectInstance * value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SCEN"; }
            /*! \endcond */
        private:
            std::vector<std::string> sceneObject;
            std::vector<SceneObjectInstance*> sceneObjectInstance;
        };
    }
}

#endif // LIB_NL2PARK_SCEN_H

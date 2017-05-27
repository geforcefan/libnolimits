#ifndef LIB_NL2PARK_FREENODE_H
#define LIB_NL2PARK_FREENODE_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class FreeNode : public Stream::Chunk {
        public:
            FreeNode() {
                setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
            }

            FreeNode(glm::vec3 position) {
                setPosition(position);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "FreeNode[getPosition]: " << Helper::debug(getPosition()) << std::endl;
            }

            glm::vec3 getPosition() const;
            void setPosition(const glm::vec3 &value);

        private:
            glm::vec3 position;
        };
    }
}

#endif // LIB_NL2PARK_FREENODE_H

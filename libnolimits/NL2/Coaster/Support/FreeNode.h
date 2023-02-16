#ifndef LIB_NL2PARK_FREENODE_H
#define LIB_NL2PARK_FREENODE_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class FreeNode : public Stream::Chunk {
        public:
            FreeNode() {}

            FreeNode(glm::dvec3 position) {
                setPosition(position);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "FreeNode[getPosition]: " << Helper::debug(getPosition()) << std::endl;
            }

            glm::dvec3 getPosition() const;
            void setPosition(const glm::dvec3 &value);

        private:
            glm::dvec3 position = glm::dvec3(0.0f, 0.0f, 0.0f);
        };
    }
}

#endif // LIB_NL2PARK_FREENODE_H

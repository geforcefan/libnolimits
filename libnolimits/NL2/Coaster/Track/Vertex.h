#ifndef LIB_NL2PARK_VERTEX_H
#define LIB_NL2PARK_VERTEX_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Vertex : public Stream::Chunk {
        public:
            Vertex() {
                setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
                setLocked(false);
                setStrict(false);
            }

            Vertex(glm::vec4 position, bool locked, bool strict) {
                setPosition(position);
                setLocked(locked);
                setStrict(strict);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Vertex[getPosition]: " << Helper::debug(getPosition()) << std::endl;
                std::cout << "Vertex[getLocked]: " << getLocked() << std::endl;
                std::cout << "Vertex[getStrict]: " << getStrict() << std::endl;
            }

            glm::vec4 getPosition() const;
            void setPosition(const glm::vec4 &value);

            bool getLocked() const;
            void setLocked(bool value);

            bool getStrict() const;
            void setStrict(bool value);

        private:
            glm::vec4 position;
            bool locked;
            bool strict;
        };
    }
}

#endif // LIB_NL2PARK_VERTEX_H

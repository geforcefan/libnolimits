#ifndef LIB_NL2PARK_FREENODE_H
#define LIB_NL2PARK_FREENODE_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class FreeNode : public Stream::Chunk {
        public:
            FreeNode() {}

            void read(File::File *file);
            void write(File::File *file);

            glm::vec3 getPosition() const;
            void setPosition(const glm::vec3 &value);

        private:
            glm::vec3 position;
        };
    }
}

#endif // LIB_NL2PARK_FREENODE_H

#ifndef LIB_NL2PARK_VERTEX_H
#define LIB_NL2PARK_VERTEX_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class Vertex : public Stream::Chunk {
        public:
            Vertex() {}
            void read(File::File *file);
            void write(File::File *file);

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

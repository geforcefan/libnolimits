#include "Vertex.h"

namespace Library {
    namespace NL2Park {
        void Vertex::read(File::File *file) {
            setPosition(file->readDoubleVec4());
            setLocked(file->readBoolean());
            setStrict(file->readBoolean());

            file->readNull(22);
        }

        glm::vec4 Vertex::getPosition() const {
            return position;
        }

        void Vertex::setPosition(const glm::vec4 &value) {
            position = value;
        }

        bool Vertex::getLocked() const {
            return locked;
        }

        void Vertex::setLocked(bool value) {
            locked = value;
        }

        bool Vertex::getStrict() const {
            return strict;
        }

        void Vertex::setStrict(bool value) {
            strict = value;
        }
    }

}

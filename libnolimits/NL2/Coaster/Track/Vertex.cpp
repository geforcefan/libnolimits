#include "Vertex.h"

namespace NoLimits {
    namespace NoLimits2 {
        void Vertex::read(File::File *file) {
            setPosition(file->readDoubleVec4());
            setLocked(file->readBoolean());
            setStrict(file->readBoolean());

            file->readNull(22);
        }

        void Vertex::write(File::File *file) {
            file->writeDoubleVec4(getPosition());
            file->writeBoolean(getLocked());
            file->writeBoolean(getStrict());

            file->writeNull(22);
        }

        glm::dvec4 Vertex::getPosition() const {
            return position;
        }

        void Vertex::setPosition(const glm::dvec4 &value) {
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

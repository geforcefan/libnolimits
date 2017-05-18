#include "FreeNode.h"

namespace NoLimits {
    namespace NoLimits2 {
        void FreeNode::read(File::File *file) {
            setPosition(file->readDoubleVec3());
            file->readNull(4);
        }

        void FreeNode::write(File::File *file) {
            file->writeDoubleVec3(getPosition());
            file->writeNull(4);
        }

        glm::vec3 FreeNode::getPosition() const {
            return position;
        }

        void FreeNode::setPosition(const glm::vec3 &value) {
            position = value;
        }
    }
}

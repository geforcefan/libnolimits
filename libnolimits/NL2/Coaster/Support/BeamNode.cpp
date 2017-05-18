#include "BeamNode.h"

namespace NoLimits {
    namespace NoLimits2 {
        void BeamNode::read(File::File *file) {
            setPosition(file->readFloat());
            setIsFlange(file->readBoolean());

            file->readNull(11);
        }

        void BeamNode::write(File::File *file) {
            file->writeFloat(getPosition());
            file->writeBoolean(getIsFlange());

            file->writeNull(11);
        }

        bool BeamNode::getIsFlange() const {
            return isFlange;
        }

        void BeamNode::setIsFlange(bool value) {
            isFlange = value;
        }

        float BeamNode::getPosition() const {
            return position;
        }

        void BeamNode::setPosition(float value) {
            position = value;
        }
    }
}

#include "BeamNode.h"

namespace NoLimits {
    namespace NoLimits2 {
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

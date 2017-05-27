#ifndef LIB_NL2PARK_FLANGE_H
#define LIB_NL2PARK_FLANGE_H

#include "../../../Stream/Chunk.h"
#include "BeamNode.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Flange : public BeamNode {
        public:
            Flange() : BeamNode() {
                setIsFlange(true);
            }

            Flange(float position) : BeamNode(position) {
                setIsFlange(true);
            }
        };
    }
}

#endif // LIB_NL2PARK_FLANGE_H

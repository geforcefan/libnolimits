#ifndef LIB_NL2PARK_BEAMNODE_H
#define LIB_NL2PARK_BEAMNODE_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class BeamNode : public Stream::Chunk {
        public:
            BeamNode() {
                setIsFlange(false);
                setPosition(0.0f);
            }

            BeamNode(float position) : BeamNode() {
                setPosition(position);
            }

            void debug() {
                std::cout << "BeamNode[getIsFlange]: " << getIsFlange() << std::endl;
                std::cout << "BeamNode[getPosition]: " << getPosition() << std::endl;
            }

            float getPosition() const;
            void setPosition(float value);

            bool getIsFlange() const;
        protected:
            void setIsFlange(bool value);

        private:
            float position;
            bool isFlange;
        };
    }
}

#endif // LIB_NL2PARK_BEAMNODE_H

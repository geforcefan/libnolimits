#ifndef LIB_NL2PARK_BEAM_H
#define LIB_NL2PARK_BEAM_H

#include "../../../Stream/Chunk.h"
#include "BeamNode.h"
#include "Flange.h"
#include "BeamConnection.h"
#include "SupportNode.h"

#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
        class Beam : public Stream::Chunk, public SupportNode {
        public:
            enum Type {
                None,
                Pipe,
                LoopingBeam,
                LBeam,
                HBeam,
                BoxBeam,
                WoodenChordBeam,
                WoodenCatwalk,
                CBeam,
                Cable
            };

            enum LODPriority {
                Highest,
                High,
                Medium,
                Low,
                Lowest
            };

            enum RotationMode {
                HorizontalBeam,
                VerticalBeam
            };

            Beam() : SupportNode() {
                connection1 = new BeamConnection();
                connection2 = new BeamConnection();

                setType(Type::Pipe);
                setStartWidth(0.5f);
                setEndWidth(0.5f);
                setRotationAngle(0.0f);
                setExtraLengthAtStart(0.0f);
                setExtraLengthAtEnd(0.0f);
                setNodeOffsetRelativeX(0.0f);
                setNodeOffsetAbsoluteYStart(0.0f);
                setNodeOffsetAbsoluteYEnd(0.0f);
                setRotationMode(RotationMode::HorizontalBeam);
                setLODPriority(LODPriority::Highest);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                SupportNode::debug();

                std::cout << "Beam[getConnection1]: " << std::endl;
                getConnection1()->debug();

                std::cout << "Beam[getConnection2]: " << std::endl;
                getConnection2()->debug();

                std::cout << "Beam[getType]: " << getType() << std::endl;
                std::cout << "Beam[getStartWidth]: " << getStartWidth() << std::endl;
                std::cout << "Beam[getEndWidth]: " << getEndWidth() << std::endl;
                std::cout << "Beam[getRotationAngle]: " << getRotationAngle() << std::endl;
                std::cout << "Beam[getExtraLengthAtStart]: " << getExtraLengthAtStart() << std::endl;
                std::cout << "Beam[getExtraLengthAtEnd]: " << getExtraLengthAtEnd() << std::endl;
                std::cout << "Beam[getNodeOffsetRelativeX]: " << getNodeOffsetRelativeX() << std::endl;
                std::cout << "Beam[getNodeOffsetAbsoluteYStart]: " << getNodeOffsetAbsoluteYStart() << std::endl;
                std::cout << "Beam[getNodeOffsetAbsoluteYEnd]: " << getNodeOffsetAbsoluteYEnd() << std::endl;
                std::cout << "Beam[getRotationMode]: " << getRotationMode() << std::endl;
                std::cout << "Beam[getLODPriority]: " << getLODPriority() << std::endl;

                std::cout << "Beam[beamNode.size]: " << beamNode.size() << std::endl;
                if(beamNode.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < beamNode.size(); i++) {
                    beamNode[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            BeamConnection *getConnection1() const;
            void setConnection1(BeamConnection *value);

            BeamConnection *getConnection2() const;
            void setConnection2(BeamConnection *value);

            Type getType() const;
            void setType(const Type &value);

            float getStartWidth() const;
            void setStartWidth(float value);

            float getEndWidth() const;
            void setEndWidth(float value);

            float getRotationAngle() const;
            void setRotationAngle(float value);

            float getExtraLengthAtStart() const;
            void setExtraLengthAtStart(float value);

            float getExtraLengthAtEnd() const;
            void setExtraLengthAtEnd(float value);

            float getNodeOffsetRelativeX() const;
            void setNodeOffsetRelativeX(float value);

            float getNodeOffsetAbsoluteYStart() const;
            void setNodeOffsetAbsoluteYStart(float value);

            float getNodeOffsetAbsoluteYEnd() const;
            void setNodeOffsetAbsoluteYEnd(float value);

            std::vector<BeamNode *> getBeamNode() const;
            uint32_t insertBeamNode(BeamNode* value);
            uint32_t insertFlange(Flange *value);

            RotationMode getRotationMode();
            void setRotationMode(RotationMode value);

            LODPriority getLODPriority();
            void setLODPriority(LODPriority value);
        private:
            void setFlag1(const uint8_t &value);
            void setFlag2(const uint8_t &value);
            void setFlag3(const uint8_t &value);

            BeamConnection* connection1;
            BeamConnection* connection2;

            Type type;

            float startWidth;
            float endWidth;

            float rotationAngle;

            float extraLengthAtStart;
            float extraLengthAtEnd;

            float nodeOffsetRelativeX;
            float nodeOffsetAbsoluteYStart;
            float nodeOffsetAbsoluteYEnd;

            std::vector<BeamNode*> beamNode;
        };
    }
}

#endif // LIB_NL2PARK_BEAM_H

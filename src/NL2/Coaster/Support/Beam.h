#ifndef LIB_NL2PARK_BEAM_H
#define LIB_NL2PARK_BEAM_H

#include <Stream/Chunk.h>
#include "BeamNode.h"
#include "BeamConnection.h"
#include "SupportNode.h"

#include <vector>

namespace NoLimits {
    namespace NL2 {
        class Beam : public Stream::Chunk, public SupportNode {
        public:
            enum Type {
                Pipe = 1,
                LoopingBeam = 2,
                LBeam = 3,
                HBeam = 4,
                BoxBeam = 5,
                WoodenChordBeam = 6,
                WoodenCatwalk = 7,
                CBeam = 8,
                Cable = 9
            };

            enum LODPriority {
                Highest = 0,
                High = 1,
                Medium = 2,
                Low = 3,
                Lowest = 4
            };

            enum RotationMode {
                HorizontalBeam = 0,
                VerticalBeam = 1
            };

            Beam() {
                connection1 = new BeamConnection();
                connection2 = new BeamConnection();
            }

            void read(File::File *file);
            void write(File::File *file);

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
            void insertBeamNode(BeamNode* value);

            RotationMode getRotationMode() const;
            void setRotationMode(const RotationMode &value);

            LODPriority getLodPriority() const;
            void setLodPriority(const LODPriority &value);

            void setFlag1(const uint8_t &value);
            void setFlag2(const uint8_t &value);
            void setFlag3(const uint8_t &value);

            RotationMode getRotationMode();
            void setRotationMode(RotationMode value);

            LODPriority getLODPriority();
            void setLODPriority(LODPriority value);
        private:
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

            RotationMode rotationMode;
            LODPriority lodPriority;
        };
    }
}

#endif // LIB_NL2PARK_BEAM_H

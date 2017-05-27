#include "Beam.h"

namespace NoLimits {
    namespace NoLimits2 {
        void Beam::read(File::File *file) {
            beamNode.clear();

            BeamConnection::Type connection1Type = (BeamConnection::Type)file->readUnsignedInteger();
            setConnection1(BeamConnection::createBeamConnectionFromType(connection1Type));
            getConnection1()->read(file);

            BeamConnection::Type connection2Type = (BeamConnection::Type)file->readUnsignedInteger();
            setConnection2(BeamConnection::createBeamConnectionFromType(connection2Type));
            getConnection2()->read(file);

            file->readNull(3);

            setType((Beam::Type)file->readUnsigned8());

            file->readNull(1);

            setFlag1(file->readUnsigned8());
            setFlag2(file->readUnsigned8());
            setFlag3(file->readUnsigned8());

            setStartWidth(file->readFloat());
            setEndWidth(file->readFloat());
            setRotationAngle(file->readFloat());
            setColor(file->readColor());

            setExtraLengthAtStart(file->readFloat());
            setExtraLengthAtEnd(file->readFloat());
            setNodeOffsetRelativeX(file->readFloat());
            setNodeOffsetAbsoluteYStart(file->readFloat());
            setNodeOffsetAbsoluteYEnd(file->readFloat());

            file->readNull(13);

            uint32_t numberOfBeamNodes = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfBeamNodes; i++) {
                float position = file->readFloat();
                bool isFlange = file->readBoolean();

                file->readNull(11);

                BeamNode* _beamNode = nullptr;

                if(isFlange)
                    _beamNode = new Flange();
                else
                    _beamNode = new BeamNode();

                _beamNode->setPosition(position);
                insertBeamNode(_beamNode);
            }
        }

        void Beam::write(File::File *file) {
            file->writeUnsignedInteger(getConnection1()->getType());
            getConnection1()->write(file);

            file->writeUnsignedInteger(getConnection2()->getType());
            getConnection2()->write(file);

            file->writeNull(3);

            file->writeUnsigned8(getType());

            file->writeNull(1);

            file->writeUnsigned8(flag1);
            file->writeUnsigned8(flag2);
            file->writeUnsigned8(flag3);

            file->writeFloat(getStartWidth());
            file->writeFloat(getEndWidth());
            file->writeFloat(getRotationAngle());
            file->writeColor(getColor());

            file->writeFloat(getExtraLengthAtStart());
            file->writeFloat(getExtraLengthAtEnd());
            file->writeFloat(getNodeOffsetRelativeX());
            file->writeFloat(getNodeOffsetAbsoluteYStart());
            file->writeFloat(getNodeOffsetAbsoluteYEnd());

            file->writeNull(13);

            file->writeUnsignedInteger(beamNode.size());
            for(uint32_t i = 0; i < beamNode.size(); i++) {
                file->writeFloat(beamNode[i]->getPosition());
                file->writeBoolean(beamNode[i]->getIsFlange());
                file->writeNull(11);
            }
        }

        BeamConnection *Beam::getConnection1() const {
            return connection1;
        }

        void Beam::setConnection1(BeamConnection *value) {
            connection1 = value;
        }

        BeamConnection *Beam::getConnection2() const {
            return connection2;
        }

        void Beam::setConnection2(BeamConnection *value) {
            connection2 = value;
        }

        Beam::Type Beam::getType() const {
            return type;
        }

        void Beam::setType(const Beam::Type &value) {
            type = value;
        }

        float Beam::getStartWidth() const {
            return startWidth;
        }

        void Beam::setStartWidth(float value) {
            startWidth = value;
        }

        float Beam::getEndWidth() const {
            return endWidth;
        }

        void Beam::setEndWidth(float value) {
            endWidth = value;
        }

        float Beam::getRotationAngle() const {
            return rotationAngle;
        }

        void Beam::setRotationAngle(float value) {
            rotationAngle = value;
        }

        float Beam::getExtraLengthAtStart() const {
            return extraLengthAtStart;
        }

        void Beam::setExtraLengthAtStart(float value) {
            extraLengthAtStart = value;
        }

        float Beam::getExtraLengthAtEnd() const {
            return extraLengthAtEnd;
        }

        void Beam::setExtraLengthAtEnd(float value) {
            extraLengthAtEnd = value;
        }

        float Beam::getNodeOffsetRelativeX() const {
            return nodeOffsetRelativeX;
        }

        void Beam::setNodeOffsetRelativeX(float value) {
            nodeOffsetRelativeX = value;
        }

        float Beam::getNodeOffsetAbsoluteYStart() const {
            return nodeOffsetAbsoluteYStart;
        }

        void Beam::setNodeOffsetAbsoluteYStart(float value) {
            nodeOffsetAbsoluteYStart = value;
        }

        float Beam::getNodeOffsetAbsoluteYEnd() const {
            return nodeOffsetAbsoluteYEnd;
        }

        void Beam::setNodeOffsetAbsoluteYEnd(float value) {
            nodeOffsetAbsoluteYEnd = value;
        }

        std::vector<BeamNode *> Beam::getBeamNode() const {
            return beamNode;
        }

        uint32_t Beam::insertBeamNode(BeamNode *value) {
            beamNode.push_back(value);
            return beamNode.size() - 1;
        }

        uint32_t Beam::insertFlange(Flange *value) {
            beamNode.push_back(value);
            return beamNode.size() - 1;
        }

        void Beam::setFlag1(const uint8_t &value) {
            SupportNode::setFlag1(value);
        }

        void Beam::setFlag2(const uint8_t &value) {
            SupportNode::setFlag2(value);
        }

        void Beam::setFlag3(const uint8_t &value) {
            SupportNode::setFlag3(value);
        }

        Beam::RotationMode Beam::getRotationMode() {
            if(hasFlag2(SupportNode::Flags::RotationModeAzimuth))
                return Beam::RotationMode::VerticalBeam;
            else
                return Beam::RotationMode::HorizontalBeam;
        }

        void Beam::setRotationMode(Beam::RotationMode value) {
            setWithCheckFlag2(SupportNode::Flags::RotationModeAzimuth, false);

            switch(value) {
                case Beam::RotationMode::VerticalBeam:
                    setWithCheckFlag2(SupportNode::Flags::RotationModeAzimuth, true);
                    break;
                case Beam::RotationMode::HorizontalBeam:
                    break;
            }
        }

        Beam::LODPriority Beam::getLODPriority() {
            if(hasFlag3(3))
                return Beam::LODPriority::Lowest;
            else if(hasFlag3(1) && hasFlag3(2))
                return Beam::LODPriority::Low;
            else if(!hasFlag3(1) && hasFlag3(2))
                return Beam::LODPriority::Medium;
            else if(hasFlag3(1) && !hasFlag3(2))
                return Beam::LODPriority::High;
            else
                return Beam::LODPriority::Highest;
        }

        void Beam::setLODPriority(Beam::LODPriority value) {
            setWithCheckFlag3(1, false);
            setWithCheckFlag3(2, false);
            setWithCheckFlag3(3, false);

            switch(value) {
                case Beam::LODPriority::Lowest:
                    setWithCheckFlag3(3, true);
                    break;
                case Beam::LODPriority::Low:
                    setWithCheckFlag3(1, true);
                    setWithCheckFlag3(2, true);
                    break;
                case Beam::LODPriority::Medium:
                    setWithCheckFlag3(2, true);
                    break;
                case Beam::LODPriority::High:
                    setWithCheckFlag3(1, true);
                    break;
                case Beam::LODPriority::Highest:
                    break;
            }
        }
    }
}

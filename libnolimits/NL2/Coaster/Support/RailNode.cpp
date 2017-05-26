#include "RailNode.h"

namespace NoLimits {
    namespace NoLimits2 {
        void RailNode::read(File::File *file) {
            supportParameter.clear();

            setPosition(file->readDouble());

            file->readNull(1);

            setColor(file->readColor());

            file->readNull(2);

            setIsModel(file->readBoolean());
            uint8_t style = file->readUnsigned8();

            if(!getIsModel()) {
                if(style == 0)
                    setConnectionStyle(RailNode::ConnectionStyle::Simple);
                if(style == 1)
                    setConnectionStyle(RailNode::ConnectionStyle::Prefab);
                if(style == 2)
                    setConnectionStyle(RailNode::ConnectionStyle::TrackDefault);
            } else {
                if(style == 0)
                    setConnectionStyle(RailNode::ConnectionStyle::TwistedStraightDown);
                if(style == 1)
                    setConnectionStyle(RailNode::ConnectionStyle::TwistedHorizontal);
                if(style == 2)
                    setConnectionStyle(RailNode::ConnectionStyle::TwistedVertical);
                if(style == 3)
                    setConnectionStyle(RailNode::ConnectionStyle::CorkscrewStraightDown);
                if(style == 4)
                    setConnectionStyle(RailNode::ConnectionStyle::Horizontal4D);
                if(style == 5)
                    setConnectionStyle(RailNode::ConnectionStyle::Vertical4D);
                if(style == 6)
                    setConnectionStyle(RailNode::ConnectionStyle::Aligned4D);
                if(style == 7)
                    setConnectionStyle(RailNode::ConnectionStyle::Special4D);
                if(style == 8)
                    setConnectionStyle(RailNode::ConnectionStyle::SuspendedHorizontal);
                if(style == 9)
                    setConnectionStyle(RailNode::ConnectionStyle::SuspendedVertical);
            }

            setSizeParameter(file->readDouble());
            uint32_t prefabIndex = file->readUnsignedInteger();

            if(!getIsModel() && getConnectionStyle() == RailNode::ConnectionStyle::Prefab) {
                setPrefabIndex(prefabIndex - 1);
            } else {
                setPrefabIndex(0);
            }

            file->readNull(1);

            setFlag1(file->readUnsigned8());
            setFlag2(file->readUnsigned8());
            setFlag3(file->readUnsigned8());

            file->readNull(8);

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "SPPM") {
                    SupportParameter *supportParameter = new SupportParameter();
                    insertSupportParameter(supportParameter);

                    file->readChunk(supportParameter);
                    i = file->tell() - 1;
                }
            }
        }

        void RailNode::write(File::File *file) {
            file->writeDouble(getPosition());

            file->writeNull(1);

            file->writeColor(getColor());

            file->writeNull(2);

            (file->writeBoolean(getIsModel()));

            uint8_t style = getConnectionStyle();

            if(!getIsModel()) {
                if(style == RailNode::ConnectionStyle::Simple)
                    file->writeUnsigned8(0);
                if(style == RailNode::ConnectionStyle::Prefab)
                    file->writeUnsigned8(1);
                if(style == RailNode::ConnectionStyle::TrackDefault)
                    file->writeUnsigned8(2);
            } else {
                if(style == RailNode::ConnectionStyle::TwistedStraightDown)
                    file->writeUnsigned8(0);
                if(style == RailNode::ConnectionStyle::TwistedHorizontal)
                    file->writeUnsigned8(1);
                if(style == RailNode::ConnectionStyle::TwistedVertical)
                    file->writeUnsigned8(2);
                if(style == RailNode::ConnectionStyle::CorkscrewStraightDown)
                    file->writeUnsigned8(3);
                if(style == RailNode::ConnectionStyle::Horizontal4D)
                    file->writeUnsigned8(4);
                if(style == RailNode::ConnectionStyle::Vertical4D)
                    file->writeUnsigned8(5);
                if(style == RailNode::ConnectionStyle::Aligned4D)
                    file->writeUnsigned8(6);
                if(style == RailNode::ConnectionStyle::Special4D)
                    file->writeUnsigned8(7);
                if(style == RailNode::ConnectionStyle::SuspendedHorizontal)
                    file->writeUnsigned8(8);
                if(style == RailNode::ConnectionStyle::SuspendedVertical)
                    file->writeUnsigned8(9);
            }

            file->writeDouble(getSizeParameter());

            if(!getIsModel() && style == RailNode::ConnectionStyle::Prefab) {
                file->writeUnsignedInteger(getPrefabIndex() + 1);
            } else {
                file->writeUnsignedInteger(0);
            }

            file->writeNull(1);

            file->writeUnsigned8(flag1);
            file->writeUnsigned8(flag2);
            file->writeUnsigned8(flag3);

            file->writeNull(8);

            if(supportParameter.size())
                for(uint32_t i = 0; i < supportParameter.size(); i++)
                    file->writeChunk(supportParameter[i]);
        }

        double RailNode::getPosition() const {
            return position;
        }

        void RailNode::setPosition(double value) {
            position = value;
        }

        double RailNode::getSizeParameter() const {
            return sizeParameter;
        }

        void RailNode::setSizeParameter(double value) {
            sizeParameter = value;
        }

        uint32_t RailNode::getTrackIndex() const {
            return trackIndex;
        }

        void RailNode::setTrackIndex(const uint32_t &value) {
            trackIndex = value;
        }

        RailNode::ConnectionStyle RailNode::getConnectionStyle() const {
            return connectionStyle;
        }

        void RailNode::setConnectionStyle(const RailNode::ConnectionStyle &value) {
            connectionStyle = value;
        }

        bool RailNode::getIsModel() const {
            return isModel;
        }

        void RailNode::setIsModel(bool value) {
            isModel = value;
        }

        uint32_t RailNode::getPrefabIndex() const {
            return prefabIndex;
        }

        void RailNode::setPrefabIndex(const uint32_t &value) {
            prefabIndex = value;
        }

        std::vector<SupportParameter *> RailNode::getSupportParameter() const {
            return supportParameter;
        }

        uint32_t RailNode::insertSupportParameter(SupportParameter *value) {
            supportParameter.push_back(value);
            return supportParameter.size() - 1;
        }
    }
}

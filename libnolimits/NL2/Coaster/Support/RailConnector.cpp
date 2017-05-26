#include "RailConnector.h"

namespace NoLimits {
    namespace NoLimits2 {
        void RailConnector::read(File::File *file) {
            supportParameter.clear();

            setPosition(file->readDouble());

            file->readNull(1);

            setColor(file->readColor());

            file->readNull(2);

            setIsModel(file->readBoolean());
            uint8_t style = file->readUnsigned8();

            if(!getIsModel()) {
                if(style == 0)
                    setConnectionStyle(RailConnector::ConnectionStyle::Simple);
                if(style == 1)
                    setConnectionStyle(RailConnector::ConnectionStyle::Prefab);
                if(style == 2)
                    setConnectionStyle(RailConnector::ConnectionStyle::TrackDefault);
            } else {
                if(style == 0)
                    setConnectionStyle(RailConnector::ConnectionStyle::TwistedStraightDown);
                if(style == 1)
                    setConnectionStyle(RailConnector::ConnectionStyle::TwistedHorizontal);
                if(style == 2)
                    setConnectionStyle(RailConnector::ConnectionStyle::TwistedVertical);
                if(style == 3)
                    setConnectionStyle(RailConnector::ConnectionStyle::CorkscrewStraightDown);
                if(style == 4)
                    setConnectionStyle(RailConnector::ConnectionStyle::Horizontal4D);
                if(style == 5)
                    setConnectionStyle(RailConnector::ConnectionStyle::Vertical4D);
                if(style == 6)
                    setConnectionStyle(RailConnector::ConnectionStyle::Aligned4D);
                if(style == 7)
                    setConnectionStyle(RailConnector::ConnectionStyle::Special4D);
                if(style == 8)
                    setConnectionStyle(RailConnector::ConnectionStyle::SuspendedHorizontal);
                if(style == 9)
                    setConnectionStyle(RailConnector::ConnectionStyle::SuspendedVertical);
            }

            setSizeParameter(file->readDouble());
            uint32_t prefabIndex = file->readUnsignedInteger();

            if(!getIsModel() && getConnectionStyle() == RailConnector::ConnectionStyle::Prefab) {
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

        void RailConnector::write(File::File *file) {
            file->writeDouble(getPosition());

            file->writeNull(1);

            file->writeColor(getColor());

            file->writeNull(2);

            (file->writeBoolean(getIsModel()));

            uint8_t style = getConnectionStyle();

            if(!getIsModel()) {
                if(style == RailConnector::ConnectionStyle::Simple)
                    file->writeUnsigned8(0);
                if(style == RailConnector::ConnectionStyle::Prefab)
                    file->writeUnsigned8(1);
                if(style == RailConnector::ConnectionStyle::TrackDefault)
                    file->writeUnsigned8(2);
            } else {
                if(style == RailConnector::ConnectionStyle::TwistedStraightDown)
                    file->writeUnsigned8(0);
                if(style == RailConnector::ConnectionStyle::TwistedHorizontal)
                    file->writeUnsigned8(1);
                if(style == RailConnector::ConnectionStyle::TwistedVertical)
                    file->writeUnsigned8(2);
                if(style == RailConnector::ConnectionStyle::CorkscrewStraightDown)
                    file->writeUnsigned8(3);
                if(style == RailConnector::ConnectionStyle::Horizontal4D)
                    file->writeUnsigned8(4);
                if(style == RailConnector::ConnectionStyle::Vertical4D)
                    file->writeUnsigned8(5);
                if(style == RailConnector::ConnectionStyle::Aligned4D)
                    file->writeUnsigned8(6);
                if(style == RailConnector::ConnectionStyle::Special4D)
                    file->writeUnsigned8(7);
                if(style == RailConnector::ConnectionStyle::SuspendedHorizontal)
                    file->writeUnsigned8(8);
                if(style == RailConnector::ConnectionStyle::SuspendedVertical)
                    file->writeUnsigned8(9);
            }

            file->writeDouble(getSizeParameter());

            if(!getIsModel() && style == RailConnector::ConnectionStyle::Prefab) {
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

        double RailConnector::getPosition() const {
            return position;
        }

        void RailConnector::setPosition(double value) {
            position = value;
        }

        double RailConnector::getSizeParameter() const {
            return sizeParameter;
        }

        void RailConnector::setSizeParameter(double value) {
            sizeParameter = value;
        }

        uint32_t RailConnector::getTrackIndex() const {
            return trackIndex;
        }

        void RailConnector::setTrackIndex(const uint32_t &value) {
            trackIndex = value;
        }

        RailConnector::ConnectionStyle RailConnector::getConnectionStyle() const {
            return connectionStyle;
        }

        void RailConnector::setConnectionStyle(const RailConnector::ConnectionStyle &value) {
            connectionStyle = value;
        }

        bool RailConnector::getIsModel() const {
            return isModel;
        }

        void RailConnector::setIsModel(bool value) {
            isModel = value;
        }

        uint32_t RailConnector::getPrefabIndex() const {
            return prefabIndex;
        }

        void RailConnector::setPrefabIndex(const uint32_t &value) {
            prefabIndex = value;
        }

        std::vector<SupportParameter *> RailConnector::getSupportParameter() const {
            return supportParameter;
        }

        uint32_t RailConnector::insertSupportParameter(SupportParameter *value) {
            supportParameter.push_back(value);
            return supportParameter.size() - 1;
        }
    }
}

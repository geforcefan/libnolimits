#include "RailNode.h"

namespace Library {
    namespace NL2Park {
        void RailNode::read(File::File *file) {
            setPosition(file->readDouble());

            file->readNull(1);

            setColor(file->readColor());

            file->readNull(2);

            setIsModel(file->readBoolean());
            uint8_t style = file->readUnsigned8();

            if(!getIsModel()) {
                if(style == 0)
                    setConnectionStyle(RailNode::ConnectionStyle::Simple);
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

            file->readNull(5);

            setFlag1(file->readUnsigned8());
            setFlag2(file->readUnsigned8());
            setFlag3(file->readUnsigned8());
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
    }
}

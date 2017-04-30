#include "RollPoint.h"

namespace Library {
    namespace NL2Park {
        void RollPoint::read(File::File *file) {
            setPosition(file->readDouble());
            setRoll(file->readDouble());
            setVertical(file->readBoolean());
            setStrict(file->readBoolean());

            file->readNull(14);
        }

        double RollPoint::getPosition() const {
            return position;
        }

        void RollPoint::setPosition(double value) {
            position = value;
        }

        double RollPoint::getRoll() const {
            return roll;
        }

        void RollPoint::setRoll(double value) {
            roll = value;
        }

        bool RollPoint::getVertical() const {
            return vertical;
        }

        void RollPoint::setVertical(bool value) {
            vertical = value;
        }

        bool RollPoint::getStrict() const {
            return strict;
        }

        void RollPoint::setStrict(bool value) {
            strict = value;
        }
    }
}

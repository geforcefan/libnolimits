#include "Parameter4D.h"

namespace NoLimits {
    namespace NL2 {
        void Parameter4D::read(File::File *file) {
            setPosition(file->readDouble());
            setAngle(file->readDouble());

            file->readNull(20);
        }

        void Parameter4D::write(File::File *file) {
            file->writeDouble(getPosition());
            file->writeDouble(getAngle());

            file->writeNull(20);
        }

        double Parameter4D::getPosition() const {
            return position;
        }

        void Parameter4D::setPosition(double value) {
            position = value;
        }

        double Parameter4D::getAngle() const {
            return angle;
        }

        void Parameter4D::setAngle(double value) {
            angle = value;
        }
    }
}

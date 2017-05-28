#include "Train.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits1 {
        void Train::read(File::File *file) {
            getIndividualColor()->read(file);
        }

        void Train::write(File::File *file) {
            getIndividualColor()->write(file);
        }

        IndividualColor *Train::getIndividualColor() const {
            return individualColor;
        }

        void Train::setIndividualColor(IndividualColor *value) {
            individualColor = value;
        }
    }
}

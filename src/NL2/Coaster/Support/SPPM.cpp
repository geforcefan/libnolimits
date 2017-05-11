#include "SPPM.h"

namespace NoLimits {
    namespace NL2 {
        void SPPM::read(File::File *file) {
            // I DONT KNOW WHAT KIND OF CHUNK THIS IS!
            file->readNull(4);
            setUnknown(file->readFloat());
            file->readNull(4);
        }

        void SPPM::write(File::File *file) {
            // I DONT KNOW WHAT KIND OF CHUNK THIS IS!
            file->writeNull(4);
            file->writeFloat(getUnknown());
            file->writeNull(4);
        }

        float SPPM::getUnknown() const {
            return unknown;
        }

        void SPPM::setUnknown(float value) {
            unknown = value;
        }

    }
}

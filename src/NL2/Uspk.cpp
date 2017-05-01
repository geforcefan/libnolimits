#include <src/NL2/Uspk.h>
#include <iostream>

namespace NoLimits {
    namespace NL2 {
        void Uspk::read(File::File *file) {
            // I don´t know what this chunk does (USPK)
        }

        void Uspk::write(File::File *file) {
            file->writeNull(71);
            file->writeBoolean(true);
            file->writeString("intern");
            file->writeString("intern");
            file->writeString("This package is part of NoLimits2");
            file->writeNull(106);
        }
    }
}

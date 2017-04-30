#include <NL2Park/Coaster/Car.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Car::read(File::File *file) {
            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if (chunk == "INDC") {
                    getIndividualColor()->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }
            }
        }

        IndividualColor *Car::getIndividualColor() const {
            return individualColor;
        }

        void Car::setIndividualColor(IndividualColor *value) {
            individualColor = value;
        }

        bool Car::getIsZeroCar() const {
            return isZeroCar;
        }

        void Car::setIsZeroCar(bool value) {
            isZeroCar = value;
        }
    }
}

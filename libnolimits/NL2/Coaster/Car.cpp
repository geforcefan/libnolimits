#include "Car.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void Car::write(File::File *file) {
            file->writeUnsignedInteger(getInternalCarIndex());
            file->writeNull(32);

            if(getIndividualColor()->getHasIndividualColor()) {
                file->writeChunk(getIndividualColor());
            }
        }

        void Car::read(File::File *file) {
            setInternalCarIndex(file->readUnsignedInteger());

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if (chunk == "INDC") {
                    file->readChunk(getIndividualColor());
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

        uint32_t Car::getInternalCarIndex() const {
            return internalCarIndex;
        }

        void Car::setInternalCarIndex(const uint32_t &value) {
            internalCarIndex = value;
        }
    }
}

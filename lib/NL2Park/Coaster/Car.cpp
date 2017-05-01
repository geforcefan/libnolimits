#include <NL2Park/Coaster/Car.h>
#include <iostream>

namespace NoLimits {
    namespace NL2 {
        void Car::write(File::File *file) {
            file->writeUnsignedInteger(getCarIndex());
            file->writeNull(32);

            if(getIndividualColor()->getHasIndividualColor()) {
                file->writeFile(getIndividualColor()->writeChunk());
            }
        }

        void Car::read(File::File *file) {
            setCarIndex(file->readUnsignedInteger());

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if (chunk == "INDC") {
                    getIndividualColor()->readChunk(file->getChunkMemoryFile());
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

        uint32_t Car::getCarIndex() const {
            return carIndex;
        }

        void Car::setCarIndex(const uint32_t &value) {
            carIndex = value;
        }
    }
}

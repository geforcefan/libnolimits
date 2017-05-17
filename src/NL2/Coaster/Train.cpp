#include "Train.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void Train::write(File::File *file) {
            file->writeString(getStartBlock());
            file->writeUnsignedInteger(car.size() + (zeroCar ? 1 : 0));

            file->writeNull(4);

            file->writeBoolean(getRunBackward());
            file->writeBoolean(getRemovedFromTrack());

            file->writeNull(31);

            if(zeroCar) {
                zeroCar->setInternalCarIndex(0);
                file->writeChunk(zeroCar);
            }

            for(uint32_t i = 0; i < car.size(); i++) {
                car[i]->setInternalCarIndex(i + 1);
                file->writeChunk(car[i]);
            }

            if(getIndividualColor()->getHasIndividualColor()) {
                file->writeChunk(getIndividualColor());
            }
        }

        void Train::read(File::File *file) {
            car.clear();

            setStartBlock(file->readString());
            file->readUnsignedInteger(); // number of cars

            file->readNull(4);

            setRunBackward(file->readBoolean());
            setRemovedFromTrack(file->readBoolean());

            file->readNull(31);

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "CAR") {
                    Car *_car = new Car();
                    file->readChunk(_car);

                    if(_car->getInternalCarIndex())
                        insertCar(_car);
                    else
                        setZeroCar(_car);

                    i = file->tell() - 1;
                }

                if (chunk == "INDC") {
                    file->readChunk(getIndividualColor());
                    i = file->tell() - 1;
                }
            }
        }

        std::vector<Car*> Train::getCar() const {
            return car;
        }

        void Train::insertCar(Car* value) {
            car.push_back(value);
        }

        IndividualColor *Train::getIndividualColor() const {
            return individualColor;
        }

        void Train::setIndividualColor(IndividualColor *value) {
            individualColor = value;
        }

        bool Train::getRunBackward() const {
            return runBackward;
        }

        void Train::setRunBackward(bool value) {
            runBackward = value;
        }

        bool Train::getRemovedFromTrack() const {
            return removedFromTrack;
        }

        void Train::setRemovedFromTrack(bool value) {
            removedFromTrack = value;
        }

        std::string Train::getStartBlock() const {
            return startBlock;
        }

        void Train::setStartBlock(const std::string &value) {
            startBlock = value;
        }

        Car *Train::getZeroCar() const {
            return zeroCar;
        }

        void Train::setZeroCar(Car *value) {
            zeroCar = value;
        }
    }
}

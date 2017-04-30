#include <NL2Park/Coaster/Train.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Train::read(File::File *file) {
            file->readNull(1);

            setStartBlock(file->readString());
            file->readNull(1);

            file->readNull(7);
            setRunBackward(file->readBoolean());
            setRemovedFromTrack(file->readBoolean());

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "CAR") {
                    Car *_car = new Car();
                    insertCar(_car);

                    _car->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if (chunk == "INDC") {
                    getIndividualColor()->readChunk(file->getChunkBufferFile());
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
    }
}

#ifndef LIB_NL2PARK_TRAIN_H
#define LIB_NL2PARK_TRAIN_H

#include <Stream/Chunk.h>
#include "IndividualColor.h"
#include "Car.h"
#include <vector>

namespace Library {
    namespace NL2Park {
        class Train: public Stream::Chunk {
        public:
            Train() {
                individualColor = new IndividualColor();
            }

            void read(File::File *file);

            std::vector<Car*> getCar() const;
            void insertCar(Car* value);

            IndividualColor *getIndividualColor() const;
            void setIndividualColor(IndividualColor *value);

            bool getRunBackward() const;
            void setRunBackward(bool value);

            bool getRemovedFromTrack() const;
            void setRemovedFromTrack(bool value);

            std::string getStartBlock() const;
            void setStartBlock(const std::string &value);

        private:
            std::vector<Car*> car;
            IndividualColor* individualColor;
            bool runBackward;
            bool removedFromTrack;
            std::string startBlock;
        };
    }
}

#endif // LIB_NL2PARK_TRAIN_H

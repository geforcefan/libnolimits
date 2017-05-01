#ifndef LIB_NL2PARK_TRAIN_H
#define LIB_NL2PARK_TRAIN_H

#include <Stream/Chunk.h>
#include "IndividualColor.h"
#include "Car.h"
#include <vector>

namespace NoLimits {
    namespace NL2 {
        class Train: public Stream::Chunk {
        public:
            Train() {
                individualColor = new IndividualColor();
            }

            void debug() {
                std::cout << "Train[getRunBackward]: " << getRunBackward() << std::endl;
                std::cout << "Train[getRemovedFromTrack]: " << getRemovedFromTrack() << std::endl;
                std::cout << "Train[getStartBlock]: " << getStartBlock() << std::endl;

                getIndividualColor()->debug();

                std::cout << "Train[getCar.size]: " << car.size() << std::endl;
                if(car.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < car.size(); i++) {
                    car[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            void write(File::File *file);
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

            std::string getChunkName() { return "TRAI"; }
        };
    }
}

#endif // LIB_NL2PARK_TRAIN_H

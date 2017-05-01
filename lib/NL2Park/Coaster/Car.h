#ifndef LIB_NL2PARK_CAR_H
#define LIB_NL2PARK_CAR_H

#include <Stream/Chunk.h>
#include "IndividualColor.h"
#include <vector>

namespace NoLimits {
    namespace NL2 {
        class Car: public Stream::Chunk {
        public:
            Car() {
                individualColor = new IndividualColor();
            }

            void debug() {
                std::cout << "Car[getCarIndex]: " << getCarIndex() << std::endl;

                getIndividualColor()->debug();
            }

            void write(File::File *file);
            void read(File::File *file);

            IndividualColor *getIndividualColor() const;
            void setIndividualColor(IndividualColor *value);

            bool getIsZeroCar() const;
            void setIsZeroCar(bool value);

            uint32_t getCarIndex() const;
            void setCarIndex(const uint32_t &value);

        private:
            IndividualColor *individualColor;
            bool isZeroCar;
            uint32_t carIndex;

        protected:
            std::string getChunkName() { return "CAR "; }
        };
    }
}

#endif // LIB_NL2PARK_CAR_H

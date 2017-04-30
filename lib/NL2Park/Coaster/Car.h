#ifndef LIB_NL2PARK_CAR_H
#define LIB_NL2PARK_CAR_H

#include <Stream/Chunk.h>
#include "IndividualColor.h"
#include <vector>

namespace Library {
    namespace NL2Park {
        class Car: public Stream::Chunk {
        public:
            Car() {
                individualColor = new IndividualColor();
            }

            void read(File::File *file);

            IndividualColor *getIndividualColor() const;
            void setIndividualColor(IndividualColor *value);

            bool getIsZeroCar() const;
            void setIsZeroCar(bool value);

        private:
            IndividualColor *individualColor;
            bool isZeroCar;
        };
    }
}

#endif // LIB_NL2PARK_CAR_H

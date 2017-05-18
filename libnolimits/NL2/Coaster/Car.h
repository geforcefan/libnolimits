#ifndef LIB_NL2PARK_CAR_H
#define LIB_NL2PARK_CAR_H

#include "../../Stream/Chunk.h"
#include "IndividualColor.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
        class Car: public Stream::Chunk {
        public:
            Car() {
                individualColor = new IndividualColor();

                setInternalCarIndex(0);
            }

            void debug() {
                std::cout << "Car" << std::endl;
                getIndividualColor()->debug();
            }

            void write(File::File *file);
            void read(File::File *file);

            IndividualColor *getIndividualColor() const;
            void setIndividualColor(IndividualColor *value);

            uint32_t getInternalCarIndex() const;
            void setInternalCarIndex(const uint32_t &value);

        private:
            IndividualColor *individualColor;
            std::string getChunkName() { return "CAR "; }
            uint32_t internalCarIndex;
        };
    }
}

#endif // LIB_NL2PARK_CAR_H

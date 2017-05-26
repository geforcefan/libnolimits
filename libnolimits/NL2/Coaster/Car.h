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

            /*! \cond INTERNAL */
            void write(File::File *file);
            void read(File::File *file);
            /*! \endcond */

            IndividualColor *getIndividualColor() const;
            void setIndividualColor(IndividualColor *value);

            /*! \cond INTERNAL */
            uint32_t getInternalCarIndex() const;
            void setInternalCarIndex(const uint32_t &value);
            /*! \endcond */

            /*! \cond INTERNAL */
            std::string getChunkName() { return "CAR "; }
            /*! \endcond */
        private:
            IndividualColor *individualColor;

            /*! \cond INTERNAL */
            uint32_t internalCarIndex;
            /*! \endcond */
        };
    }
}

#endif // LIB_NL2PARK_CAR_H

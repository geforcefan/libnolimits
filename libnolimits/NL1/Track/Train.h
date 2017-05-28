#ifndef LIB_NOLIMITS_NL1_TRAIN_H
#define LIB_NOLIMITS_NL1_TRAIN_H

#include "../../Stream/Chunk.h"
#include "IndividualColor.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits1 {
        class Train: public Stream::Chunk {
        public:
            Train() {
                setIndividualColor(new IndividualColor());
            }

            void debug() {
                getIndividualColor()->debug();
            }

            IndividualColor *getIndividualColor() const;
            void setIndividualColor(IndividualColor *value);

            /*! \cond INTERNAL */
            void write(File::File *file);
            void read(File::File *file);
            /*! \endcond */
        private:
            IndividualColor *individualColor;
        };
    }
}

#endif // LIB_NOLIMITS_NL1_TRAIN_H

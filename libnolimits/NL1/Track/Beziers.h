#ifndef LIB_NOLIMITS_NL1_BEZIERS_H
#define LIB_NOLIMITS_NL1_BEZIERS_H

#include "../../Nolimits.h"
#include "../../Stream/Chunk.h"
#include <string>
#include <ostream>
#include <vector>

/*! \cond INTERNAL */
namespace NoLimits {
    namespace NoLimits1 {
        class Track;

        class Beziers: public Stream::Chunk {
        public:
            Beziers(Track *_track) : track(_track) {}

            void read(File::File *file);
            void write(File::File *file);

            std::string getChunkName() { return "BEZR"; }
        private:
            Track *track;
        };
    }
}
/*! \endcond */

#endif // LIB_NOLIMITS_NL1_BEZIERS_H

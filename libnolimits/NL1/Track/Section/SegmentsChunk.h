#ifndef LIB_NOLIMITS_NL1_SEGMENTS_CHUNK_H
#define LIB_NOLIMITS_NL1_SEGMENTS_CHUNK_H

#include "../../../Stream/Chunk.h"

/*! \cond INTERNAL */
namespace NoLimits {
    namespace NoLimits1 {
        class Track;

        class SegmentsChunk: public Stream::Chunk {
        public:
            SegmentsChunk(Track *_track) : track(_track) {}

            void read(File::File *file);
            void write(File::File *file);

            std::string getChunkName() { return "SEGM"; }
        private:
            Track *track;
        };
    }
}
/*! \endcond */

#endif // LIB_NOLIMITS_NL1_SEGMENTS_CHUNK_H

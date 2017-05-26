#ifndef LIB_STREAM_CHUNK_H
#define LIB_STREAM_CHUNK_H

#include "../File/File.h"

#include <stdint.h>
#include "../Nolimits.h"

namespace NoLimits {
    namespace Stream {
        class Chunk {
        public:
            /*! \cond INTERNAL */
            virtual void read(File::File *file) {}
            virtual void write(File::File *file) {}
            virtual std::string getChunkName() { return "CHNK"; }
            /*! \endcond */

            virtual void debug() {}
        };
    }
}

#endif // LIB_STREAM_CHUNK_H

#ifndef LIB_STREAM_CHUNK_H
#define LIB_STREAM_CHUNK_H

#include "../File/File.h"

#include <stdint.h>
#include <nolimits.h>

namespace NoLimits {
    namespace Stream {
        class Chunk {
        public:
            virtual void read(File::File *file) {}
            virtual void write(File::File *file) {}
            virtual void debug() {}
            virtual std::string getChunkName() { return "CHNK"; }
        };
    }
}

#endif // LIB_STREAM_CHUNK_H

#ifndef LIB_STREAM_CHUNK_H
#define LIB_STREAM_CHUNK_H

#include <File/File.h>

#include <stdint.h>
#include <nolimits.h>

namespace NoLimits {
    namespace Stream {
        class Chunk {
        public:
            Chunk() {}

            void readChunk(File::File *file);
            File::File* writeChunk();

            virtual void debug() {}
        protected:
            virtual void read(File::File *file) {}
            virtual void write(File::File *file) {}

            virtual std::string getChunkName() { return "CHNK"; }
        };
    }
}

#endif // LIB_STREAM_CHUNK_H

#include "Chunk.h"
#include <iostream>
#include <zlib.h>

#include <File/MemoryFile.h>

#define ZLIB_CHUNK 16384

namespace NoLimits {
    namespace Stream {
        void Chunk::readChunk(File::File *file) {
            file->openRB();
            file->readNull(4); // Chunk size
            read(file);
            file->close();
        }

        File::File* Chunk::writeChunk() {
            File::MemoryFile *fileChunk = new File::MemoryFile();
            File::MemoryFile *fileChunkInner = new File::MemoryFile();

            fileChunkInner->openWB();
            write(fileChunkInner);
            fileChunkInner->close();

            fileChunk->openWB();
            fileChunk->writeChunkName(getChunkName());
            fileChunk->writeUnsignedInteger((uint32_t)fileChunkInner->getFilesize());
            fileChunk->writeFile(fileChunkInner);
            fileChunk->close();

            return fileChunk;
        }
    }
}

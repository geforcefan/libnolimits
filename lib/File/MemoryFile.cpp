#include <File/MemoryFile.h>

#include <stdlib.h>
#include <stdexcept>
#include <fstream>
#include <iostream>

namespace NoLimits {
    namespace File {
        MemoryFile::MemoryFile() : File() {
            bufferSize = 0;
            buffer = (void*) malloc(bufferSize);
        }

        bool MemoryFile::openWB() {
            if(openedRB || openedWB) close();
            openedWB = true;
            pos = 0;

            return true;
        }

        void MemoryFile::setBuffer(void *_buffer, long _size) {
            buffer = _buffer;
            bufferSize = _size;
        }

        bool MemoryFile::openRB() {
            if(openedRB || openedWB) close();
            openedRB = true;
            pos = 0;

            return true;
        }

        bool MemoryFile::close() {
            openedRB = false;
            openedWB = false;
            pos = 0;

            return true;
        }

        void MemoryFile::reallocBuffer() {
            buffer = (void*) realloc(buffer, bufferSize);
        }

        std::streamsize MemoryFile::read(void *ptr, std::streamsize size, std::streamsize count) {
            if(openedRB) {
                std::streamsize readSize = count * size;
                std::streamsize restBytes = bufferSize - pos;

                if(!restBytes) return 0;

                if(readSize > restBytes)
                    readSize = restBytes;

                memcpy(ptr, ((char*)buffer)+pos, readSize);

                pos += readSize;
                return readSize;
            }

            return 0;
        }

        std::streamsize MemoryFile::write(const void *ptr, std::streamsize size, std::streamsize count) {
            if(openedWB) {
                std::streamsize copySize = count * size;
                bufferSize += copySize;
                reallocBuffer();

                memcpy(((char*)buffer)+pos, ptr, copySize);
                pos += copySize;

                return copySize;
            }

            return 0;
        }

        int MemoryFile::seek(long offset, int origin) {
            switch(origin) {
                case SEEK_CUR:
                    pos += offset;
                    break;
                case SEEK_END:
                    pos = bufferSize - offset;
                    break;
                case SEEK_SET:
                    pos = offset;
                    break;
            }

            if(pos < 0) {
                pos = 0;
                return -1;
            }

            if(pos > bufferSize) {
                pos = bufferSize;
                return -1;
            }

            return 0;
        }

        long MemoryFile::tell() {
            return pos;
        }

        long MemoryFile::getFilesize() {
            return bufferSize;
        }

        bool MemoryFile::isEof() {
            if(pos >= bufferSize) return true;
            else return false;
        }

        MemoryFile *MemoryFile::createFromFilePath(std::string filepath) {
            MemoryFile *bf = new MemoryFile();

            std::ifstream file;
            file.open(filepath.c_str(), std::ifstream::in | std::ifstream::ate | std::ifstream::binary);

            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);

            char *buffer = (char *) malloc(size);
            file.read(buffer, size);

            bf->setBuffer(buffer, size);
            bf->reallocBuffer();

            return bf;
        }
    }
}

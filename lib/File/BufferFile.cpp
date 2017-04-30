#include <File/BufferFile.h>

#include <stdlib.h>
#include <stdexcept>
#include <fstream>
#include <iostream>

namespace Library {
    namespace File {
        BufferFile::BufferFile() : File() {
            bufferSize = 0;
            buffer = (void*) malloc(bufferSize);
        }

        bool BufferFile::openWB() {
            if(openedRB || openedWB) close();
            openedWB = true;
            pos = 0;

            return true;
        }

        void BufferFile::setBuffer(void *_buffer, long _size) {
            buffer = _buffer;
            bufferSize = _size;
        }

        bool BufferFile::openRB() {
            if(openedRB || openedWB) close();
            openedRB = true;
            pos = 0;

            return true;
        }

        bool BufferFile::close() {
            openedRB = false;
            openedWB = false;
            pos = 0;

            return true;
        }

        void BufferFile::reallocBuffer() {
            buffer = (void*) realloc(buffer, bufferSize);
        }

        std::streamsize BufferFile::read(void *ptr, std::streamsize size, std::streamsize count) {
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

        std::streamsize BufferFile::write(const void *ptr, std::streamsize size, std::streamsize count) {
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

        int BufferFile::seek(long offset, int origin) {
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

        long BufferFile::tell() {
            return pos;
        }

        bool BufferFile::canSeekInFile() {
            return true;
        }

        long BufferFile::getFilesize() {
            return bufferSize;
        }

        bool BufferFile::canWrite() {
            return true;
        }

        bool BufferFile::isEof() {
            if(pos >= bufferSize) return true;
            else return false;
        }

        BufferFile *BufferFile::createFromFilePath(std::string filepath) {
            BufferFile *bf = new BufferFile();

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

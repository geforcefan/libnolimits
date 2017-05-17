#include "NormalFile.h"

namespace NoLimits {
    namespace File {
        bool NormalFile::openWB() {
            filePtr = fopen(getFilepath().c_str(), "wb");

            if(filePtr) {
                openedWB = true;
                openedRB = false;
                return filePtr != 0 ? true : false;
            } else {
                return false;
            }
        }

        bool NormalFile::openRB() {
            filePtr = fopen(getFilepath().c_str(), "rb");

            if(filePtr) {
                openedRB = true;
                openedWB = false;
                return filePtr != 0 ? true : false;
            } else {
                return false;
            }
        }


        std::streamsize NormalFile::write(const void* ptr, std::streamsize size, std::streamsize count) {
            if(filePtr) {
                return fwrite(ptr, size, count, filePtr) ? true : false;
            } else return false;
        }

        std::streamsize NormalFile::read(void* ptr, std::streamsize size, std::streamsize count) {
            if(filePtr) {
                return fread(ptr, size, count, filePtr);
            } else return false;
        }

        bool NormalFile::isEof() {
            return feof(filePtr) ? true : false;
        }

        int NormalFile::seek(long offset, int origin) {
            if(filePtr) {
                return fseek(filePtr, offset, origin);
            } else return false;
        }

        long NormalFile::tell() {
            if(filePtr) {
                return ftell(filePtr);
            } else return -1L;
        }

        int NormalFile::flush() {
            if(filePtr) {
                return fflush(filePtr);
            } else return 0;
        }

        long NormalFile::getFilesize() {
            FILE *pFile = nullptr;
            pFile = fopen(getFilepath().c_str(), "rb");

            if(pFile) {
                fseek(pFile, 0, SEEK_END);
                long size = ftell(pFile);
                fclose(pFile);
                return size;
            } else return 0;
        }

        bool NormalFile::close() {
            if(filePtr) {
                openedWB = false;
                openedRB = false;

                fclose(filePtr);
                filePtr = 0;

                return true;
            }

            return false;
        }

        NormalFile::~NormalFile() {
            if(filePtr) {
                fclose(filePtr);
            }
        }
    }
}

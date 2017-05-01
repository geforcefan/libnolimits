#include "File.h"
#include "BufferFile.h"
#include <iostream>
#include <zlib.h>

#define ZLIB_CHUNK 16384

namespace NoLimits {
    namespace File {
        File::File() {
            openedWB = false;
            openedRB = false;
        }

        bool File::isOpenedRB() const {
            return openedRB;
        }

        bool File::isOpenedWB() const {
            return openedWB;
        }

        void File::readNull(long count) {
            seek(count, SEEK_CUR);
        }

        void File::writeNull(long count) {
            char *buffer = (char*) malloc(count);
            memset(buffer, 0, count);

            write(&buffer[0], count, 1);
        }

        bool File::readBoolean() {
            bool buffer;
            read(&buffer, 1, 1);

            return buffer;
        }

        void File::writeBoolean(bool value) {
            write(&value, 1, 1);
        }

        float File::readFloat() {
            float floatBuffer;
            read(&floatBuffer, 4, 1);
            floatBuffer = be2Host(floatBuffer);

            return floatBuffer;
        }

        void File::writeFloat(float value) {
            value = be2Host(value);
            write(&value, 4, 1);
        }

        double File::readDouble() {
            double doubleBuffer;
            read(&doubleBuffer, 8, 1);
            doubleBuffer = be2Host(doubleBuffer);

            return doubleBuffer;
        }

        void File::writeDouble(double value) {
            value = be2Host(value);
            write(&value, 8, 1);
        }

        uint16_t File::readUnsignedShort() {
            uint16_t shortBuffer;
            read(&shortBuffer, 2, 1);
            shortBuffer = be2Host(shortBuffer);

            return shortBuffer;
        }

        void File::writeUnsignedShort(uint16_t value) {
            value = be2Host(value);
            write(&value, 2, 1);
        }

        uint32_t File::readUnsignedInteger() {
            uint32_t intBuffer;
            read(&intBuffer, 4, 1);
            intBuffer = be2Host(intBuffer);

            return intBuffer;
        }

        void File::writeUnsignedInteger(uint32_t value) {
            value = be2Host(value);
            write(&value, 4, 1);
        }

        uint8_t File::readUnsigned8() {
            uint8_t u8Buffer;
            read(&u8Buffer, 1, 1);

            return u8Buffer;
        }

        void File::writeUnsigned8(uint8_t value) {
            write(&value, 1, 1);
        }

        int File::readInteger() {
            int intBuffer;
            read(&intBuffer, 4, 1);
            intBuffer = be2Host(intBuffer);

            return intBuffer;
        }

        void File::writeInteger(int value) {
            value = be2Host(value);
            write(&value, 4, 1);
        }

        glm::vec3 File::readColor() {
            return readUnsigned8Vec3();
        }

        void File::writeColor(glm::vec3 color) {
            return writeUnsigned8Vec3(color);
        }

        glm::vec2 File::readIntVec2() {
            return glm::vec2(readInteger(), readInteger());
        }

        void File::writeIntVec2(glm::vec2 vec) {
            writeInteger(vec.x);
            writeInteger(vec.y);
        }

        glm::vec2 File::readFloatVec2() {
            return glm::vec2(readFloat(), readFloat());
        }

        void File::writeFloatVec2(glm::vec2 vec) {
            writeFloat(vec.x);
            writeFloat(vec.y);
        }

        glm::vec3 File::readFloatVec3() {
            return glm::vec3(readFloat(), readFloat(), readFloat());
        }

        void File::writeFloatVec3(glm::vec3 vec) {
            writeFloat(vec.x);
            writeFloat(vec.y);
            writeFloat(vec.z);
        }

        glm::vec3 File::readUnsigned8Vec3() {
            return glm::vec3(readUnsigned8(), readUnsigned8(), readUnsigned8());
        }

        void File::writeUnsigned8Vec3(glm::vec3 vec) {
            writeUnsigned8(vec.x);
            writeUnsigned8(vec.y);
            writeUnsigned8(vec.z);
        }

        glm::vec2 File::readDoubleVec2() {
            return glm::vec2(readDouble(), readDouble());
        }

        void File::writeDoubleVec2(glm::vec2 vec) {
            writeDouble(vec.x);
            writeDouble(vec.y);
        }

        glm::vec4 File::readDoubleVec4() {
            return glm::vec4(readDouble(), readDouble(), readDouble(), readDouble());
        }

        void File::writeDoubleVec4(glm::vec4 vec) {
            writeDouble(vec.x);
            writeDouble(vec.y);
            writeDouble(vec.z);
            writeDouble(vec.w);
        }

        std::string File::readChunkName() {
            std::string chunkName(4, '\0');
            read(&chunkName[0], sizeof(char), 4);

            return Helper::trim(chunkName);
        }

        void File::writeChunkName(std::string chunkName) {
            write(chunkName.data(), sizeof(char), 4);
        }

        void File::writeFile(File *file) {
            file->openRB();

            char *buffer = (char*) malloc(file->getFilesize());
            file->read(&buffer[0], 1, file->getFilesize());
            file->close();

            write(&buffer[0], 1, file->getFilesize());
        }

        File *File::readCompressedFile() {
            readUnsignedInteger(); // uncompressedSize
            uint32_t compressedSize = readUnsignedInteger();

            char *compressedData = (char*) malloc(compressedSize);
            read(&compressedData[0], 1, compressedSize);

            BufferFile *compressedDataBufferFile = new BufferFile();
            compressedDataBufferFile->setBuffer(compressedData, compressedSize);
            compressedDataBufferFile->openRB();

            BufferFile *decompressedDataBufferFile = new BufferFile();
            decompressedDataBufferFile->openWB();

            z_stream strm;
            unsigned have;
            int ret;

            unsigned char in[ZLIB_CHUNK];
            unsigned char out[ZLIB_CHUNK];

            strm.zalloc = Z_NULL;
            strm.zfree = Z_NULL;
            strm.opaque = Z_NULL;
            strm.avail_in = 0;
            strm.next_in = Z_NULL;

            ret = inflateInit2(&strm, 15);

            if (ret == Z_OK) {
                do {
                    strm.avail_in = compressedDataBufferFile->read(in, 1, ZLIB_CHUNK);

                    if (strm.avail_in == 0)
                        break;
                    strm.next_in = in;

                    do {
                        strm.avail_out = ZLIB_CHUNK;
                        strm.next_out = out;
                        ret = inflate(&strm, Z_NO_FLUSH);

                        switch (ret) {
                            case Z_NEED_DICT:
                                ret = Z_DATA_ERROR;
                            case Z_DATA_ERROR:
                            case Z_MEM_ERROR:
                                (void)inflateEnd(&strm);

                                compressedDataBufferFile->close();
                                decompressedDataBufferFile->close();

                                return decompressedDataBufferFile;
                                break;
                        }

                        have = ZLIB_CHUNK - strm.avail_out;
                        decompressedDataBufferFile->write(out, 1, have);
                    } while (strm.avail_out == 0);
                } while (ret != Z_STREAM_END);
            }

            compressedDataBufferFile->close();
            decompressedDataBufferFile->close();

            return decompressedDataBufferFile;
        }

        void File::writeFileCompressed(File *uncompressedFile) {
            File *compressedFile = new BufferFile();

            uncompressedFile->openRB();
            compressedFile->openWB();

            z_stream strm;
            unsigned have;
            int ret;

            unsigned char in[ZLIB_CHUNK];
            unsigned char out[ZLIB_CHUNK];

            strm.zalloc = Z_NULL;
            strm.zfree = Z_NULL;
            strm.opaque = Z_NULL;

            strm.avail_in = 0;
            strm.next_in = Z_NULL;

            ret = deflateInit(&strm, Z_BEST_COMPRESSION);

            if (ret == Z_OK) {
                do {
                    strm.avail_in = uncompressedFile->read(in, 1, ZLIB_CHUNK);

                    if (strm.avail_in == 0)
                        break;
                    strm.next_in = in;

                    do {
                        strm.avail_out = ZLIB_CHUNK;
                        strm.next_out = out;

                        if(strm.avail_in < ZLIB_CHUNK)
                            ret = deflate(&strm, Z_FINISH);
                        else
                            ret = deflate(&strm, Z_NO_FLUSH);

                        switch (ret) {
                            case Z_NEED_DICT:
                                ret = Z_DATA_ERROR;
                            case Z_DATA_ERROR:
                            case Z_MEM_ERROR:
                                (void)inflateEnd(&strm);

                                compressedFile->close();
                                uncompressedFile->close();
                                return;
                                break;
                        }

                        have = ZLIB_CHUNK - strm.avail_out;
                        compressedFile->write(out, 1, have);
                    } while (strm.avail_out == 0);
                } while (ret != Z_STREAM_END);
            }

            uncompressedFile->close();
            compressedFile->close();

            writeUnsignedInteger(uncompressedFile->getFilesize());
            writeUnsignedInteger(compressedFile->getFilesize());
            writeFile(compressedFile);
        }

        File *File::getChunkBufferFile() {
            uint32_t chunkSize = readUnsignedInteger();

            char *chunkBuffer = (char*) malloc(chunkSize + 4);

            seek(-4, SEEK_CUR);
            read(&chunkBuffer[0], chunkSize + 4, 1);

            BufferFile *bufferFile = new BufferFile();
            bufferFile->setBuffer(chunkBuffer, chunkSize + 4);

            return bufferFile;
        }

        std::string File::readString() {
            bool terminated = false;
            std::string str;

            while (!terminated) {
                char buffer[2];
                read(&buffer[0], 1, 2);
                char c = buffer[1];

                if (c == 0) {
                    terminated = true;
                } else {
                    str.append(1, c);
                }
            }

            return str;
        }

        void File::writeString(std::string value) {
            for(unsigned long i = 0; i < value.size(); i++) {
                writeNull(1);
                write(&value[i], sizeof(char), 1);
            }
            writeNull(2);
        }

        template <typename T>
        T File::bswap(T val) {
            T retVal;
            char *pVal = (char*) &val;
            char *pRetVal = (char*)&retVal;
            int size = sizeof(T);
            for(int i=0; i<size; i++) {
                pRetVal[size-1-i] = pVal[i];
            }

            return retVal;
        }

        template <typename T>
        T File::be2Host(T val) {
        #ifdef __BIG_ENDIAN__
            return val;
        #else
            return bswap(val);
        #endif
        }

        template <typename T>
        T File::host2Be(T val) {
        #ifdef __BIG_ENDIAN__
            return val;
        #else
            return bswap(val);
        #endif
        }

        template <typename T>
        T File::le2Host(T val) {
        #ifdef __BIG_ENDIAN__
            return bswap(val);
        #else
            return val;
        #endif
        }
        template <typename T>
        T File::host2Le(T val) {
        #ifdef __BIG_ENDIAN__
            return bswap(val);
        #else
            return val;
        #endif
        }
    }
}

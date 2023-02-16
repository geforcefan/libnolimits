#ifndef LIB_FILE_FILE_H
#define LIB_FILE_FILE_H

#include <cstddef>
#include <cstring>
#include <fstream>

#include <stdint.h>
#include "../Nolimits.h"

namespace NoLimits {
    namespace Stream {
        class Chunk;
    }

    /*! \cond INTERNAL */
    namespace File {
        class File
        {
        public:
            File(std::string _filepath) : filepath(_filepath) {
                openedWB = false;
                openedRB = false;
            }

            File() {
                openedWB = false;
                openedRB = false;
            }

            /**
             * Open file in write binary mode
             *
             * @return success
             */
            virtual bool openWB() { return false; }

            /**
             * Open file in read binary mode
             *
             * @return success
             */
            virtual bool openRB() { return false; }

            /**
             * Write block of data to stream
             *
             * @param ptr Pointer to the array of elements to be written, converted to a const void*
             * @param size Size in bytes of each element to be written
             * @param count Number of elements, each one with a size of size bytes
             *
             * @return The total number of elements successfully written is returned
             */
            virtual std::streamsize write(const void * ptr, std::streamsize size, std::streamsize count) { return 0; }

            /**
             * Read block of data from stream
             *
             * @param ptr Pointer to a block of memory with a size of at least (size*count) bytes, converted to a void*
             * @param size Size, in bytes, of each element to be read
             * @param count Number of elements, each one with a size of size bytes
             *
             * @return The total number of elements successfully read is returned
             */
            virtual std::streamsize read (void * ptr, std::streamsize size, std::streamsize count) { return 0; }

            /**
             * Closes the file
             *
             * @return If the stream is successfully closed, a true value is returned.
             */
            virtual bool close() { return false; }

            /**
             * Checks whether the end-of-File indicator, returning a value different from false if it is
             *
             * @return A non-false value is returned in the case that the end-of-file indicator
             */
            virtual bool isEof() { return false; }

            /**
             * Sets the position indicator associated with the stream to a new position
             *
             * @param offset Number of bytes to offset from origin
             * @param origin Position used as reference for the offset
             */
            virtual int seek(long offset, int origin) { return 0; }

            /**
             * Returns the current value of the position indicator
             *
             * @return On success, the current value of the position indicator is returned
             */
            virtual long tell() { return false; }

            /**
             * Rested file
             *
             * @return A zero value indicates success
             */
            virtual int flush() { return false; }

            /**
             * Is file opened in write binary mode
             *
             * @return A true value in the case that the file is opened in write binary mode
             */
            bool isOpenedWB() const;

            /**
             * Is file opened in read binary mode
             *
             * @return A true value in the case that the file is opened in read binary mode
             */
            bool isOpenedRB() const;

            /**
             * Gets file size
             *
             * @return File size
             */
            virtual long getFilesize() { return 0; }

            /**
             * Reads unsigned short value from file.
             *
             * @return Read unsigned short value from file
             */
            uint16_t readUnsignedShort();

            /**
             * Writes unsigned short value to file.
             *
             * @param value Value to be written
             */
            void writeUnsignedShort(uint16_t value);

            /**
             * Reads unsigned integer value from file.
             *
             * @return Read unsigned integer value from file
             */
            uint32_t readUnsignedInteger();

            /**
             * Writes unsigned integer value to file.
             *
             * @param value Value to be written
             */
            void writeUnsignedInteger(uint32_t value);

            /**
             * Reads unsigned byte from file.
             *
             * @return Read byte integer value from file
             */
            uint8_t readUnsigned8();

            /**
             * Writes unsigned byte to file.
             *
             * @param value Value to be written
             */
            void writeUnsigned8(uint8_t value);

            /**
             * Reads integer value from file.
             *
             * @return Read integer value from file
             */
            int readInteger();

            /**
             * Writes integer value to file.
             *
             * @param value Value to be written
             */
            void writeInteger(int value);

            /**
             * Skips reading n count of bytes.
             *
             * @param count n count of bytes to skip
             */
            void readNull(long count);

            /**
             * Writes n count of null bytes to file.
             *
             * @param count n count of null bytes
             */
            void writeNull(long count);

            /**
             * Reads float value from file.
             *
             * @return Read float value from file
             */
            float readFloat();

            /**
             * Writes float value to file.
             *
             * @param value Value to be written
             */
            void writeFloat(float value);

            /**
             * Reads double value from file.
             *
             * @return Read double value from file
             */
            double readDouble();

            /**
             * Writes double value to file.
             *
             * @param value Value to be written
             */
            void writeDouble(double value);

            /**
             * Reads boolean value from file.
             *
             * @return Read boolean value from file
             */
            bool readBoolean();

            /**
             * Writes boolean value to file.
             *
             * @param value Value to be written
             */
            void writeBoolean(bool value);

            /**
             * Reads legacy boolean value from file. NoLimits 1 files are legacy
             *
             * @return Read boolean value from file
             */
            bool readBooleanLegacy();

            /**
             * Writes legacy boolean value to file. NoLimits 1 files are legacy
             *
             * @param value Value to be written
             */
            void writeBooleanLegacy(bool value);

            /**
             * Reads legacy color value from file. NoLimits 1 files are legacy.
             * Colors are stored in RGB (0-255) as bytes
             *
             * @return Read color value from file
             */
            glm::vec3 readColorLegacy();

            /**
             * Writes legacy color value to file. NoLimits 1 files are legacy.
             * Colors are stored in RGB (0-255) as bytes
             *
             * @param value Value to be written
             */
            void writeColorLegacy(glm::vec3 color);

            /**
             * Reads color value from file.
             * Colors are stored in RGB (0-255) as bytes
             *
             * @return Read color value from file
             */
            glm::vec3 readColor();

            /**
             * Writes color value to file.
             * Colors are stored in RGB (0-255) as bytes
             *
             * @param value Value to be written
             */
            void writeColor(glm::vec3 color);

            /**
             * Reads 2D integer vector value from file
             *
             * @return Read 2D integer vector value from file
             */
            glm::vec2 readIntVec2();

            /**
             * Writes 2D integer vector value to file.
             *
             * @param value Value to be written
             */
            void writeIntVec2(glm::vec2 vec);

            /**
             * Reads 2D float vector value from file
             *
             * @return Read 2D float vector value from file
             */
            glm::vec2 readFloatVec2();

            /**
             * Writes 2D float vector value to file.
             *
             * @param value Value to be written
             */
            void writeFloatVec2(glm::vec2 vec);

            /**
             * Reads 2D double vector value from file
             *
             * @return Read 2D double vector value from file
             */
            glm::dvec2 readDoubleVec2();

            /**
             * Writes 2D double vector value to file.
             *
             * @param value Value to be written
             */
            void writeDoubleVec2(glm::dvec2 vec);

            /**
             * Reads 3D unsigned byte vector value from file
             *
             * @return Read 3D unsigned byte vector value from file
             */
            glm::vec3 readUnsigned8Vec3();

            /**
             * Writes 4D unsigned byte vector value to file.
             *
             * @param value Value to be written
             */
            void writeUnsigned8Vec4(glm::vec4 vec);

            /**
             * Reads 4D unsigned byte vector value from file
             *
             * @return Read 4D unsigned byte vector value from file
             */
            glm::vec4 readUnsigned8Vec4();

            /**
             * Writes 3D unsigned byte vector value to file.
             *
             * @param value Value to be written
             */
            void writeUnsigned8Vec3(glm::vec3 vec);

            /**
             * Reads 3D float vector value from file
             *
             * @return Read 3D float vector value from file
             */
            glm::vec3 readFloatVec3();

            /**
             * Writes 3D float vector value to file.
             *
             * @param value Value to be written
             */
            void writeFloatVec3(glm::vec3 vec);

            /**
             * Reads 3D double vector value from file
             *
             * @return Read 3D double vector value from file
             */
            glm::dvec3 readDoubleVec3();

            /**
             * Writes 3D double vector value to file.
             *
             * @param value Value to be written
             */
            void writeDoubleVec3(glm::dvec3 vec);

            /**
             * Reads 4D double vector value from file
             *
             * @return Read 4D double vector value from file
             */
            glm::dvec4 readDoubleVec4();

            /**
             * Writes 4D double vector value to file.
             *
             * @param value Value to be written
             */
            void writeDoubleVec4(glm::dvec4 vec);

            /**
             * Reads string value from file
             *
             * @return Read string value from file
             */
            std::string readString();

            /**
             * Writes string value to file.
             *
             * @param value Value to be written
             */
            void writeString(std::string value);

            /**
             * Reads legacy string value from file. NoLimits 1 files are legacy
             *
             * @return Read string value from file
             */
            std::string readStringLegacy();

            /**
             * Writes legacy string value to file. NoLimits 1 files are legacy
             *
             * @param value Value to be written
             */
            void writeStringLegacy(std::string value);

            std::string readChunkName();
            void writeChunkName(std::string chunkName);

            void writeFile(File *file);

            File *readCompressedFile();
            void writeFileCompressed(File *uncompressedFile);

            void readChunk(Stream::Chunk *chunk);
            void writeChunk(Stream::Chunk *chunk);

            std::string getFilepath() const;
            void setFilepath(const std::string &value);
        protected:
            bool openedWB;
            bool openedRB;

            template <typename T> T bswap(T val);
            template <typename T> T be2Host(T val);
            template <typename T> T host2Be(T val);
            template <typename T> T le2Host(T val);
            template <typename T> T host2Le(T val);

        private:
            std::string filepath;
        };
    }
    /*! \endcond */
}

#endif

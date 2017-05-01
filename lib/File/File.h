#ifndef LIB_FILE_FILE_H
#define LIB_FILE_FILE_H

#include <cstddef>
#include <cstring>
#include <fstream>

#include <stdint.h>
#include <nolimits.h>

namespace NoLimits {
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

            virtual bool openWB() { return false; }
            virtual bool openRB() { return false; }

            virtual std::streamsize write(const void * ptr, std::streamsize size, std::streamsize count) { return 0; }
            virtual std::streamsize read (void * ptr, std::streamsize size, std::streamsize count) { return 0; }

            virtual bool close() { return false; }

            virtual bool isEof() { return false; }
            virtual int seek(long offset, int origin) { return 0; }
            virtual long tell() { return false; }
            virtual int flush() { return false; }

            bool isOpenedWB() const;
            bool isOpenedRB() const;

            virtual long getFilesize() { return 0; }

            uint16_t readUnsignedShort();
            void writeUnsignedShort(uint16_t value);

            uint32_t readUnsignedInteger();
            void writeUnsignedInteger(uint32_t value);

            uint8_t readUnsigned8();
            void writeUnsigned8(uint8_t value);

            int readInteger();
            void writeInteger(int value);

            void readNull(long count);
            void writeNull(long count);

            float readFloat();
            void writeFloat(float value);

            double readDouble();
            void writeDouble(double value);

            bool readBoolean();
            void writeBoolean(bool value);

            glm::vec3 readColor();
            void writeColor(glm::vec3 color);

            glm::vec2 readIntVec2();
            void writeIntVec2(glm::vec2 vec);

            glm::vec2 readFloatVec2();
            void writeFloatVec2(glm::vec2 vec);

            glm::vec2 readDoubleVec2();
            void writeDoubleVec2(glm::vec2 vec);

            glm::vec3 readUnsigned8Vec3();
            void writeUnsigned8Vec3(glm::vec3 vec);

            glm::vec3 readFloatVec3();
            void writeFloatVec3(glm::vec3 vec);

            glm::vec4 readDoubleVec4();
            void writeDoubleVec4(glm::vec4 vec);

            std::string readString();
            void writeString(std::string value);

            std::string readChunkName();
            void writeChunkName(std::string chunkName);

            void writeFile(File *file);

            File *readCompressedFile();
            void writeFileCompressed(File *uncompressedFile);

            File *getChunkMemoryFile();

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
}

#endif

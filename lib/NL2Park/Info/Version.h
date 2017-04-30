#ifndef LIB_NL2PARK_VERSION_H
#define LIB_NL2PARK_VERSION_H

#include <string>
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Version: public Stream::Chunk {
        public:
            void read(File::File *file);
            void write(File::File *file);

            uint16_t getMajor() const;
            void setMajor(const uint16_t &value);

            uint16_t getMinor() const;
            void setMinor(const uint16_t &value);

            uint16_t getRevision() const;
            void setRevision(const uint16_t &value);

            uint16_t getBuild() const;
            void setBuild(const uint16_t &value);

        private:
            uint16_t major;
            uint16_t minor;
            uint16_t revision;
            uint16_t build;
        };
    }
}

#endif

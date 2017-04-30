#ifndef LIB_NL2PARK_USPK_H
#define LIB_NL2PARK_USPK_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Uspk: public Stream::Chunk {
        public:
            Uspk() {}

            void read(File::File *file);
            void write(File::File *file);
        protected:
            std::string getChunkName() { return "USPK"; }
        };
    }
}

#endif // LIB_NL2PARK_USPK_H

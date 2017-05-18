#ifndef LIB_NL2PARK_SPPM_H
#define LIB_NL2PARK_SPPM_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class SPPM : public Stream::Chunk {
        public:
            SPPM() {}

            void read(File::File *file);
            void write(File::File *file);

            float getUnknown() const;
            void setUnknown(float value);

            std::string getChunkName() { return "SPPM"; }
        private:
            float unknown;
        };
    }
}

#endif // LIB_NL2PARK_SPPM_H

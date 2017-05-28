#ifndef LIB_NOLIMITS_NL1_VERSION_H
#define LIB_NOLIMITS_NL1_VERSION_H

#include "../../Nolimits.h"
#include "../../Stream/Chunk.h"
#include <string>
#include <ostream>

namespace NoLimits {
    namespace NoLimits1 {
        class Version: public Stream::Chunk {
        public:
            void debug() {
                std::cout << "Version[getMajor]: " << ((int)getMajor()) << std::endl;
                std::cout << "Version[getMinor]: " << ((int)getMinor()) << std::endl;
                std::cout << "Version[getRevision]: " << ((int)getRevision()) << std::endl;
                std::cout << "Version[getMarkup]: " << ((int)getMarkup()) << std::endl;
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            uint8_t getMajor() const;
            void setMajor(const uint8_t &value);

            uint8_t getMinor() const;
            void setMinor(const uint8_t &value);

            uint8_t getRevision() const;
            void setRevision(const uint8_t &value);

            uint8_t getMarkup() const;
            void setMarkup(const uint8_t &value);

        private:
            uint8_t major;
            uint8_t minor;
            uint8_t revision;
            uint8_t markup;
        };
    }
}

#endif

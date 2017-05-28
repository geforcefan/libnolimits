#ifndef LIB_NOLIMITS_NL1_INFO_H
#define LIB_NOLIMITS_NL1_INFO_H

#include "../../Nolimits.h"
#include "../../Stream/Chunk.h"
#include <string>
#include <ostream>

namespace NoLimits {
    namespace NoLimits1 {
        class Info: public Stream::Chunk {
        public:
            void debug() {
                std::cout << "Info[getDescription]: " << getDescription() << std::endl;
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            std::string getChunkName() { return "INFO"; }

            const std::string &getDescription() const;
            void setDescription(const std::string &value);

        private:
            std::string description;
        };
    }
}

#endif

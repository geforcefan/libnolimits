#ifndef LIB_NL2PARK_RESOURCEFILE_H
#define LIB_NL2PARK_RESOURCEFILE_H

#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class ResourceFile: public Stream::Chunk {
        public:
            ResourceFile() {
                setId("");
                setPath("");
            }

            void debug() {
                std::cout << "Script[getId]: " << getId() << std::endl;
                std::cout << "Script[getPath]: " << getPath() << std::endl;
            }

            void read(File::File *file);
            void write(File::File *file);

            std::string getId() const;
            void setId(const std::string &value);

            std::string getPath() const;
            void setPath(const std::string &value);

        private:
            std::string id;
            std::string path;
        };
    }
}

#endif // LIB_NL2PARK_RESOURCEFILE_H

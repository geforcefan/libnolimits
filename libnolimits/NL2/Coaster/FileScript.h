#ifndef LIB_NL2PARK_FILESCRIPT_H
#define LIB_NL2PARK_FILESCRIPT_H

#include "../../Stream/Chunk.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
        class FileScript: public Stream::Chunk {
        public:
            FileScript() {}

            void debug() {
                std::cout << "FileScript[path.size]: " << path.size() << std::endl;
                if(path.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < path.size(); i++) {
                    std::cout << "FileScript[path][" << i << "]: " << path[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            std::vector<std::string> getPath() const;
            uint32_t insertPath(std::string value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "FSCR"; }
            /*! \endcond */
        private:
            std::vector<std::string> path;
        };
    }
}

#endif // LIB_NL2PARK_FILESCRIPT_H

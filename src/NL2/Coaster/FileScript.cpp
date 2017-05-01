#include <src/NL2/Coaster/FileScript.h>
#include <iostream>

namespace NoLimits {
    namespace NL2 {
        void FileScript::read(File::File *file) {
            path.clear();

            uint32_t numberOfPaths = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfPaths; i++) {
                insertPath(file->readString());
                file->readNull(8);
            }

            file->readNull(8);
        }

        void FileScript::write(File::File *file) {
            file->writeUnsignedInteger(path.size());
            for(uint32_t i = 0; i < path.size(); i++) {
                file->writeString(path[i]);
                file->writeNull(8);
            }

            file->writeNull(8);
        }

        std::vector<std::string> FileScript::getPath() const {
            return path;
        }

        void FileScript::insertPath(std::string value) {
            path.push_back(value);
        }
    }
}

#include "ResourceFile.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void ResourceFile::read(File::File *file) {
            setId(file->readString());
            setPath(file->readString());
        }

        void ResourceFile::write(File::File *file) {
            file->writeString(getId());
            file->writeString(getPath());
        }

        std::string ResourceFile::getId() const {
            return id;
        }

        void ResourceFile::setId(const std::string &value) {
            id = value;
        }

        std::string ResourceFile::getPath() const {
            return path;
        }

        void ResourceFile::setPath(const std::string &value) {
            path = value;
        }
    }
}

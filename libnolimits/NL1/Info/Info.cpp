#include "Info.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Info::read(File::File *file) {
            file->readNull(16);
            setDescription(file->readStringLegacy());
            file->readNull(4); // sub chunk size
        }

        void Info::write(File::File *file) {
            file->writeNull(16);
            file->writeStringLegacy(getDescription());
            file->writeUnsignedInteger(0); // sub chunk size
        }

        const std::string &Info::getDescription() const {
            return description;
        }

        void Info::setDescription(const std::string &value) {
            description = value;
        }
    }
}

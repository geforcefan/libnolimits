#include "Version.h"
#include <iostream>
namespace NoLimits {
    namespace NoLimits1 {
        void Version::read(File::File *file) {
            setMajor(file->readUnsigned8());
            setMinor(file->readUnsigned8());
            setRevision(file->readUnsigned8());
            setMarkup(file->readUnsigned8());
        }

        void Version::write(File::File *file) {
            // we always write the nltrack version which this library supports
            file->writeUnsigned8(NLTRACK_VERSION_MAJOR);
            file->writeUnsigned8(NLTRACK_VERSION_MINOR);
            file->writeUnsigned8(NLTRACK_VERSION_REVISION);
            file->writeUnsigned8(NLTRACK_VERSION_MARKUP);

            major = NLTRACK_VERSION_MAJOR;
            minor = NLTRACK_VERSION_MINOR;
            revision = NLTRACK_VERSION_REVISION;
            markup = NLTRACK_VERSION_MARKUP;
        }

        uint8_t Version::getMajor() const {
            return major;
        }

        void Version::setMajor(const uint8_t &value) {
            major = value;
        }

        uint8_t Version::getMinor() const {
            return minor;
        }

        void Version::setMinor(const uint8_t &value) {
            minor = value;
        }

        uint8_t Version::getRevision() const {
            return revision;
        }

        void Version::setRevision(const uint8_t &value) {
            revision = value;
        }

        uint8_t Version::getMarkup() const {
            return markup;
        }

        void Version::setMarkup(const uint8_t &value) {
            markup = value;
        }
    }
}

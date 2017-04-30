#include "Version.h"
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Version::read(File::File *file) {
            setMajor(file->readUnsigned8());
            setMinor(file->readUnsigned8());
            setRevision(file->readUnsigned8());
            setBuild(file->readUnsigned8());
        }

        void Version::write(File::File *file) {
            // we always write the n2park version which this library supports
            file->writeUnsigned8(NL2PARK_VERSION_MAJOR);
            file->writeUnsigned8(NL2PARK_VERSION_MINOR);
            file->writeUnsigned8(NL2PARK_VERSION_REVISION);
            file->writeUnsigned8(NL2PARK_VERSION_BUILD);

            major = NL2PARK_VERSION_MAJOR;
            minor = NL2PARK_VERSION_MINOR;
            revision = NL2PARK_VERSION_REVISION;
            build = NL2PARK_VERSION_BUILD;
        }

        uint16_t Version::getMajor() const {
            return major;
        }

        void Version::setMajor(const uint16_t &value) {
            major = value;
        }

        uint16_t Version::getMinor() const {
            return minor;
        }

        void Version::setMinor(const uint16_t &value) {
            minor = value;
        }

        uint16_t Version::getRevision() const {
            return revision;
        }

        void Version::setRevision(const uint16_t &value) {
            revision = value;
        }

        uint16_t Version::getBuild() const {
            return build;
        }

        void Version::setBuild(const uint16_t &value) {
            build = value;
        }
    }
}

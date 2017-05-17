#include "BeamConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        void BeamConnection::read(File::File *file) {
            setType((BeamConnection::Type)file->readUnsignedInteger());
            setIndex(file->readUnsignedInteger());
            setIndexOnBeam(file->readUnsignedInteger());
            setIndexOnRailConnector(file->readUnsignedInteger());
        }

        void BeamConnection::write(File::File *file) {
            file->writeUnsignedInteger(getType());
            file->writeUnsignedInteger(getIndex());
            file->writeUnsignedInteger(getIndexOnBeam());
            file->writeUnsignedInteger(getIndexOnRailConnector());
        }

        BeamConnection::Type BeamConnection::getType() const {
            return type;
        }

        void BeamConnection::setType(const BeamConnection::Type &value) {
            type = value;
        }

        uint32_t BeamConnection::getIndex() const {
            return index;
        }

        void BeamConnection::setIndex(const uint32_t &value) {
            index = value;
        }

        uint32_t BeamConnection::getIndexOnBeam() const {
            return indexOnBeam;
        }

        void BeamConnection::setIndexOnBeam(const uint32_t &value) {
            indexOnBeam = value;
        }

        uint32_t BeamConnection::getIndexOnRailConnector() const {
            return indexOnRailConnector;
        }

        void BeamConnection::setIndexOnRailConnector(const uint32_t &value) {
            indexOnRailConnector = value;
        }
    }
}

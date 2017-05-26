#include "BeamConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        void BeamConnection::read(File::File *file) {
            setType((BeamConnection::Type)file->readUnsignedInteger());
            setIndex1(file->readUnsignedInteger());
            setIndex2(file->readUnsignedInteger());
            setIndex3(file->readUnsignedInteger());
        }

        void BeamConnection::write(File::File *file) {
            file->writeUnsignedInteger(getType());
            file->writeUnsignedInteger(getIndex1());
            file->writeUnsignedInteger(getIndex2());
            file->writeUnsignedInteger(getIndex3());
        }

        BeamConnection::Type BeamConnection::getType() const {
            return type;
        }

        void BeamConnection::setType(const BeamConnection::Type &value) {
            type = value;
        }

        uint32_t BeamConnection::getIndex1() const {
            return index1;
        }

        void BeamConnection::setIndex1(const uint32_t &value) {
            index1 = value;
        }

        uint32_t BeamConnection::getIndex2() const {
            return index2;
        }

        void BeamConnection::setIndex2(const uint32_t &value) {
            index2 = value;
        }

        uint32_t BeamConnection::getIndex3() const {
            return index3;
        }

        void BeamConnection::setIndex3(const uint32_t &value) {
            index3 = value;
        }
    }
}

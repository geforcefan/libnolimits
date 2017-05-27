#include "BeamConnection.h"
#include "BeamNodeConnection.h"
#include "FreeNodeConnection.h"
#include "FooterConnection.h"
#include "RailConnectorConnection.h"

namespace NoLimits {
    namespace NoLimits2 {
        void BeamConnection::read(File::File *file) {
            setIndex1(file->readUnsignedInteger());
            setIndex2(file->readUnsignedInteger());
            setIndex3(file->readUnsignedInteger());
        }

        void BeamConnection::write(File::File *file) {
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

        BeamConnection *BeamConnection::createBeamConnectionFromType(BeamConnection::Type type) {
            switch(type) {
                case BeamConnection::Type::BeamNode:
                    return new BeamNodeConnection();
                case BeamConnection::Type::Footer:
                    return new FooterConnection();
                case BeamConnection::Type::FreeNode:
                    return new FreeNodeConnection();
                case BeamConnection::Type::RailConnector:
                    return new RailConnectorConnection();
                case BeamConnection::Type::None:
                default:
                    return new BeamConnection();
            }
        }
    }
}

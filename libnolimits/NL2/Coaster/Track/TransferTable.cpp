#include "TransferTable.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void TransferTable::readSpecialTrack(File::File *file) {
            setDefaultTrack(file->readUnsignedInteger());
            setLength(file->readDouble());
            setDistance(file->readDouble());
            setDisplayStructure((SpecialTrack::DisplayStructure)file->readUnsigned8());

            file->readNull(31);

            for(int i=0; i <= file->tell(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "SECT") {
                    Section *_section = new Section();
                    file->readChunk(_section);

                    setSection(_section->getSection());
                    i = file->tell() - 1;
                }
            }
        }

        void TransferTable::writeSpecialTrack(File::File *file) {
            file->writeUnsignedInteger(getDefaultTrack());
            file->writeDouble(getLength());
            file->writeDouble(getDistance());
            file->writeUnsigned8(getDisplayStructure());

            file->writeNull(31);

            getSection()->writeChunk(file);
        }

        uint32_t TransferTable::getDefaultTrack() const {
            return defaultTrack;
        }

        void TransferTable::setDefaultTrack(const uint32_t &value) {
            defaultTrack = value;
        }

        double TransferTable::getLength() const {
            return length;
        }

        void TransferTable::setLength(double value) {
            length = value;
        }

        double TransferTable::getDistance() const {
            return distance;
        }

        void TransferTable::setDistance(double value) {
            distance = value;
        }

        SpecialTrack::DisplayStructure TransferTable::getDisplayStructure() const {
            return displayStructure;
        }

        void TransferTable::setDisplayStructure(const SpecialTrack::DisplayStructure &value) {
            displayStructure = value;
        }

        Section *TransferTable::getSection() const {
            return section;
        }

        void TransferTable::setSection(Section *value) {
            section = value;
        }
    }
}

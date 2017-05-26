#include "SpecialTrack.h"
#include "SwitchTrack.h"
#include "TransferTable.h"
#include "../../../File/MemoryFile.h"

#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void SpecialTrack::read(File::File *file) {
            segment.clear();

            setName(file->readString());
            file->readNull(4); // special track type

            setPosition(file->readDoubleVec3());
            setRotation(file->readDoubleVec3());

            uint32_t numberOfInputPoints = file->readUnsignedInteger();
            uint32_t numberOfOutputPoints = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfInputPoints; i++) {
                insertInput(file->readUnsignedInteger());
            }

            for(uint32_t i = 0; i < numberOfOutputPoints; i++) {
                insertOutput(file->readUnsignedInteger());
            }

            setSwitchTime(file->readFloat());

            file->readNull(60);

            file->readNull(8); // dummy read chunk name and chunk size

            readSpecialTrack(file);

            for(int i=0; i <= file->tell(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "SEGM") {
                    Segment *_segment = new Segment();
                    insertSegment(_segment);

                    file->readChunk(_segment);
                    i = file->tell() - 1;
                }
            }
        }

        void SpecialTrack::write(File::File *file) {
            file->writeString(getName());
            file->writeUnsignedInteger(getSpecialTrackType());

            file->writeDoubleVec3(getPosition());
            file->writeDoubleVec3(getRotation());

            file->writeUnsignedInteger(input.size());
            file->writeUnsignedInteger(output.size());

            for(uint32_t i = 0; i < input.size(); i++) {
                file->writeUnsignedInteger(input[i]);
            }

            for(uint32_t i = 0; i < output.size(); i++) {
                file->writeUnsignedInteger(output[i]);
            }

            file->writeFloat(getSwitchTime());

            file->writeNull(60);

            File::File *specialTrackChunkFile = new File::MemoryFile();
            specialTrackChunkFile->openWB();
            writeSpecialTrack(specialTrackChunkFile);
            specialTrackChunkFile->close();

            file->writeChunkName(getSpecialTrackChunkName());
            file->writeUnsignedInteger(specialTrackChunkFile->getFilesize());
            file->writeFile(specialTrackChunkFile);

            for(uint32_t i = 0; i < segment.size(); i++) {
                file->writeChunk(segment[i]);
            }
        }

        SpecialTrack::SpecialTrackType SpecialTrack::getSpecialTrackType() const {
            return _specialTrackType;
        }

        void SpecialTrack::setSpecialTrackType(const SpecialTrack::SpecialTrackType &specialTrackType) {
            _specialTrackType = specialTrackType;
        }
        
        std::string SpecialTrack::getName() const {
            return name;
        }
        
        void SpecialTrack::setName(const std::string &value) {
            name = value;
        }

        glm::vec3 SpecialTrack::getPosition() const {
            return position;
        }

        void SpecialTrack::setPosition(const glm::vec3 &value) {
            position = value;
        }

        glm::vec3 SpecialTrack::getRotation() const {
            return rotation;
        }

        void SpecialTrack::setRotation(const glm::vec3 &value) {
            rotation = value;
        }

        std::vector<uint32_t> SpecialTrack::getInput() const {
            return input;
        }

        uint32_t SpecialTrack::insertInput(uint32_t value) {
            input.push_back(value);
            return input.size() - 1;
        }

        std::vector<uint32_t> SpecialTrack::getOutput() const {
            return output;
        }

        uint32_t SpecialTrack::insertOutput(uint32_t value) {
            output.push_back(value);
            return output.size() - 1;
        }

        float SpecialTrack::getSwitchTime() const {
            return switchTime;
        }

        void SpecialTrack::setSwitchTime(float value) {
            switchTime = value;
        }

        std::vector<Segment *> SpecialTrack::getSegment() const {
            return segment;
        }

        uint32_t SpecialTrack::insertSegment(Segment *value) {
            segment.push_back(value);
            return segment.size() - 1;
        }

        SpecialTrack *SpecialTrack::createSpecialTrackFromType(SpecialTrack::SpecialTrackType specialTrackType) {
            switch (specialTrackType) {
            case SpecialTrackType::SwitchTrackFork:
                return new SwitchTrack(SwitchTrack::SwitchType::Fork);
                break;
            case SpecialTrackType::SwitchTrackMerge:
                return new SwitchTrack(SwitchTrack::SwitchType::Merge);
                break;
            case SpecialTrackType::Transfer:
                return new TransferTable();
                break;
            case SpecialTrackType::None:
            default:
                return new SpecialTrack();
                break;
            }
        }
    }
}

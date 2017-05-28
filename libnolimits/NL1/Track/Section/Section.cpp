#include "Section.h"
#include "Lift.h"
#include "Transport.h"
#include "Brake.h"
#include "../../../File/MemoryFile.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Section::read(File::File *file) {
            setUseIndividualTrackColor(file->readBooleanLegacy());
            setTrackSpineColor(file->readColorLegacy());
            setTrackRailColor(file->readColorLegacy());
            setTrackCrosstieColor(file->readColorLegacy());
            setUseTunnel(file->readBooleanLegacy());
            setFlags1(file->readUnsignedInteger());
            file->readNull(11);

            uint32_t sectionSize = file->readUnsignedInteger();
            uint32_t currPos = file->tell();

            readSection(file);

            file->seek(currPos + sectionSize, SEEK_SET);
        }

        void Section::write(File::File *file) {
            file->writeBooleanLegacy(getUseIndividualTrackColor());
            file->writeColorLegacy(getTrackSpineColor());
            file->writeColorLegacy(getTrackRailColor());
            file->writeColorLegacy(getTrackCrosstieColor());
            file->writeBooleanLegacy(getUseTunnel());
            file->writeUnsignedInteger(getFlags1());
            file->writeNull(11);

            File::File *sectionFile = new File::MemoryFile();
            sectionFile->openWB();
            writeSection(sectionFile);
            sectionFile->close();

            file->writeUnsignedInteger(sectionFile->getFilesize());
            file->writeFile(sectionFile);
        }

        Section *Section::createSectionFromType(Section::SectionType sectionType) {
            switch(sectionType) {
                case Section::SectionType::Lift:
                    return new NoLimits1::Lift();
                case Section::SectionType::Transport:
                    return new NoLimits1::Transport();
                case Section::SectionType::Brake:
                    return new NoLimits1::Brake();
                case Section::SectionType::Track:
                default:
                    return new Section();
            }
        }

        Section::SectionType Section::getSectionType() const {
            return sectionType;
        }

        void Section::setSectionType(Section::SectionType value) {
            sectionType = value;
        }

        bool Section::getUseIndividualTrackColor() const {
            return useIndividualTrackColor;
        }

        void Section::setUseIndividualTrackColor(bool value) {
            useIndividualTrackColor = value;
        }

        const glm::vec3 &Section::getTrackSpineColor() const {
            return trackSpineColor;
        }

        void Section::setTrackSpineColor(const glm::vec3 &value) {
            trackSpineColor = value;
        }

        const glm::vec3 &Section::getTrackRailColor() const {
            return trackRailColor;
        }

        void Section::setTrackRailColor(const glm::vec3 &value) {
            trackRailColor = value;
        }

        const glm::vec3 &Section::getTrackCrosstieColor() const {
            return trackCrosstieColor;
        }

        void Section::setTrackCrosstieColor(const glm::vec3 &value) {
            trackCrosstieColor = value;
        }

        bool Section::getUseTunnel() const {
            return useTunnel;
        }

        void Section::setUseTunnel(bool value) {
            useTunnel = value;
        }

        uint32_t Section::getFlags1() const {
            return flags1;
        }

        void Section::setFlags1(uint32_t value) {
            flags1 = value;
        }

        uint32_t Section::getFlags2() const {
            return flags2;
        }

        void Section::setFlags2(uint32_t value) {
            flags2 = value;
        }
    }
}

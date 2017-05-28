#include "SegmentsChunk.h"
#include "../Track.h"
#include "Section.h"

namespace NoLimits {
    namespace NoLimits1 {
        void SegmentsChunk::read(File::File *file) {
            uint32_t numberOfSegments = file->readUnsignedInteger();
            track->setClosed(file->readBooleanLegacy());

            file->readNull(16);

            for(uint32_t i = 0; i < numberOfSegments; i++) {
                uint32_t sectionType = file->readUnsignedInteger();

                Section *section = Section::createSectionFromType((Section::SectionType) sectionType);
                track->insertSection(section);
                section->read(file);
            }

            file->readNull(16);
            file->readNull(4); // sub chunk count
        }

        void SegmentsChunk::write(File::File *file) {
            file->writeUnsignedInteger((uint32_t) track->getSection().size());
            file->writeBooleanLegacy(track->getClosed());

            file->writeNull(16);

            for(uint32_t i = 0; i < track->getSection().size(); i++) {
                file->writeUnsignedInteger(track->getSection()[i]->getSectionType());
                track->getSection()[i]->write(file);
            }

            file->writeNull(16);
            file->writeUnsignedInteger(0); // sub chunk count
        }
    }
}

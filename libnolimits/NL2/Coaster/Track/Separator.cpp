#include "Separator.h"

namespace NoLimits {
    namespace NoLimits2 {
        void Separator::read(File::File *file) {
            setPosition(file->readDouble());

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "SEGM") {
                    Segment *_segment = new Segment();
                    setSegment(_segment);

                    file->readChunk(_segment);
                    i = file->tell() - 1;
                }

                if(chunk == "SECT") {
                    Section *_section = new Section();
                    file->readChunk(_section);

                    setSection(_section->getSection());
                    i = file->tell() - 1;

                    setSeparatorType(Separator::SeparatorType::TypeSeparator);
                }
            }
        }

        void Separator::write(File::File *file) {
            file->writeDouble(getPosition());
            file->writeNull(28);

            file->writeChunk(getSegment());

            if(getSeparatorType() == Separator::SeparatorType::TypeSeparator) {
                // usually we use file->writeChunk, but ONLY in this case we need to "WRAP" the writing
                // process, because sections are nestes with its subtypes (lift, station, etc...) and I didn´t
                // wanted to separate section and its subtypes (how the file format internally suggests)
                getSection()->writeChunk(file);
            }
        }

        Section *Separator::getSection() const {
            return section;
        }

        void Separator::setSection(Section *value) {
            section = value;
        }

        Segment *Separator::getSegment() const {
            return segment;
        }

        void Separator::setSegment(Segment *value) {
            segment = value;
        }

        double Separator::getPosition() const {
            return position;
        }

        void Separator::setPosition(double value) {
            position = value;
        }

        Separator::SeparatorType Separator::getSeparatorType() const {
            return separatorType;
        }

        void Separator::setSeparatorType(const Separator::SeparatorType &value) {
            separatorType = value;
        }
    }

}

#include "Separator.h"

namespace NoLimits {
    namespace NL2 {
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
                }
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
    }

}

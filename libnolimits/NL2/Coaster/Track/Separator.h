#ifndef LIB_NL2PARK_SEPARATOR_H
#define LIB_NL2PARK_SEPARATOR_H

#include "Section/Section.h"
#include "Segment.h"
#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Separator : public Stream::Chunk {
        public:
            enum SeparatorType {
                TypeSeparator,
                StyleSeparator
            };

            Separator() {
                section = new Section();
                segment = new Segment();

                setSeparatorType(Separator::SeparatorType::StyleSeparator);
            }

            void read(File::File *file);
            void write(File::File *file);

            Section *getSection() const;
            void setSection(Section *value);

            Segment *getSegment() const;
            void setSegment(Segment *value);

            double getPosition() const;
            void setPosition(double value);

            SeparatorType getSeparatorType() const;
            void setSeparatorType(const SeparatorType &value);

            std::string getChunkName() { return "SEPA"; }
        private:
            Section *section;
            Segment *segment;

            double position;

            SeparatorType separatorType;
        };
    }
}

#endif // LIB_NL2PARK_SEPARATOR_H

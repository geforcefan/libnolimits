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
                setPosition(0.0f);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Separator[getPosition]: " << getPosition() << std::endl;
                std::cout << "Separator[getSeparatorType]: " << getSeparatorType() << std::endl;

                getSegment()->debug();
                getSection()->debug();
            }

            Section *getSection() const;
            void setSection(Section *value);

            Segment *getSegment() const;
            void setSegment(Segment *value);

            double getPosition() const;
            void setPosition(double value);

            SeparatorType getSeparatorType() const;
            void setSeparatorType(const SeparatorType &value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SEPA"; }
            /*! \endcond */
        private:
            Section *section;
            Segment *segment;

            double position;

            SeparatorType separatorType;
        };
    }
}

#endif // LIB_NL2PARK_SEPARATOR_H

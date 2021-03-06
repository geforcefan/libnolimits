#ifndef LIB_NL2PARK_SECTION_H
#define LIB_NL2PARK_SECTION_H

#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Section : public NoLimits::Stream::Chunk {
        public:
            enum SectionType {
                Track,
                Station,
                Lift,
                Transport,
                Brake,
                Storage
            };

            Section(SectionType sectionType) : _sectionType(sectionType), section(this) {
                setName("");
            }

            Section() : _sectionType(SectionType::Track), section(this) {
                setName("");
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void writeChunk(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Section[getSectionType]: " << getSectionType() << std::endl;
                std::cout << "Section[getName]: " << getName() << std::endl;
            }

            SectionType getSectionType() const;
            void setSectionType(const SectionType &sectionType);

            std::string getName() const;
            void setName(const std::string &value);

            Section *getSection() const;
            void setSection(Section *value);
        private:
            SectionType _sectionType;
            std::string name;

            Section *section;
        };
    }
}

#endif // LIB_NL2PARK_SECTION_H

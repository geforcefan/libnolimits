#ifndef LIB_NL2PARK_SECTION_H
#define LIB_NL2PARK_SECTION_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Section : public Library::Stream::Chunk {
        public:
            enum SectionType {
                Track,
                Transport,
                Lift,
                Brake,
                Station,
                Storage
            };

            Section(SectionType sectionType) : _sectionType(sectionType), section(this) {}
            Section() : _sectionType(SectionType::Track), section(this) {}
            void read(File::File *file);

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

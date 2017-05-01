#include "Section.h"
#include "Lift.h"
#include "Transport.h"
#include "Brake.h"
#include "Station.h"
#include "Storage.h"

#include <iostream>

namespace NoLimits {
    namespace NL2 {
        void Section::read(File::File *file) {
            file->readNull(4);
            std::string name = file->readString();
            file->readNull(1);

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "LIFT") {
                    NoLimits::NL2::Lift *_lift = new NoLimits::NL2::Lift();
                    _lift->setName(name);
                    setSection(_lift);

                    file->readChunk(_lift);
                    i = file->tell() - 1;
                }

                if(chunk == "TRNS") {
                    NoLimits::NL2::Transport *_transport = new NoLimits::NL2::Transport();
                    _transport->setName(name);
                    setSection(_transport);

                    file->readChunk(_transport);
                    i = file->tell() - 1;
                }

                if(chunk == "BRKE") {
                    NoLimits::NL2::Brake *_brake = new NoLimits::NL2::Brake();
                    _brake->setName(name);
                    setSection(_brake);

                    file->readChunk(_brake);
                    i = file->tell() - 1;
                }

                if(chunk == "STTN") {
                    NoLimits::NL2::Station *_station = new NoLimits::NL2::Station();
                    _station->setName(name);
                    setSection(_station);

                    file->readChunk(_station);
                    i = file->tell() - 1;
                }

                if(chunk == "STOR") {
                    NoLimits::NL2::Storage *_storage = new NoLimits::NL2::Storage();
                    _storage->setName(name);
                    setSection(_storage);

                    file->readChunk(_storage);
                    i = file->tell() - 1;
                }
            }
        }

        Section::SectionType Section::getSectionType() const {
            return _sectionType;
        }

        void Section::setSectionType(const Section::SectionType &sectionType) {
            _sectionType = sectionType;
        }

        std::string Section::getName() const {
            return name;
        }

        void Section::setName(const std::string &value) {
            name = value;
        }

        Section *Section::getSection() const {
            return section;
        }

        void Section::setSection(Section *value) {
            section = value;
        }
    }
}

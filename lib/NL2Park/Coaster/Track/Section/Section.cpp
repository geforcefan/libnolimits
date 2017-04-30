#include "Section.h"
#include "Lift.h"
#include "Transport.h"
#include "Brake.h"
#include "Station.h"
#include "Storage.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Section::read(File::File *file) {
            file->readNull(4);
            std::string name = file->readString();
            file->readNull(1);

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "LIFT") {
                    Library::NL2Park::Lift *_lift = new Library::NL2Park::Lift();
                    _lift->setName(name);
                    setSection(_lift);

                    _lift->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "TRNS") {
                    Library::NL2Park::Transport *_transport = new Library::NL2Park::Transport();
                    _transport->setName(name);
                    setSection(_transport);

                    _transport->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "BRKE") {
                    Library::NL2Park::Brake *_brake = new Library::NL2Park::Brake();
                    _brake->setName(name);
                    setSection(_brake);

                    _brake->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "STTN") {
                    Library::NL2Park::Station *_station = new Library::NL2Park::Station();
                    _station->setName(name);
                    setSection(_station);

                    _station->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "STOR") {
                    Library::NL2Park::Storage *_storage = new Library::NL2Park::Storage();
                    _storage->setName(name);
                    setSection(_storage);

                    _storage->readChunk(file->getChunkBufferFile());
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

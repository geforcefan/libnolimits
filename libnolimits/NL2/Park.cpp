#include "Park.h"
#include <iostream>
#include "../File/NormalFile.h"
#include "../File/MemoryFile.h"

namespace NoLimits {
    namespace NoLimits2 {
        Park::Park(std::string filepath) : Park() {
            NoLimits::File::File *inputFile = new NoLimits::File::NormalFile(filepath);
            inputFile->openRB();
            if(inputFile->readChunkName() == "NL2P")
                inputFile->readChunk(this);
            inputFile->close();
        }

        void Park::save(std::string filepath) {
            NoLimits::File::File *outputFile = new NoLimits::File::NormalFile(filepath);
            outputFile->openWB();
            outputFile->writeChunk(this);
            outputFile->close();
        }

        void Park::write(File::File *file) {
            file->writeNull(4); // propably version?

            file->writeChunk(getInfo());
            file->writeChunk(getUspk());

            for(uint32_t i = 0; i < coaster.size(); i++) {
                file->writeChunk(coaster[i]);
            }

            file->writeChunk(getTerrain());
            file->writeChunk(getScenery());
        }

        void Park::read(File::File *file) {
            coaster.clear();

            file->readNull(4); // propably version?

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "INFO") {
                    file->readChunk(getInfo());
                    i = file->tell() - 1;
                }

                if(chunk == "COAS") {
                    Coaster *_coaster = new Coaster();
                    file->readChunk(_coaster);

                    insertCoaster(_coaster);
                    i = file->tell() - 1;
                }

                if(chunk == "TERC") {
                    file->readChunk(getTerrain());
                    i = file->tell() - 1;
                }

                if(chunk == "SCEN") {
                    file->readChunk(getScenery());
                    i = file->tell() - 1;
                }

                if(chunk == "USPK") {
                    file->readChunk(getUspk());
                    i = file->tell() - 1;
                }
            }
        }

        Info *Park::getInfo() const {
            return info;
        }

        std::vector<Coaster*> Park::getCoaster() const {
            return coaster;
        }

        Coaster *Park::getCoaster(std::string name) const {
            if(coasterMapping.find(name) != coasterMapping.end())
                return coaster.at(coasterMapping.at(name));
            else
                return nullptr;
        }

        uint32_t Park::insertCoaster(Coaster* value) {
            coasterMapping[value->getName()] = coaster.size();
            coaster.push_back(value);
            return coaster.size() - 1;
        }

        Terrain *Park::getTerrain() const {
            return terrain;
        }

        void Park::setTerrain(Terrain *value) {
            terrain = value;
        }

        Uspk *Park::getUspk() const {
            return uspk;
        }

        void Park::setUspk(Uspk *value) {
            uspk = value;
        }

        Scenery *Park::getScenery() const {
            return scenery;
        }

        void Park::setScenery(Scenery *value) {
            scenery = value;
        }
    }
}

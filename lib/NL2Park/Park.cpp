#include <NL2Park/Park.h>
#include <iostream>
#include <File/NormalFile.h>
#include <File/MemoryFile.h>

namespace NoLimits {
    namespace NL2 {
        Park::Park() {
            info = new Info();
            terrain = new Terrain();
            uspk = new Uspk();
            scenery = new Scenery();
        }

        Park::Park(std::string filepath) : Park() {
            readChunk(new NoLimits::File::NormalFile(filepath));
        }

        void Park::save(std::string filepath) {
            NoLimits::File::File *outputFile = new NoLimits::File::NormalFile(filepath.c_str());
            outputFile->openWB();
            outputFile->writeFile(writeChunk());
            outputFile->close();
        }

        void Park::write(File::File *file) {
            file->writeNull(4); // propably version?

            file->writeFile(getInfo()->writeChunk());
            file->writeFile(getUspk()->writeChunk());

            for(uint32_t i = 0; i < coaster.size(); i++) {
                file->writeFile(coaster[i]->writeChunk());
            }

            file->writeFile(getTerrain()->writeChunk());
            file->writeFile(getScenery()->writeChunk());
        }

        void Park::read(File::File *file) {
            coaster.clear();

            file->readNull(4); // propably version?

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "INFO") {
                    getInfo()->readChunk(file->getChunkMemoryFile());
                    i = file->tell() - 1;
                }

                if(chunk == "COAS") {
                    Coaster *_coaster = new Coaster();
                    _coaster->readChunk(file->getChunkMemoryFile());

                    insertCoaster(_coaster);
                    i = file->tell() - 1;
                }

                if(chunk == "TERC") {
                    getTerrain()->readChunk(file->getChunkMemoryFile());
                    i = file->tell() - 1;
                }

                if(chunk == "SCEN") {
                    getScenery()->readChunk(file->getChunkMemoryFile());
                    i = file->tell() - 1;
                }

                if(chunk == "USPK") {
                    getUspk()->readChunk(file->getChunkMemoryFile());
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

        void Park::insertCoaster(Coaster* value) {
            coasterMapping[value->getName()] = coaster.size();
            coaster.push_back(value);
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

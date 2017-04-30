#ifndef LIB_NL2PARK_PARK_H
#define LIB_NL2PARK_PARK_H

#include <string>
#include <Stream/Chunk.h>
#include "Uspk.h"
#include "Scenery/Scenery.h"
#include <NL2Park/Info/Info.h>
#include <NL2Park/Terrain/Terrain.h>
#include <NL2Park/Coaster/Coaster.h>

#include <vector>
#include <map>

namespace Library {
    namespace NL2Park {
        class Park: public Stream::Chunk {
        public:
            Park(std::string filepath);
            Park() {
                info = new Info();
                terrain = new Terrain();
                uspk = new Uspk();
                scenery = new Scenery();
            }

            void debug() {
                info->debug();
                scenery->debug();
            }

            void read(File::File *file);
            void write(File::File *file);

            void save(std::string filepath);

            Info *getInfo() const;

            std::vector<Coaster*> getCoaster() const;
            Coaster* getCoaster(std::string name) const;
            void insertCoaster(Coaster* value);

            Terrain *getTerrain() const;
            void setTerrain(Terrain *value);

            Uspk *getUspk() const;
            void setUspk(Uspk *value);

            Scenery *getScenery() const;
            void setScenery(Scenery *value);

        protected:
            std::string getChunkName() { return "NL2P"; }

        private:
            Info *info;
            Terrain *terrain;
            Uspk *uspk;
            Scenery *scenery;

            std::vector<Coaster*> coaster;
            std::map<std::string, int> coasterMapping;
        };
    }
}

#endif

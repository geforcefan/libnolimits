#ifndef LIB_NL2PARK_PARK_H
#define LIB_NL2PARK_PARK_H

#include <string>
#include "Uspk.h"
#include "Scenery/Scenery.h"
#include "Info/Info.h"
#include "Terrain/Terrain.h"
#include "Coaster/Coaster.h"
#include "../Stream/Chunk.h"

#include <vector>
#include <map>

namespace NoLimits {
    namespace NoLimits2 {
        class Park: public Stream::Chunk {
        public:
            Park(std::string filepath);
            Park();

            void debug() {
                info->debug();
                scenery->debug();

                std::cout << "Park[getCoaster.size]: " << coaster.size() << std::endl;
                if(coaster.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < coaster.size(); i++) {
                    coaster[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                terrain->debug();
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

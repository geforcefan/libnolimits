#ifndef LIB_NL2PARK_COASTER_H
#define LIB_NL2PARK_COASTER_H

#include <vector>

#include <Stream/Chunk.h>
#include <lib/NL2Park/Coaster/Colors.h>
#include <lib/NL2Park/Coaster/Style.h>
#include <lib/NL2Park/Coaster/Mode.h>
#include <lib/NL2Park/Coaster/Train.h>
#include <lib/NL2Park/Coaster/Track/Track.h>
#include <lib/NL2Park/Coaster/Track/Section/Section.h>
#include <lib/NL2Park/Coaster/Track/CustomTrack.h>

namespace NoLimits {
    namespace NL2 {
        class Coaster: public Stream::Chunk {
        public:
            Coaster() {
                colors = new Colors();
                style = new Style();
                mode = new Mode();
            }

            void debug() {
                std::cout << "Coaster[getName]: " << getName() << std::endl;
                std::cout << "Coaster[getDescription]: " << getDescription() << std::endl;
                std::cout << "Coaster[getNumberOfCarsPerTrain]: " << getNumberOfCarsPerTrain() << std::endl;
                std::cout << "Coaster[getHideWireframe]: " << getHideWireframe() << std::endl;
                std::cout << "Coaster[getFreezed]: " << getFreezed() << std::endl;

                colors->debug();
                style->debug();
                mode->debug();

                std::cout << "Coaster[getTrain.size]: " << train.size() << std::endl;
                if(train.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < train.size(); i++) {
                    train[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            void read(File::File *file);
            void write(File::File *file);

            std::string getName() const;
            void setName(const std::string &value);

            std::string getDescription() const;
            void setDescription(const std::string &value);

            uint32_t getNumberOfCarsPerTrain() const;
            void setNumberOfCarsPerTrain(const uint32_t &value);

            bool getHideWireframe() const;
            void setHideWireframe(bool value);

            bool getFreezed() const;
            void setFreezed(bool value);

            Colors *getColors() const;
            void setColors(Colors *value);

            Style *getStyle() const;
            void setStyle(Style *value);

            Mode *getMode() const;
            void setMode(Mode *value);

            std::vector<std::string> getFileScript() const;
            void insertFileScript(std::string value);

            std::vector<Track*> getTrack() const;
            void insertTrack(Track* value);

            std::vector<Train*> getTrain() const;
            void insertTrain(Train* value);

            Section *getSection(std::string name);

        private:
            std::string name;
            std::string description;

            uint32_t numberOfCarsPerTrain;

            bool hideWireframe;
            bool freezed;

            Colors *colors;
            Style *style;
            Mode *mode;

            std::vector<Track*> track;
            std::vector<std::string> fileScript;
            std::vector<Train*> train;

        protected:
            std::string getChunkName() { return "COAS"; }
        };
    }
}

#endif // LIB_NL2PARK_COASTER_H

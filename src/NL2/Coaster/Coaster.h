#ifndef LIB_NL2PARK_COASTER_H
#define LIB_NL2PARK_COASTER_H

#include <vector>

#include <Stream/Chunk.h>
#include <src/NL2/Coaster/Colors.h>
#include <src/NL2/Coaster/Style.h>
#include <src/NL2/Coaster/Mode.h>
#include <src/NL2/Coaster/Train.h>
#include <src/NL2/Coaster/Track/Track.h>
#include <src/NL2/Coaster/Track/Section/Section.h>
#include <src/NL2/Coaster/Track/CustomTrack.h>
#include <src/NL2/Coaster/Support/Support.h>
#include "Script.h"
#include "FileScript.h"

namespace NoLimits {
    namespace NL2 {
        class Coaster: public Stream::Chunk {
        public:
            Coaster() {
                colors = new Colors();
                style = new Style();
                mode = new Mode();
                fileScript = new FileScript();
                support = new Support();

                setName("New Coaster");
                setDescription("");
                setHideWireframe(false);
                setFreezed(false);

                insertTrain(new Train());
                insertTrain(new Train());
            }

            void debug() {
                std::cout << "Coaster[getName]: " << getName() << std::endl;
                std::cout << "Coaster[getDescription]: " << getDescription() << std::endl;
                std::cout << "Coaster[getHideWireframe]: " << getHideWireframe() << std::endl;
                std::cout << "Coaster[getFreezed]: " << getFreezed() << std::endl;

                colors->debug();
                style->debug();
                mode->debug();
                support->debug();

                std::cout << "Coaster[getTrain.size]: " << train.size() << std::endl;
                if(train.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < train.size(); i++) {
                    train[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                fileScript->debug();

                std::cout << "Coaster[script.size]: " << script.size() << std::endl;
                if(script.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < script.size(); i++) {
                    script[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Coaster[track.size]: " << track.size() << std::endl;
                if(track.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < track.size(); i++) {
                    track[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            void read(File::File *file);
            void write(File::File *file);

            std::string getName() const;
            void setName(const std::string &value);

            std::string getDescription() const;
            void setDescription(const std::string &value);

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

            Support *getSupport() const;
            void setSupport(Support *value);

            std::vector<Track*> getTrack() const;
            void insertTrack(Track* value);

            std::vector<Train*> getTrain() const;
            void insertTrain(Train* value);

            Section *getSection(std::string name);

            std::vector<Script *> getScript() const;
            void insertScript(Script* value);

            std::string getChunkName() { return "COAS"; }

        private:
            std::string name;
            std::string description;

            bool hideWireframe;
            bool freezed;

            Colors *colors;
            Style *style;
            Mode *mode;
            FileScript *fileScript;
            Support *support;

            std::vector<Track*> track;
            std::vector<Train*> train;
            std::vector<Script*> script;
        };
    }
}

#endif // LIB_NL2PARK_COASTER_H

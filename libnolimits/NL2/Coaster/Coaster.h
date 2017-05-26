#ifndef LIB_NL2PARK_COASTER_H
#define LIB_NL2PARK_COASTER_H

#include <vector>

#include "../../Stream/Chunk.h"
#include "Colors.h"
#include "Style.h"
#include "Mode.h"
#include "Train.h"
#include "Track/Track.h"
#include "Track/Section/Section.h"
#include "Track/CustomTrack.h"
#include "Track/SpecialTrack.h"
#include "Support/Support.h"
#include "Script.h"
#include "FileScript.h"

namespace NoLimits {
    namespace NoLimits2 {
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

            Coaster(std::string name) : Coaster() {
                setName(name);
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

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

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
            uint32_t insertTrack(Track* value);

            std::vector<Train*> getTrain() const;
            uint32_t insertTrain(Train* value);

            Section *getSection(std::string name);

            FileScript *getFileScript();

            std::vector<Script *> getScript() const;
            uint32_t insertScript(Script* value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "COAS"; }
            /*! \endcond */

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

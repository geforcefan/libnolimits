#include <NL2Park/Coaster/Coaster.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        Coaster::Coaster() {
            colors = new Colors();
            style = new Style();
            mode = new Mode();
        }

        void Coaster::read(File::File *file) {
            setName(file->readString());

            getColors()->setWireframeTrack(file->readColor());
            getMode()->setSplinePosition((Mode::SplinePosition)file->readUnsigned8());

            getMode()->setSplinePositionOffset(file->readDoubleVec2());

            setDescription(file->readString());

            file->readNull(3);
            getStyle()->setStyleType((Style::StyleType)file->readUnsigned8());

            getColors()->setRails(file->readColor());
            getColors()->setCrossTies(file->readColor());
            getColors()->setMainSpine(file->readColor());
            getColors()->setCar(file->readColor());
            getColors()->setSeat(file->readColor());
            getColors()->setHarness(file->readColor());
            getColors()->setBogie(file->readColor());

            setFreezed(file->readBoolean());
            getColors()->setSpineColorScheme((Colors::SpineColorScheme)file->readUnsigned8());
            getColors()->setSupports(file->readColor());
            getColors()->setTunnel(file->readColor());

            getStyle()->setWornType((Style::WornType)file->readUnsigned8());
            getColors()->setChasiss(file->readColor());

            getMode()->setOperationMode((Mode::Operation)file->readUnsigned8());
            getStyle()->setRailType((Style::RailType)file->readUnsigned8());

            getColors()->setHandrails(file->readColor());
            getColors()->setCatwalks(file->readColor());

            getMode()->setPhysicsModel((Mode::PhysicsModel)file->readUnsigned8());
            setHideWireframe(file->readBoolean());

            setNumberOfCarsPerTrain(file->readUnsigned8());

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "TRAI") {
                    Train *_train = new Train();
                    insertTrain(_train);

                    _train->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "CUTK") {
                    CustomTrack *_track = new CustomTrack();
                    insertTrack(_track);

                    _track->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "CUFR") {
                    getMode()->getCustomFriction()->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "FSCR") {
                    file->readNull(4);

                    uint32_t numScripts = file->readUnsignedInteger();

                    for(uint32_t i = 0; i < numScripts; i++) {
                        insertFileScript(file->readString());
                        file->readNull(8);
                    }
                }
            }

            for (unsigned long i = 0; i < train.size(); i++) {
                Train *t = train.at(i);
                if (t->getCar().size() && numberOfCarsPerTrain != t->getCar().size()) {
                    t->getCar().at(0)->setIsZeroCar(true);
                }
            }
        }

        std::string Coaster::getName() const {
            return name;
        }

        void Coaster::setName(const std::string &value) {
            name = value;
        }

        std::string Coaster::getDescription() const {
            return description;
        }

        void Coaster::setDescription(const std::string &value) {
            description = value;
        }

        uint32_t Coaster::getNumberOfCarsPerTrain() const {
            return numberOfCarsPerTrain;
        }

        void Coaster::setNumberOfCarsPerTrain(const uint32_t &value) {
            numberOfCarsPerTrain = value;
        }

        bool Coaster::getHideWireframe() const {
            return hideWireframe;
        }

        void Coaster::setHideWireframe(bool value) {
            hideWireframe = value;
        }

        bool Coaster::getFreezed() const {
            return freezed;
        }

        void Coaster::setFreezed(bool value) {
            freezed = value;
        }

        Colors *Coaster::getColors() const {
            return colors;
        }

        void Coaster::setColors(Colors *value) {
            colors = value;
        }

        Style *Coaster::getStyle() const {
            return style;
        }

        void Coaster::setStyle(Style *value) {
            style = value;
        }

        Mode *Coaster::getMode() const {
            return mode;
        }

        void Coaster::setMode(Mode *value) {
            mode = value;
        }

        std::vector<std::string> Coaster::getFileScript() const {
            return fileScript;
        }

        void Coaster::insertFileScript(std::string value) {
            fileScript.push_back(value);
        }

        std::vector<Track*> Coaster::getTrack() const {
            return track;
        }

        void Coaster::insertTrack(Track* value) {
            track.push_back(value);
        }

        std::vector<Train*> Coaster::getTrain() const {
            return train;
        }

        void Coaster::insertTrain(Train* value) {
            train.push_back(value);
        }

        Section *Coaster::getSection(std::string name) {
            Section *foundSection = NULL;

            if(!name.size())
                return foundSection;

            for(unsigned long i = 0; i < track.size(); i++) {
                Track *t = track[i];
                Section *section = t->getSectionByName(name);

                if(section != NULL) {
                    foundSection = section;
                    break;
                }
            }

            return foundSection;
        }
    }
}

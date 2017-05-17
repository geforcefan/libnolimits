#include "Coaster.h"
#include <iostream>
#include <algorithm>

namespace NoLimits {
    namespace NoLimits2 {
        void Coaster::write(File::File *file) {
            file->writeString(getName());

            file->writeColor(getColors()->getWireframeTrack());
            file->writeUnsigned8(getMode()->getSplinePosition());

            file->writeDoubleVec2(getMode()->getSplinePositionOffset());

            file->writeString(getDescription());

            file->writeNull(3);
            file->writeUnsigned8(getStyle()->getStyleType());

            file->writeColor(getColors()->getRails());
            file->writeColor(getColors()->getCrossTies());
            file->writeColor(getColors()->getMainSpine());
            file->writeColor(getColors()->getCar());
            file->writeColor(getColors()->getSeat());
            file->writeColor(getColors()->getHarness());
            file->writeColor(getColors()->getBogie());

            file->writeBoolean(getFreezed());
            file->writeUnsigned8(getColors()->getSpineColorScheme());
            file->writeColor(getColors()->getSupports());
            file->writeColor(getColors()->getTunnel());

            file->writeUnsigned8(getStyle()->getWornType());
            file->writeColor(getColors()->getChasiss());

            file->writeUnsigned8(getMode()->getOperationMode());
            file->writeUnsigned8(getStyle()->getRailType());

            file->writeColor(getColors()->getHandrails());
            file->writeColor(getColors()->getCatwalks());

            file->writeUnsigned8(getMode()->getPhysicsModel());
            file->writeBoolean(getHideWireframe());

            int numberOfCarsPerTrain = 0;
            for(uint32_t i = 0; i < train.size(); i++) {
                numberOfCarsPerTrain = std::min((int)train[i]->getCar().size(), numberOfCarsPerTrain);
            }

            file->writeUnsigned8(numberOfCarsPerTrain);

            file->writeNull(6);


            for(uint32_t i = 0; i < track.size(); i++) {
                if(track[i]->getTrackType() == Track::TrackType::Custom) {
                    file->writeChunk(dynamic_cast<CustomTrack*>(track[i]));
                }
            }

            for(uint32_t i = 0; i < train.size(); i++) {
                file->writeChunk(train[i]);
            }

            for(uint32_t i = 0; i < script.size(); i++) {
                file->writeChunk(script[i]);
            }

            if(fileScript->getPath().size())
                file->writeChunk(fileScript);

            file->writeChunk(getSupport());

            file->writeChunk(getMode()->getCustomFriction());
        }

        void Coaster::read(File::File *file) {
            track.clear();
            train.clear();
            script.clear();

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

            // number of cars per train, but we don´t need to read this value, since there are car chunks inside of train chunks
            // where we can determine how many cars per train there is
            //setNumberOfCarsPerTrain(file->readUnsigned8());
            file->readNull(1);

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "TRAI") {
                    Train *_train = new Train();
                    insertTrain(_train);

                    file->readChunk(_train);
                    i = file->tell() - 1;
                }

                if(chunk == "CUTK") {
                    CustomTrack *_track = new CustomTrack();
                    insertTrack(_track);

                    file->readChunk(_track);
                    i = file->tell() - 1;
                }

                if(chunk == "CUFR") {
                    file->readChunk(getMode()->getCustomFriction());
                    i = file->tell() - 1;
                }

                if(chunk == "SCRT") {
                    Script *_script = new Script();
                    insertScript(_script);

                    file->readChunk(_script);
                    i = file->tell() - 1;
                }

                if(chunk == "FSCR") {
                    file->readChunk(fileScript);
                    i = file->tell() - 1;
                }

                if(chunk == "SUPP") {
                    file->readChunk(getSupport());
                    i = file->tell() - 1;
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
            Section *foundSection = nullptr;

            if(!name.size())
                return foundSection;

            for(unsigned long i = 0; i < track.size(); i++) {
                Track *t = track[i];
                Section *section = t->getSectionByName(name);

                if(section != nullptr) {
                    foundSection = section;
                    break;
                }
            }

            return foundSection;
        }

        std::vector<Script*> Coaster::getScript() const {
            return script;
        }

        void Coaster::insertScript(Script* value) {
            script.push_back(value);
        }

        Support *Coaster::getSupport() const {
            return support;
        }

        void Coaster::setSupport(Support *value) {
            support = value;
        }
    }
}

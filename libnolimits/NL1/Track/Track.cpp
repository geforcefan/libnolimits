#include "Track.h"
#include "../../File/NormalFile.h"
#include "../../File/MemoryFile.h"
#include "BeziersChunk.h"
#include "Section/SegmentsChunk.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Track::read(File::File *file) {
            train.clear();
            vertex.clear();
            section.clear();

            setCoasterStyle((Track::CoasterStyle)file->readUnsignedInteger());

            uint32_t numberOfTrains = file->readUnsignedInteger();
            setNumberOfCarsPerTrain(file->readUnsignedInteger());

            for(uint32_t i = 0; i < numberOfTrains; i++) {
                Train *_train = new Train();
                _train->read(file);
                insertTrain(_train);
            }

            getColors()->setTrackSpine(file->readColorLegacy());
            getColors()->setTrackRail(file->readColorLegacy());
            getColors()->setTrackCrosstie(file->readColorLegacy());
            getColors()->setSupports(file->readColorLegacy());
            getColors()->setTrainSeat(file->readColorLegacy());
            getColors()->setTrainRestraint(file->readColorLegacy());
            getColors()->setTrain(file->readColorLegacy());
            getColors()->setTrainGear(file->readColorLegacy());

            file->readNull(4); // always 0, 57, 23, 2, don´t know what this is.

            setTrackMode((Track::TrackMode)file->readUnsignedInteger());

            getColors()->setUseTunnelColor(file->readBooleanLegacy());
            getColors()->setTunnel(file->readColorLegacy());

            file->readNull(3);
            file->readNull(4); // number of sub chunks

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if (chunk == "INFO") {
                    file->readChunk(getInfo());
                    i = file->tell() - 1;
                }

                if (chunk == "BEZR") {
                    BeziersChunk *beziersChunk = new BeziersChunk(this);
                    file->readChunk(beziersChunk);
                    i = file->tell() - 1;
                }

                if (chunk == "SEGM") {
                    SegmentsChunk *segmentsChunk = new SegmentsChunk(this);
                    file->readChunk(segmentsChunk);
                    i = file->tell() - 1;
                }
            }
        }

        void Track::write(File::File *file) {
            file->writeUnsignedInteger(getCoasterStyle());
            file->writeUnsignedInteger(train.size());
            file->writeUnsignedInteger(getNumberOfCarsPerTrain());

            for(uint32_t i = 0; i < train.size(); i++) {
                train[i]->write(file);
            }

            file->writeColorLegacy(getColors()->getTrackSpine());
            file->writeColorLegacy(getColors()->getTrackRail());
            file->writeColorLegacy(getColors()->getTrackCrosstie());
            file->writeColorLegacy(getColors()->getSupports());
            file->writeColorLegacy(getColors()->getTrainSeat());
            file->writeColorLegacy(getColors()->getTrainRestraint());
            file->writeColorLegacy(getColors()->getTrain());
            file->writeColorLegacy(getColors()->getTrainGear());

            file->writeUnsigned8(0);
            file->writeUnsigned8(57);
            file->writeUnsigned8(23);
            file->writeUnsigned8(2);

            file->writeUnsignedInteger(getTrackMode());

            file->writeBooleanLegacy(getColors()->getUseTunnelColor());
            file->writeColorLegacy(getColors()->getTunnel());

            file->writeNull(3);

            uint32_t numberOfSubChunks = 0;

            File::File *subChunksFile = new File::MemoryFile();
            subChunksFile->openWB();

            subChunksFile->writeChunk(getInfo());
            numberOfSubChunks++;

            if(vertex.size()) {
                BeziersChunk *beziersChunk = new BeziersChunk(this);
                subChunksFile->writeChunk(beziersChunk);
                numberOfSubChunks++;
            }

            if(section.size()) {
                SegmentsChunk *segmentsChunk = new SegmentsChunk(this);
                subChunksFile->writeChunk(segmentsChunk);
                numberOfSubChunks++;
            }

            subChunksFile->close();

            file->writeUnsignedInteger(numberOfSubChunks);
            file->writeFile(subChunksFile);
        }

        Info *Track::getInfo() const {
            return info;
        }

        void Track::setInfo(Info *value) {
            info = value;
        }

        Track::CoasterStyle Track::getCoasterStyle() const {
            return coasterStyle;
        }

        void Track::setCoasterStyle(Track::CoasterStyle value) {
            coasterStyle = value;
        }

        const std::vector<Train *, std::allocator<Train *>> &Track::getTrain() const {
            return train;
        }

        void Track::insertTrain(Train *value) {
            train.push_back(value);
        }

        uint32_t Track::getNumberOfCarsPerTrain() const {
            return numberOfCarsPerTrain;
        }

        void Track::setNumberOfCarsPerTrain(uint32_t value) {
            numberOfCarsPerTrain = value;
        }

        Colors *Track::getColors() const {
            return colors;
        }

        void Track::setColors(Colors *value) {
            colors = value;
        }

        Track::TrackMode Track::getTrackMode() const {
            return trackMode;
        }

        void Track::setTrackMode(Track::TrackMode value) {
            trackMode = value;
        }

        const std::vector<Vertex *, std::allocator<Vertex *>> &Track::getVertex() const {
            return vertex;
        }

        void Track::insertVertex(Vertex* value) {
            vertex.push_back(value);
        }

        const std::vector<Section *, std::allocator<Section *>> &Track::getSection() const {
            return section;
        }

        void Track::insertSection(Section* value) {
            section.push_back(value);
        }

        bool Track::getClosed() const {
            return closed;
        }

        void Track::setClosed(bool value) {
            closed = value;
        }
    }
}
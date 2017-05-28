#include "Track.h"
#include "../../File/NormalFile.h"
#include "../../File/MemoryFile.h"

namespace NoLimits {
    namespace NoLimits1 {
        void Track::read(File::File *file) {
            train.clear();

            setCoasterStyle((Track::CoasterStyle)file->readUnsignedInteger());

            uint32_t numberOfTrains = file->readUnsignedInteger();
            setNumberOfCarsPerTrain(file->readUnsignedInteger());

            for(uint32_t i = 0; i < numberOfTrains; i++) {
                Train *_train = new Train();
                _train->read(file);
                insertTrain(_train);
            }

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if (chunk == "INFO") {
                    file->readChunk(getInfo());
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

            uint32_t numberOfSubChunks = 0;

            File::File *subChunksFile = new File::MemoryFile();
            subChunksFile->openWB();

            subChunksFile->writeChunk(getInfo());
            numberOfSubChunks++;

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
    }
}
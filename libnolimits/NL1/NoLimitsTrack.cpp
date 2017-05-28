#include "NoLimitsTrack.h"
#include "../File/NormalFile.h"
#include "../File/MemoryFile.h"

namespace NoLimits {
    namespace NoLimits1 {
        NoLimitsTrack::NoLimitsTrack(std::string filepath) : NoLimitsTrack() {
            NoLimits::File::File *inputFile = new NoLimits::File::NormalFile(filepath);
            inputFile->openRB();
            if(inputFile->readChunkName() == "NLIM")
                inputFile->readChunk(this);
            inputFile->close();
        }

        void NoLimitsTrack::save(std::string filepath) {
            NoLimits::File::File *outputFile = new NoLimits::File::NormalFile(filepath);
            outputFile->openWB();
            outputFile->writeChunk(this);
            outputFile->close();
        }

        void NoLimitsTrack::read(File::File *file) {
            getVersion()->read(file);
            file->readNull(1);
            setUse16Friction(file->readBooleanLegacy());
            file->readNull(14);

            file->readUnsignedInteger(); // sub chunks count
            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if (chunk == "TRCK") {
                    file->readChunk(getTrack());
                    i = file->tell() - 1;
                }
            }
        }

        void NoLimitsTrack::write(File::File *file) {
            getVersion()->write(file);
            file->writeNull(1);
            file->writeBooleanLegacy(getUse16Friction());
            file->writeNull(14);

            uint32_t numberOfSubChunks = 0;

            File::File *subChunksFile = new File::MemoryFile();
            subChunksFile->openWB();

            subChunksFile->writeChunk(getTrack());
            numberOfSubChunks++;

            subChunksFile->close();

            file->writeUnsignedInteger(numberOfSubChunks);
            file->writeFile(subChunksFile);
        }

        Version *NoLimitsTrack::getVersion() const {
            return version;
        }

        void NoLimitsTrack::setVersion(Version *value) {
            version = value;
        }

        bool NoLimitsTrack::getUse16Friction() const {
            return use16Friction;
        }

        void NoLimitsTrack::setUse16Friction(bool value) {
            use16Friction = value;
        }

        Track *NoLimitsTrack::getTrack() const {
            return track;
        }

        void NoLimitsTrack::setTrack(Track *value) {
            track = value;
        }
    }
}
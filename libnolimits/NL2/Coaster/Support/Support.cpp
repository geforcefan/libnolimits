#include "Support.h"
#include "../../../File/MemoryFile.h"

namespace NoLimits {
    namespace NoLimits2 {
        void Support::read(File::File *file) {
            footer.clear();
            freeNode.clear();
            footer.clear();
            prefab.clear();

            file->readNull(32);

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);
                std::string chunk = file->readChunkName();

                if(chunk == "FOOT") {
                    readFooters(file);
                }

                if(chunk == "FREE") {
                    readFreeNodes(file);
                }

                if(chunk == "BEAM") {
                    readBeams(file);
                }

                if(chunk == "PRFT") {
                    readPrefab(file);
                }
            }
        }

        void Support::readFooters(File::File *file) {
            file->readNull(4);
            file->readNull(8);

            uint32_t numberOfFooter = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfFooter; i++) {
                Footer *_footer = new Footer();
                _footer->read(file);

                insertFooter(_footer);
            }

            file->readNull(8);
        }

        void Support::writeFooters(File::File *file) {
            File::File *subfile = new File::MemoryFile();
            subfile->openWB();

            subfile->writeNull(8);
            subfile->writeUnsignedInteger(footer.size());
            for(uint32_t i = 0; i < footer.size(); i++) {
                footer[i]->write(subfile);
            }
            subfile->writeNull(8);

            subfile->close();

            file->writeChunkName("FOOT");
            file->writeUnsignedInteger(subfile->getFilesize());
            file->writeFile(subfile);
        }


        void Support::readPrefab(File::File *file) {
            file->readNull(4);

            uint32_t numberOfPrefabs = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfPrefabs; i++) {
                insertPrefab(file->readString());
            }
        }

        void Support::writePrefab(File::File *file) {
            File::File *subfile = new File::MemoryFile();
            subfile->openWB();

            subfile->writeUnsignedInteger(prefab.size());
            for(uint32_t i = 0; i < prefab.size(); i++) {
                subfile->writeString(prefab[i]);
            }

            subfile->close();

            file->writeChunkName("PRFT");
            file->writeUnsignedInteger(subfile->getFilesize());
            file->writeFile(subfile);
        }

        void Support::readFreeNodes(File::File *file) {
            file->readNull(4);
            file->readNull(8);

            uint32_t numberOfFreeNodes = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfFreeNodes; i++) {
                FreeNode *_freeNode = new FreeNode();
                _freeNode->read(file);

                insertFreeNode(_freeNode);
            }

            file->readNull(8);
        }

        void Support::writeFreeNodes(File::File *file) {
            File::File *subfile = new File::MemoryFile();
            subfile->openWB();

            subfile->writeNull(8);
            subfile->writeUnsignedInteger(freeNode.size());
            for(uint32_t i = 0; i < freeNode.size(); i++) {
                freeNode[i]->write(subfile);
            }
            subfile->writeNull(8);

            subfile->close();

            file->writeChunkName("FREE");
            file->writeUnsignedInteger(subfile->getFilesize());
            file->writeFile(subfile);
        }


        void Support::readBeams(File::File *file) {
            file->readNull(4);
            file->readNull(8);

            uint32_t numberOfBeams = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfBeams; i++) {
                Beam *_beam = new Beam();
                _beam->read(file);
                insertBeam(_beam);
            }

            file->readNull(8);
        }

        void Support::writeBeams(File::File *file) {
            File::File *subfile = new File::MemoryFile();
            subfile->openWB();

            subfile->writeNull(8);
            subfile->writeUnsignedInteger(beam.size());
            for(uint32_t i = 0; i < beam.size(); i++) {
                beam[i]->write(subfile);
            }
            subfile->writeNull(8);

            subfile->close();

            file->writeChunkName("BEAM");
            file->writeUnsignedInteger(subfile->getFilesize());
            file->writeFile(subfile);
        }

        void Support::write(File::File *file) {
            file->writeNull(32);

            if(freeNode.size())
                writeFreeNodes(file);

            if(footer.size())
                writeFooters(file);

            if(beam.size())
                writeBeams(file);

            if(prefab.size())
                writePrefab(file);
        }

        std::vector<Footer *> Support::getFooter() const {
            return footer;
        }

        uint32_t Support::insertFooter(Footer *value) {
            footer.push_back(value);
            return footer.size() - 1;
        }

        std::vector<FreeNode *> Support::getFreeNode() const {
            return freeNode;
        }

        uint32_t Support::insertFreeNode(FreeNode *value) {
            freeNode.push_back(value);
            return freeNode.size() - 1;
        }

        void Support::removeFreeNode(uint32_t freeNodeIndex) {

            freeNode.erase(freeNode.begin() + freeNodeIndex);
        }

        std::vector<Beam *> Support::getBeam() const {
            return beam;
        }

        uint32_t Support::insertBeam(Beam *value) {
            beam.push_back(value);
            return beam.size() - 1;
        }

        void Support::removeBeam(uint32_t beamIndex) {
            beam.erase(beam.begin() + beamIndex);
        }

        std::vector<std::string> Support::getPrefab() const {
            return prefab;
        }

        uint32_t Support::insertPrefab(std::string value) {
            prefab.push_back(value);
            return prefab.size() - 1;
        }
    }
}

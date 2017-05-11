#include "Support.h"
#include <File/MemoryFile.h>

namespace NoLimits {
    namespace NL2 {
        void Support::read(File::File *file) {
            footer.clear();
            freeNode.clear();
            footer.clear();

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
        }

        std::vector<Footer *> Support::getFooter() const {
            return footer;
        }

        void Support::insertFooter(Footer *value) {
            footer.push_back(value);
        }

        std::vector<FreeNode *> Support::getFreeNode() const {
            return freeNode;
        }

        void Support::insertFreeNode(FreeNode *value)
        {
            freeNode.push_back(value);
        }

        std::vector<Beam *> Support::getBeam() const {
            return beam;
        }

        void Support::insertBeam(Beam *value) {
            beam.push_back(value);
        }
    }
}

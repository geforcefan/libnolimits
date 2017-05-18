#ifndef LIB_NL2PARK_SUPPORT_H
#define LIB_NL2PARK_SUPPORT_H

#include "../../../Stream/Chunk.h"
#include "Footer.h"
#include "FreeNode.h"
#include "Beam.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
        class Support : public Stream::Chunk {
        public:
            Support() {}

            void read(File::File *file);
            void write(File::File *file);

            std::vector<Footer *> getFooter() const;
            void insertFooter(Footer* value);

            std::string getChunkName() { return "SUPP"; }

            std::vector<FreeNode *> getFreeNode() const;
            void insertFreeNode(FreeNode* value);

            std::vector<Beam *> getBeam() const;
            void insertBeam(Beam* value);

        private:
            std::vector<Footer*> footer;
            std::vector<FreeNode*> freeNode;
            std::vector<Beam*> beam;

            void readFooters(File::File *file);
            void writeFooters(File::File *file);

            void readFreeNodes(File::File *file);
            void writeFreeNodes(File::File *file);

            void readBeams(File::File *file);
            void writeBeams(File::File *file);
        };
    }
}

#endif // LIB_NL2PARK_SUPPORT_H

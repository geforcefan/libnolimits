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

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Support[footer.size]: " << footer.size() << std::endl;
                if(footer.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < footer.size(); i++) {
                    footer[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Support[freeNode.size]: " << freeNode.size() << std::endl;
                if(freeNode.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < freeNode.size(); i++) {
                    freeNode[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Support[beam.size]: " << beam.size() << std::endl;
                if(beam.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < beam.size(); i++) {
                    beam[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Support[prefab.size]: " << prefab.size() << std::endl;
                if(prefab.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < prefab.size(); i++) {
                    std::cout << "Support[prefab][" << i << "]: " << prefab[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            std::vector<Footer *> getFooter() const;
            uint32_t insertFooter(Footer* value);

            std::vector<FreeNode *> getFreeNode() const;
            uint32_t insertFreeNode(FreeNode* value);
            void removeFreeNode(uint32_t freeNodeIndex);

            std::vector<Beam *> getBeam() const;
            uint32_t insertBeam(Beam* value);
            void removeBeam(uint32_t beamIndex);

            std::vector<std::string> getPrefab() const;
            uint32_t insertPrefab(std::string value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SUPP"; }
            /*! \endcond */

        private:
            std::vector<Footer*> footer;
            std::vector<FreeNode*> freeNode;
            std::vector<Beam*> beam;
            std::vector<std::string> prefab;

            void readFooters(File::File *file);
            void writeFooters(File::File *file);

            void readFreeNodes(File::File *file);
            void writeFreeNodes(File::File *file);

            void readBeams(File::File *file);
            void writeBeams(File::File *file);

            void readPrefab(File::File *file);
            void writePrefab(File::File *file);
        };
    }
}

#endif // LIB_NL2PARK_SUPPORT_H

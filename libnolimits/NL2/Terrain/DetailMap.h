#ifndef DETAILMAP_H
#define DETAILMAP_H

#include <string>
#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class DetailMap : public Stream::Chunk
        {
        public:
            DetailMap() {
                setTexture("intern:data/textures/terrain/GrassVegetation.jpg");
                setRepeatIndex(1);
            }

            void debug() {
                std::cout << "DetailMap[getTexture]: " << getTexture() << std::endl;
                std::cout << "DetailMap[getRepeatIndex]: " << getRepeatIndex() << std::endl;
            }

            std::string getTexture() const;
            void setTexture(const std::string &value);

            uint32_t getRepeatIndex() const;
            void setRepeatIndex(const uint32_t &value);

        private:
            std::string texture;
            uint32_t repeatIndex;
        };
    }
}

#endif // DETAILMAP_H

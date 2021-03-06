#ifndef BASEMAP_H
#define BASEMAP_H

#include <string>
#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class BaseMap : public Stream::Chunk
        {
        public:
            BaseMap() {
                setTexture("intern:data/textures/terrain/DiffuseCloudGreen.jpg");
                setRepeatIndex(0);
            }

            void debug() {
                std::cout << "BaseMap[getTexture]: " << getTexture() << std::endl;
                std::cout << "BaseMap[getRepeatIndex]: " << getRepeatIndex() << std::endl;
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

#endif // BASEMAP_H

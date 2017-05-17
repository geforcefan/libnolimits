#ifndef BUMPMAP_H
#define BUMPMAP_H

#include <string>
#include "TerrainMap.h"
#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class BumpMap : public Stream::Chunk
        {
        public:
            BumpMap() {
                setTexture("");
                setSpecularMapTexture("");
                setHeightMapScale(2.2f);
                setMapType(NoLimits::NoLimits2::TerrainMap::Normal);
                setRepeatIndex(2);
            }

            void debug() {
                std::cout << "BumpMap[getTexture]: " << getTexture() << std::endl;
                std::cout << "BumpMap[getMapType]: " << getMapType() << std::endl;
                std::cout << "BumpMap[getHeightMapScale]: " << getHeightMapScale() << std::endl;
                std::cout << "BumpMap[getSpecularMapTexture]: " << getSpecularMapTexture() << std::endl;
                std::cout << "BumpMap[getRepeatIndex]: " << getRepeatIndex() << std::endl;
            }

            std::string getTexture() const;
            void setTexture(const std::string &value);

            TerrainMap getMapType() const;
            void setMapType(const TerrainMap &value);

            float getHeightMapScale() const;
            void setHeightMapScale(float value);

            std::string getSpecularMapTexture() const;
            void setSpecularMapTexture(const std::string &value);

            uint32_t getRepeatIndex() const;
            void setRepeatIndex(const uint32_t &value);

        private:
            std::string texture;
            std::string specularMapTexture;

            TerrainMap mapType;
            float heightMapScale;
            uint32_t repeatIndex;
        };
    }
}

#endif // BUMPMAP_H

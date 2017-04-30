#ifndef BUMPMAP_H
#define BUMPMAP_H

#include <string>
#include "TerrainMap.h"

namespace Library {
    namespace NL2Park {
        class BumpMap
        {
        public:
            BumpMap() {
                setTexture("");
                setSpecularMapTexture("");
                setHeightMapScale(2.2f);
                setMapType(Library::NL2Park::TerrainMap::Normal);
                setRepeatIndex(2);
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

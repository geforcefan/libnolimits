#ifndef WATER_H
#define WATER_H

#include <string>
#include "../../Stream/Chunk.h"
#include "TerrainMap.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Water : public Stream::Chunk
        {
        public:
            Water() {
                setDensity(0.8f);
                setDiffuseTexture("intern:data/textures/water/waterdiffuse.jpg");
                setDiffuseTextureRepeatsPerDistance(0.06f);
                setBumpMapTexture("intern:data/textures/water/waterbump.png");
                setBumpMapType(NoLimits::NoLimits2::TerrainMap::Height);
                setBumpMapHeightMapScale(10.0f);
                setBumpMapRepeatsPerDistance(0.08f);
                setReflection(0.8f);
                setWaves(0.3f);
            }

            void debug() {
                std::cout << "Water[getDensity]: " << getDensity() << std::endl;
                std::cout << "Water[getDiffuseTexture]: " << getDiffuseTexture() << std::endl;
                std::cout << "Water[getDiffuseTextureRepeatsPerDistance]: " << getDiffuseTextureRepeatsPerDistance() << std::endl;
                std::cout << "Water[getBumpMapTexture]: " << getBumpMapTexture() << std::endl;
                std::cout << "Water[getBumpMapRepeatsPerDistance]: " << getBumpMapRepeatsPerDistance() << std::endl;
                std::cout << "Water[getBumpMapType]: " << getBumpMapType() << std::endl;
                std::cout << "Water[getBumpMapHeightMapScale]: " << getBumpMapHeightMapScale() << std::endl;
                std::cout << "Water[getReflection]: " << getReflection() << std::endl;
                std::cout << "Water[getWaves]: " << getWaves() << std::endl;
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            float getDensity() const;
            void setDensity(float value);

            std::string getDiffuseTexture() const;
            void setDiffuseTexture(const std::string &value);

            float getDiffuseTextureRepeatsPerDistance() const;
            void setDiffuseTextureRepeatsPerDistance(float value);

            std::string getBumpMapTexture() const;
            void setBumpMapTexture(const std::string &value);

            float getBumpMapRepeatsPerDistance() const;
            void setBumpMapRepeatsPerDistance(float value);

            TerrainMap getBumpMapType() const;
            void setBumpMapType(const TerrainMap &value);

            float getBumpMapHeightMapScale() const;
            void setBumpMapHeightMapScale(float value);

            float getReflection() const;
            void setReflection(float value);

            float getWaves() const;
            void setWaves(float value);

        private:
            float density;

            std::string diffuseTexture;
            float diffuseTextureRepeatsPerDistance;

            std::string bumpMapTexture;
            float bumpMapRepeatsPerDistance;

            TerrainMap bumpMapType;
            float bumpMapHeightMapScale;

            float reflection;
            float waves;
        };
    }
}

#endif // WATER_H

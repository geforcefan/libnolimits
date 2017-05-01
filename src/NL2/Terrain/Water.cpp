#include "Water.h"

namespace NoLimits {
    namespace NL2 {
        void Water::read(File::File *file) {
            file->readNull(64);

            setDiffuseTexture(file->readString());
            setBumpMapTexture(file->readString());

            file->readNull(2);

            setDensity(file->readFloat());
            setDiffuseTextureRepeatsPerDistance(file->readFloat());

            setWaves(file->readFloat());
            setReflection(file->readFloat());

            setBumpMapType((TerrainMap)file->readUnsigned8());
            setBumpMapHeightMapScale(file->readFloat());
            setBumpMapRepeatsPerDistance(file->readFloat());
        }

        void Water::write(File::File *file) {
            file->writeNull(64);

            file->writeString(getDiffuseTexture());
            file->writeString(getBumpMapTexture());

            file->writeNull(2);

            file->writeFloat(getDensity());
            file->writeFloat(getDiffuseTextureRepeatsPerDistance());

            file->writeFloat(getWaves());
            file->writeFloat(getReflection());

            file->writeUnsigned8(getBumpMapType());
            file->writeFloat(getBumpMapHeightMapScale());
            file->writeFloat(getBumpMapRepeatsPerDistance());
        }

        float Water::getDensity() const {
            return density;
        }

        void Water::setDensity(float value) {
            density = value;
        }

        std::string Water::getDiffuseTexture() const {
            return diffuseTexture;
        }

        void Water::setDiffuseTexture(const std::string &value) {
            diffuseTexture = value;
        }

        float Water::getDiffuseTextureRepeatsPerDistance() const {
            return diffuseTextureRepeatsPerDistance;
        }

        void Water::setDiffuseTextureRepeatsPerDistance(float value) {
            diffuseTextureRepeatsPerDistance = value;
        }

        std::string Water::getBumpMapTexture() const {
            return bumpMapTexture;
        }

        void Water::setBumpMapTexture(const std::string &value) {
            bumpMapTexture = value;
        }

        float Water::getBumpMapRepeatsPerDistance() const {
            return bumpMapRepeatsPerDistance;
        }

        void Water::setBumpMapRepeatsPerDistance(float value) {
            bumpMapRepeatsPerDistance = value;
        }

        TerrainMap Water::getBumpMapType() const {
            return bumpMapType;
        }

        void Water::setBumpMapType(const TerrainMap &value) {
            bumpMapType = value;
        }

        float Water::getBumpMapHeightMapScale() const {
            return bumpMapHeightMapScale;
        }

        void Water::setBumpMapHeightMapScale(float value) {
            bumpMapHeightMapScale = value;
        }

        float Water::getReflection() const {
            return reflection;
        }

        void Water::setReflection(float value) {
            reflection = value;
        }

        float Water::getWaves() const {
            return waves;
        }

        void Water::setWaves(float value) {
            waves = value;
        }
    }
}

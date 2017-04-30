#include "Layer.h"

namespace Library {
    namespace NL2Park {
        void Layer::read(File::File *file) {
            getAutoPaint()->setEnabled(file->readBoolean());

            setName(file->readString());

            // Textures
            getBaseMap()->setTexture(file->readString());
            getDetailMap()->setTexture(file->readString());
            getBumpMap()->setTexture(file->readString());

            // Extras
            getExtras()->setFootstepSounds(file->readString());
            getExtras()->setAutoplantObject(file->readString());

            // Repeat indices
            getBaseMap()->setRepeatIndex(file->readUnsignedInteger());
            getDetailMap()->setRepeatIndex(file->readUnsignedInteger());
            getBumpMap()->setRepeatIndex(file->readUnsignedInteger());

            // Autopaint
            getAutoPaint()->setMinHeight(file->readFloat());
            getAutoPaint()->setMaxHeight(file->readFloat());
            file->readNull(4); // unknown, float?
            getAutoPaint()->setMinSlope(file->readFloat());
            getAutoPaint()->setMaxSlope(file->readFloat());
            file->readNull(4); // unknown, uint32?
            getAutoPaint()->setCovarage(file->readFloat());
            getAutoPaint()->setNoise(file->readFloat());
            getAutoPaint()->setNoiseDetail(file->readFloat());

            // Bump map
            getBumpMap()->setMapType((TerrainMap) file->readUnsigned8());
            getBumpMap()->setHeightMapScale(file->readFloat());
            getBumpMap()->setSpecularMapTexture(file->readString());

            file->readNull(37);
        }

        void Layer::write(File::File *file) {
            file->writeBoolean(getAutoPaint()->getEnabled());

            file->writeString(getName());

            // Textures
            file->writeString(getBaseMap()->getTexture());
            file->writeString(getDetailMap()->getTexture());
            file->writeString(getBumpMap()->getTexture());

            // Extras
            file->writeString(getExtras()->getFootstepSounds());
            file->writeString(getExtras()->getAutoplantObject());

            // Repeat indices
            file->writeUnsignedInteger(getBaseMap()->getRepeatIndex());
            file->writeUnsignedInteger(getDetailMap()->getRepeatIndex());
            file->writeUnsignedInteger(getBumpMap()->getRepeatIndex());

            // Autopaint
            file->writeFloat(getAutoPaint()->getMinHeight());
            file->writeFloat(getAutoPaint()->getMaxHeight());
            file->writeNull(4); // unknown, float?
            file->writeFloat(getAutoPaint()->getMinSlope());
            file->writeFloat(getAutoPaint()->getMaxSlope());
            file->writeNull(4); // unknown, uint32?
            file->writeFloat(getAutoPaint()->getCovarage());
            file->writeFloat(getAutoPaint()->getNoise());
            file->writeFloat(getAutoPaint()->getNoiseDetail());

            // Bump map
            file->writeUnsigned8(getBumpMap()->getMapType());
            file->writeFloat(getBumpMap()->getHeightMapScale());
            file->writeString(getBumpMap()->getSpecularMapTexture());

            file->writeNull(37);
        }

        BaseMap *Layer::getBaseMap() const {
            return baseMap;
        }

        void Layer::setBaseMap(BaseMap *value) {
            baseMap = value;
        }

        DetailMap *Layer::getDetailMap() const {
            return detailMap;
        }

        void Layer::setDetailMap(DetailMap *value) {
            detailMap = value;
        }

        BumpMap *Layer::getBumpMap() const {
            return bumpMap;
        }

        void Layer::setBumpMap(BumpMap *value) {
            bumpMap = value;
        }

        AutoPaint *Layer::getAutoPaint() const {
            return autoPaint;
        }

        void Layer::setAutoPaint(AutoPaint *value) {
            autoPaint = value;
        }

        Extras *Layer::getExtras() const {
            return extras;
        }

        void Layer::setExtras(Extras *value) {
            extras = value;
        }

        std::string Layer::getName() const {
            return name;
        }

        void Layer::setName(const std::string &value) {
            name = value;
        }

        float *Layer::getPaintData() const {
            return paintData;
        }

        float Layer::getIntensityAtVertex(int32_t x, int32_t y) {
            return paintData[(vertexDimY * y) + x];
        }

        void Layer::setIntensityAtVertex(int32_t x, int32_t y, float intensity) {
            paintData[(vertexDimY * y) + x] = intensity;
        }
    }
}

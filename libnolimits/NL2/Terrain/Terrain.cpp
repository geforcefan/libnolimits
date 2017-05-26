#include "Terrain.h"
#include "../../File/MemoryFile.h"

#include <iostream>
#include <algorithm>

namespace NoLimits {
    namespace NoLimits2 {
        void Terrain::read(File::File *file) {
            layer.clear();
            textureRepeats.clear();
            terrainIntensityLayers.clear();

            file->readNull(8);

            file->readNull(8); // x y limits in int, but don´t need these, we have fix 769x769
            //setVertexDimX(file->readUnsignedInteger());
            //setVertexDimY(file->readUnsignedInteger());

            getWater()->read(file);

            uint32_t numTextureRepeats = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numTextureRepeats; i++) {
                insertTextureRepeats(file->readFloat());
            }

            file->readNull(19);

            uint32_t numberOfLayers = file->readUnsignedInteger();

            for(uint32_t i = 0; i < numberOfLayers; i++) {
                Layer *l = new Layer();
                l->read(file);
                insertLayer(l);
            }

            file->readNull(64);

            File::File *terrainDataMemoryFile = file->readCompressedFile();
            terrainDataMemoryFile->openRB();

            terrainDataMemoryFile->readNull(8); // x y sizes in int, but don´t need these, we have fix 769x769
            //setVertexDimX(terrainDataMemoryFile->readUnsignedInteger());
            //setVertexDimY(terrainDataMemoryFile->readUnsignedInteger());

            uint16_t lastAbsoluteHeight = 0;
            for (uint32_t i = 0; i < getVertexDimX() * getVertexDimY(); i++) {
                uint16_t relativeHeight = terrainDataMemoryFile->readUnsignedShort();
                uint16_t absoluteHeight = relativeHeight + lastAbsoluteHeight;

                terrainData[i] = ((int32_t)absoluteHeight - 8191) / 32.0;

                lastAbsoluteHeight = absoluteHeight;
            }

            // Intensity layers
            for (uint32_t j = 0; j < getVertexDimX() * getVertexDimY(); j++) {
                for(uint32_t i = 0; i < getNumberOfIntensityLayers(); i++) {
                    terrainIntensityLayers[i][j] = (float)terrainDataMemoryFile->readUnsigned8() / 255.0f;
                }
            }

            terrainDataMemoryFile->close();
        }

        void Terrain::write(File::File *file) {
            file->writeUnsignedInteger(0x44C00000); // wtf is this?
            file->writeUnsignedInteger(0x44C00000);

            // size limits
            file->writeUnsignedInteger(getVertexDimX() - 1);
            file->writeUnsignedInteger(getVertexDimY() - 1);

            getWater()->write(file);

            file->writeUnsignedInteger(textureRepeats.size());
            for(uint32_t i = 0; i < textureRepeats.size(); i++) {
                file->writeFloat(textureRepeats[i]);
            }

            file->writeNull(19);

            file->writeUnsignedInteger(layer.size());
            for(uint32_t i = 0; i < layer.size(); i++) {
                layer[i]->write(file);
            }

            file->writeNull(64);

            File::File *terrainDataBuffer = new File::MemoryFile();
            terrainDataBuffer->openWB();
            terrainDataBuffer->writeUnsignedInteger(getVertexDimX());
            terrainDataBuffer->writeUnsignedInteger(getVertexDimY());

            uint16_t lastAbsoluteHeight = 0;
            for (uint32_t i = 0; i < getVertexDimX() * getVertexDimY(); i++) {
                uint16_t absoluteHeight = ((terrainData[i] * 32.0f) + 8191);
                uint16_t relativeHeight = absoluteHeight - lastAbsoluteHeight;

                terrainDataBuffer->writeUnsignedShort(relativeHeight);

                lastAbsoluteHeight = absoluteHeight;
            }

            // Intensity layers
            for (uint32_t j = 0; j < getVertexDimX() * getVertexDimY(); j++) {
                for(uint32_t i = 0; i < getNumberOfIntensityLayers(); i++) {
                    terrainDataBuffer->writeUnsigned8((255.0f * terrainIntensityLayers[i][j]) / 1.0f);
                }
            }

            terrainDataBuffer->close();

            file->writeFileCompressed(terrainDataBuffer);
        }

        float Terrain::getHeightAtVertex(int32_t x, int32_t y) {
            x = std::max(std::min(x, (int)vertexDimX), 0);
            y = std::max(std::min(y, (int)vertexDimY), 0);

            return terrainData[(vertexDimY * y) + x];
        }

        void Terrain::setHeightAtVertex(int32_t x, int32_t y, float height) {
            x = std::max(std::min(x, (int)vertexDimX), 0);
            y = std::max(std::min(y, (int)vertexDimY), 0);

            terrainData[(vertexDimY * y) + x] = height;
        }

        float Terrain::getIntensityAtVertex(uint32_t index, int32_t x, int32_t y) {
            if(index >= terrainIntensityLayers.size())
                return 0.0f;

            return terrainIntensityLayers[index][(vertexDimY * y) + x];
        }

        void Terrain::setIntensityAtVertex(uint32_t index, int32_t x, int32_t y, float intensity) {
            if(index >= terrainIntensityLayers.size())
                return;

            terrainIntensityLayers[index][(vertexDimY * y) + x] = intensity;
        }

        uint32_t Terrain::getNumberOfIntensityLayers() {
            return terrainIntensityLayers.size();
        }

        Water *Terrain::getWater() const {
            return water;
        }

        void Terrain::setWater(Water *value) {
            water = value;
        }

        std::vector<float> Terrain::getTextureRepeats() const {
            return textureRepeats;
        }

        uint32_t Terrain::insertTextureRepeats(float value) {
            textureRepeats.push_back(value);
            return textureRepeats.size() - 1;
        }

        std::vector<Layer*> Terrain::getLayer() const {
            return layer;
        }

        Layer *Terrain::getLayer(std::string name) {
            if(!name.size())
                return nullptr;

            for(uint32_t i = 0; i < layer.size(); i++) {
                if(layer[i]->getName() == name)
                    return layer[i];
            }

            return nullptr;
        }

        uint32_t Terrain::insertLayer(Layer* value) {
            layer.push_back(value);

            uint32_t numberOfIntensityLayers = std::floor((layer.size() + 1) / 2.0);
            for(uint32_t i = terrainIntensityLayers.size(); i < numberOfIntensityLayers; i++) {
                float *intensityLayer = (float*) malloc(sizeof(float) * getVertexDimX() * getVertexDimY());

                for (uint32_t j = 0; j < getVertexDimX() * getVertexDimY(); j++) {
                    intensityLayer[j] = 15.0f / 255.0f;
                }

                terrainIntensityLayers.push_back(intensityLayer);
            }

            return layer.size() - 1;
        }

        uint32_t Terrain::getVertexDimX() const {
            return vertexDimX;
        }

        uint32_t Terrain::getVertexDimY() const {
            return vertexDimY;
        }
    }
}

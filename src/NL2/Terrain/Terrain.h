#ifndef LIB_NL2PARK_TERRAIN_H
#define LIB_NL2PARK_TERRAIN_H

#include <string>
#include <Stream/Chunk.h>

#include <vector>
#include <map>

#include "Water.h"
#include "Layer.h"

namespace NoLimits {
    namespace NL2 {
        class Terrain: public Stream::Chunk {
        public:
            Terrain() {
                water = new Water();

                vertexDimX = 769;
                vertexDimY = 769;

                terrainData = (float*) malloc(vertexDimX * vertexDimY * sizeof(float));

                for (uint32_t j = 0; j < getVertexDimX() * getVertexDimY(); j++) {
                    terrainData[j] = 1.0f;
                }

                insertTextureRepeats(0.004f);
                insertTextureRepeats(0.3f);
                insertTextureRepeats(0.01f);
                insertTextureRepeats(0.01f);

                insertLayer(new NoLimits::NL2::Layer());
            }

            void debug() {
                std::cout << "Terrain[getTextureRepeats.size]: " << textureRepeats.size() << std::endl;
                if(textureRepeats.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < textureRepeats.size(); i++) {
                    std::cout << "Terrain[getTextureRepeats][" << i << "]: " << textureRepeats[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Terrain[getLayer.size]: " << layer.size() << std::endl;
                if(layer.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < layer.size(); i++) {
                    layer[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                getWater()->debug();

                std::cout << "Terrain[getVertexDimX]: " << getVertexDimX() << std::endl;
                std::cout << "Terrain[getVertexDimY]: " << getVertexDimY() << std::endl;
            }

            void read(File::File *file);
            void write(File::File *file);

            Water *getWater() const;
            void setWater(Water *value);

            std::vector<float> getTextureRepeats() const;
            void insertTextureRepeats(float value);

            std::vector<Layer*> getLayer() const;
            Layer *getLayer(std::string name);
            void insertLayer(Layer* value);

            uint32_t getVertexDimX() const;
            uint32_t getVertexDimY() const;

            float getHeightAtVertex(int32_t x, int32_t y);
            void setHeightAtVertex(int32_t x, int32_t y, float height);

            float getIntensityAtVertex(uint32_t index, int32_t x, int32_t y);
            void setIntensityAtVertex(uint32_t index, int32_t x, int32_t y, float intensity);

            uint32_t getNumberOfIntensityLayers();

            std::string getChunkName() { return "TERC"; }

            void saveAsBMP(std::string filepath);
            void saveAsBMP(uint32_t index, std::string filepath);
        private:
            uint32_t vertexDimX;
            uint32_t vertexDimY;

            Water *water;
            std::vector<float> textureRepeats;
            std::vector<Layer*> layer;

            float *terrainData;
            std::vector<float *> terrainIntensityLayers;
        };
    }
}

#endif

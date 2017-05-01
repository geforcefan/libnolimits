#ifndef LAYER_H
#define LAYER_H

#include <string>
#include "BaseMap.h"
#include "DetailMap.h"
#include "BumpMap.h"
#include "AutoPaint.h"
#include "Extras.h"

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
        class Layer : public Stream::Chunk
        {
        public:
            Layer() {
                baseMap = new BaseMap();
                detailMap = new DetailMap();
                bumpMap = new BumpMap();
                autoPaint = new AutoPaint();
                extras = new Extras();

                paintData = (float*) malloc(769 * 769 * sizeof(float));

                for (uint32_t j = 0; j < 769 * 769; j++) {
                    paintData[j] = 15.0f / 255.0f;
                }

                setName("Grass");
            }

            void read(File::File *file);
            void write(File::File *file);

            BaseMap *getBaseMap() const;
            void setBaseMap(BaseMap *value);

            DetailMap *getDetailMap() const;
            void setDetailMap(DetailMap *value);

            BumpMap *getBumpMap() const;
            void setBumpMap(BumpMap *value);

            AutoPaint *getAutoPaint() const;
            void setAutoPaint(AutoPaint *value);

            Extras *getExtras() const;
            void setExtras(Extras *value);

            std::string getName() const;
            void setName(const std::string &value);

            float *getPaintData() const;

            float getIntensityAtVertex(int32_t x, int32_t y);
            void setIntensityAtVertex(int32_t x, int32_t y, float intensity);
        private:
            std::string name;

            BaseMap *baseMap;
            DetailMap *detailMap;
            BumpMap *bumpMap;
            AutoPaint *autoPaint;
            Extras *extras;

            float *paintData;
        };
    }
}

#endif // LAYER_H

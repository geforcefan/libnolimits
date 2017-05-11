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

                setName("Grass");
            }

            void debug() {
                std::cout << "Layer[getName]: " << getName() << std::endl;

                getBaseMap()->debug();
                getDetailMap()->debug();
                getBumpMap()->debug();
                getAutoPaint()->debug();
                getExtras()->debug();
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
        private:
            std::string name;

            BaseMap *baseMap;
            DetailMap *detailMap;
            BumpMap *bumpMap;
            AutoPaint *autoPaint;
            Extras *extras;
        };
    }
}

#endif // LAYER_H

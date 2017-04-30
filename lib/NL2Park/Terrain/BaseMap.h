#ifndef BASEMAP_H
#define BASEMAP_H

#include <string>

namespace Library {
    namespace NL2Park {
        class BaseMap
        {
        public:
            BaseMap() {
                setTexture("intern:data/textures/terrain/DiffuseCloudGreen.jpg");
                setRepeatIndex(0);
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

#ifndef DETAILMAP_H
#define DETAILMAP_H

#include <string>

namespace Library {
    namespace NL2Park {
        class DetailMap
        {
        public:
            DetailMap() {
                setTexture("intern:data/textures/terrain/GrassVegetation.jpg");
                setRepeatIndex(1);
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

#endif // DETAILMAP_H

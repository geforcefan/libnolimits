#include "DetailMap.h"

namespace Library {
    namespace NL2Park {
        std::string DetailMap::getTexture() const {
            return texture;
        }

        void DetailMap::setTexture(const std::string &value) {
            texture = value;
        }

        uint32_t DetailMap::getRepeatIndex() const {
            return repeatIndex;
        }

        void DetailMap::setRepeatIndex(const uint32_t &value) {
            repeatIndex = value;
        }
    }
}

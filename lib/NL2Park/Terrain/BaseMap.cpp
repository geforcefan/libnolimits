#include "BaseMap.h"

namespace Library {
    namespace NL2Park {
        std::string BaseMap::getTexture() const {
            return texture;
        }

        void BaseMap::setTexture(const std::string &value) {
            texture = value;
        }

        uint32_t BaseMap::getRepeatIndex() const {
            return repeatIndex;
        }

        void BaseMap::setRepeatIndex(const uint32_t &value) {
            repeatIndex = value;
        }
    }
}

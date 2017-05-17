#include "BaseMap.h"

namespace NoLimits {
    namespace NoLimits2 {
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

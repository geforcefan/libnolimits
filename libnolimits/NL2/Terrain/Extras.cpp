#include "Extras.h"

namespace NoLimits {
    namespace NoLimits2 {
        std::string Extras::getFootstepSounds() const {
            return footstepSounds;
        }

        void Extras::setFootstepSounds(const std::string &value) {
            footstepSounds = value;
        }

        std::string Extras::getAutoplantObject() const {
            return autoplantObject;
        }

        void Extras::setAutoplantObject(const std::string &value) {
            autoplantObject = value;
        }
    }
}

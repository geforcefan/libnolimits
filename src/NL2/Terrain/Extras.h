#ifndef EXTRAS_H
#define EXTRAS_H

#include <string>

namespace NoLimits {
    namespace NL2 {
        class Extras
        {
        public:
            Extras() {
                setFootstepSounds("intern:data/sounds/walk/grass1.wav\n"
                                  "intern:data/sounds/walk/grass2.wav\n"
                                  "intern:data/sounds/walk/grass3.wav\n"
                                  "intern:data/sounds/walk/grass4.wav\n");
                setAutoplantObject("");
            }

            std::string getFootstepSounds() const;
            void setFootstepSounds(const std::string &value);

            std::string getAutoplantObject() const;
            void setAutoplantObject(const std::string &value);

        private:
            std::string footstepSounds;
            std::string autoplantObject;
        };
    }
}

#endif // EXTRAS_H

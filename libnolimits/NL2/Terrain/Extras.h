#ifndef EXTRAS_H
#define EXTRAS_H

#include <string>
#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Extras : public Stream::Chunk
        {
        public:
            Extras() {
                setFootstepSounds("intern:data/sounds/walk/grass1.wav\n"
                                  "intern:data/sounds/walk/grass2.wav\n"
                                  "intern:data/sounds/walk/grass3.wav\n"
                                  "intern:data/sounds/walk/grass4.wav\n");
                setAutoplantObject("");
            }

            void debug() {
                std::cout << "Extras[getFootstepSounds]: " << getFootstepSounds() << std::endl;
                std::cout << "Extras[getAutoplantObject]: " << getAutoplantObject() << std::endl;
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

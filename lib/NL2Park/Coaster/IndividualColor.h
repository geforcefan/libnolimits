#ifndef LIB_NL2PARK_INDIVIDUALCOLOR_H
#define LIB_NL2PARK_INDIVIDUALCOLOR_H

#include <Stream/Chunk.h>
#include <vector>

namespace Library {
    namespace NL2Park {
        class IndividualColor: public Stream::Chunk {
        public:
            IndividualColor() {}
            void read(File::File *file);

            bool getHasIndividualColor() const;
            void setHasIndividualColor(bool value);

            glm::vec3 getCarColor() const;
            void setCarColor(const glm::vec3 &value);

            glm::vec3 getSeatColor() const;
            void setSeatColor(const glm::vec3 &value);

            glm::vec3 getHarnessColor() const;
            void setHarnessColor(const glm::vec3 &value);

            glm::vec3 getBogieColor() const;
            void setBogieColor(const glm::vec3 &value);

            glm::vec3 getChassisColor() const;
            void setChassisColor(const glm::vec3 &value);

            std::string getCarTexture1() const;
            void setCarTexture1(const std::string &value);

            std::string getCarTexture2() const;
            void setCarTexture2(const std::string &value);

        private:
            bool hasIndividualColor;

            glm::vec3 carColor;
            glm::vec3 seatColor;
            glm::vec3 harnessColor;
            glm::vec3 bogieColor;
            glm::vec3 chassisColor;

            std::string carTexture1;
            std::string carTexture2;
        };
    }
}

#endif // LIB_NL2PARK_INDIVIDUALCOLOR_H

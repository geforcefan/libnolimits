#ifndef LIB_NL2PARK_INDIVIDUALCOLOR_H
#define LIB_NL2PARK_INDIVIDUALCOLOR_H

#include "../../Stream/Chunk.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits2 {
        class IndividualColor: public Stream::Chunk {
        public:
            IndividualColor() {
                setHasIndividualColor(false);
                setCarColor(glm::vec3(0.0f));
                setSeatColor(glm::vec3(0.0f));
                setHarnessColor(glm::vec3(0.0f));
                setBogieColor(glm::vec3(0.0f));
                setChassisColor(glm::vec3(0.0f));
            }

            void debug() {
                std::cout << "IndividualColor[getHasIndividualColor]: " << getHasIndividualColor() << std::endl;
                std::cout << "IndividualColor[getCarColor]: " << Helper::debug(getCarColor()) << std::endl;
                std::cout << "IndividualColor[getSeatColor]: " << Helper::debug(getSeatColor()) << std::endl;
                std::cout << "IndividualColor[getHarnessColor]: " << Helper::debug(getHarnessColor()) << std::endl;
                std::cout << "IndividualColor[getBogieColor]: " << Helper::debug(getBogieColor()) << std::endl;
                std::cout << "IndividualColor[getChassisColor]: " << Helper::debug(getChassisColor()) << std::endl;

                std::cout << "IndividualColor[getCarTexture.size]: " << carTexture.size() << std::endl;
                if(carTexture.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < carTexture.size(); i++) {
                    std::cout << "IndividualColor[getCarTexture][" << i << "]: " << carTexture[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            void write(File::File *file);
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

            std::vector<std::string> getCarTexture() const;
            void insertCarTexture(std::string value);

        private:
            bool hasIndividualColor;

            glm::vec3 carColor;
            glm::vec3 seatColor;
            glm::vec3 harnessColor;
            glm::vec3 bogieColor;
            glm::vec3 chassisColor;

            std::vector<std::string> carTexture;

            std::string getChunkName() { return "INDC"; }
        };
    }
}

#endif // LIB_NL2PARK_INDIVIDUALCOLOR_H

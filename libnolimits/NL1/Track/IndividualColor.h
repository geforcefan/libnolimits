#ifndef LIB_NOLIMITS_NL1_INDIVIDUALCOLOR_H
#define LIB_NOLIMITS_NL1_INDIVIDUALCOLOR_H

#include "../../Stream/Chunk.h"
#include <vector>

namespace NoLimits {
    namespace NoLimits1 {
        class IndividualColor: public Stream::Chunk {
        public:
            IndividualColor() {
                setHasIndividualColor(false);
            }

            void debug() {
                std::cout << "IndividualColor[getHasIndividualColor]: " << getHasIndividualColor() << std::endl;
                std::cout << "IndividualColor[getTexture]: " << getTexture() << std::endl;
                std::cout << "IndividualColor[getSeatColor]: " << Helper::debug(getSeatColor()) << std::endl;
                std::cout << "IndividualColor[getRestraintColor]: " << Helper::debug(getRestraintColor()) << std::endl;
                std::cout << "IndividualColor[getTrainColor]: " << Helper::debug(getTrainColor()) << std::endl;
                std::cout << "IndividualColor[getGearColor]: " << Helper::debug(getGearColor()) << std::endl;
            }

            /*! \cond INTERNAL */
            void write(File::File *file);
            void read(File::File *file);
            /*! \endcond */

            bool getHasIndividualColor() const;
            void setHasIndividualColor(bool value);

            const glm::vec3 &getSeatColor() const;
            void setSeatColor(const glm::vec3 &value);

            const glm::vec3 &getRestraintColor() const;
            void setRestraintColor(const glm::vec3 &value);

            const glm::vec3 &getTrainColor() const;
            void setTrainColor(const glm::vec3 &value);

            const glm::vec3 &getGearColor() const;
            void setGearColor(const glm::vec3 &value);

            const std::string &getTexture() const;
            void setTexture(const std::string &value);

        private:
            bool hasIndividualColor;

            glm::vec3 seatColor;
            glm::vec3 restraintColor;
            glm::vec3 trainColor;
            glm::vec3 gearColor;

            std::string texture;
        };
    }
}

#endif // LIB_NOLIMITS_NL1_INDIVIDUALCOLOR_H

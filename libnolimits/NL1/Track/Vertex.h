#ifndef LIB_NOLIMITS_NL1_VERTEX_H
#define LIB_NOLIMITS_NL1_VERTEX_H

#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits1 {
        class Vertex : public Stream::Chunk {
        public:
            Vertex() {
                setPosition(glm::vec3(0.0f));
                setControlPoint1(glm::vec3(0.0f));
                setControlPoint2(glm::vec3(0.0f));
                setRoll(0.0f);
                setContinuousRoll(false);
                setRelativeRoll(false);
                setEqualDistance(false);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Vertex[getPosition]: " << Helper::debug(getPosition()) << std::endl;
                std::cout << "Vertex[getControlPoint1]: " << Helper::debug(getControlPoint1()) << std::endl;
                std::cout << "Vertex[getControlPoint2]: " << Helper::debug(getControlPoint2()) << std::endl;
                std::cout << "Vertex[getRoll]: " << getRoll() << std::endl;
                std::cout << "Vertex[getContinuousRoll]: " << getContinuousRoll() << std::endl;
                std::cout << "Vertex[getRelativeRoll]: " << getRelativeRoll() << std::endl;
                std::cout << "Vertex[getEqualDistance]: " << getEqualDistance() << std::endl;
            }

            const glm::vec3 &getPosition() const;
            void setPosition(const glm::vec3 &position);

            const glm::vec3 &getControlPoint1() const;
            void setControlPoint1(const glm::vec3 &value);

            const glm::vec3 &getControlPoint2() const;
            void setControlPoint2(const glm::vec3 &value);

            float getRoll() const;
            void setRoll(float roll);

            bool getContinuousRoll() const;
            void setContinuousRoll(bool continuousRoll);

            bool getRelativeRoll() const;
            void setRelativeRoll(bool relativeRoll);

            bool getEqualDistance() const;
            void setEqualDistance(bool equalDistance);

        private:
            glm::vec3 position;
            glm::vec3 controlPoint1;
            glm::vec3 controlPoint2;
            float roll;
            bool continuousRoll;
            bool relativeRoll;
            bool equalDistance;
        };
    }
}

#endif // LIB_NL2PARK_VERTEX_H

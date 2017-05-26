#ifndef LIB_NL2PARK_SEGMENT_H
#define LIB_NL2PARK_SEGMENT_H

#include "../Colors.h"
#include "WoodenSupportGenerator.h"
#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Segment : public Stream::Chunk {
        public:
            enum Tunnel {
                None,
                Steel,
                Wooden,
                RoundConcrete,
                RectangularConcrete,
                Virtual
            };

            enum TieSpacing {
                LowestStress,
                LowerStress,
                LowStress,
                Normal,
                HighStress,
                HighestStress
            };

            Segment() {
                woodenSupportGenerator = new WoodenSupportGenerator();

                setInvisibleSegment(false);

                setLeftRailingAndCatwalk(false);
                setLeftRailingLights(false);
                setLeftRailingLightsColor(glm::vec3(255.0f));

                setRightRailingAndCatwalk(false);
                setRightRailingLights(false);
                setRightRailingLightsColor(glm::vec3(255.0f));

                setTransparentCatwalks(false);
                setUseRailsColor(false);
                setUseCrossTiesColor(false);
                setUseMainSpineColor(false);
                setUseHandrailsColor(false);
                setUseCatwalksColor(false);

                setRailColor(glm::vec3(255.0f));
                setCrossTiesColor(glm::vec3(255.0f));
                setMainSpineColor(glm::vec3(255.0f));
                setHandrailsColor(glm::vec3(255.0f));
                setCatwalksColor(glm::vec3(255.0f));

                setUseSpineColorScheme(false);
                setTunnel(Tunnel::None);
                setSpineType(0);
                setTieSpacing(TieSpacing::LowestStress);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Segment[getInvisibleSegment]: " << getInvisibleSegment() << std::endl;

                std::cout << "Segment[getLeftRailingAndCatwalk]: " << getLeftRailingAndCatwalk() << std::endl;
                std::cout << "Segment[getLeftRailingLights]: " << getLeftRailingLights() << std::endl;
                std::cout << "Segment[getLeftRailingLightsColor]: " << Helper::debug(getLeftRailingLightsColor()) << std::endl;

                std::cout << "Segment[getRightRailingAndCatwalk]: " << getRightRailingAndCatwalk() << std::endl;
                std::cout << "Segment[getRightRailingLights]: " << getRightRailingLights() << std::endl;
                std::cout << "Segment[getRightRailingLightsColor]: " << Helper::debug(getRightRailingLightsColor()) << std::endl;

                std::cout << "Segment[getTransparentCatwalks]: " << getTransparentCatwalks() << std::endl;

                std::cout << "Segment[getUseRailsColor]: " << getUseRailsColor() << std::endl;
                std::cout << "Segment[getUseCrossTiesColor]: " << getUseCrossTiesColor() << std::endl;
                std::cout << "Segment[getUseMainSpineColor]: " << getUseMainSpineColor() << std::endl;
                std::cout << "Segment[getUseHandrailsColor]: " << getUseHandrailsColor() << std::endl;
                std::cout << "Segment[getUseCatwalksColor]: " << getUseCatwalksColor() << std::endl;

                std::cout << "Segment[getRailColor]: " << Helper::debug(getRailColor()) << std::endl;
                std::cout << "Segment[getCrossTiesColor]: " << Helper::debug(getCrossTiesColor()) << std::endl;
                std::cout << "Segment[getMainSpineColor]: " << Helper::debug(getMainSpineColor()) << std::endl;
                std::cout << "Segment[getHandrailsColor]: " << Helper::debug(getHandrailsColor()) << std::endl;
                std::cout << "Segment[getCatwalksColor]: " << Helper::debug(getCatwalksColor()) << std::endl;

                std::cout << "Segment[getUseSpineColorScheme]: " << getUseSpineColorScheme() << std::endl;
                std::cout << "Segment[getSpineColorScheme]: " << getSpineColorScheme() << std::endl;

                std::cout << "Segment[getTunnel]: " << getTunnel() << std::endl;
                std::cout << "Segment[getSpineType]: " << getSpineType() << std::endl;
                std::cout << "Segment[getTieSpacing]: " << getTieSpacing() << std::endl;

                getWoodenSupportGenerator()->debug();
            }

            bool getInvisibleSegment() const;
            void setInvisibleSegment(bool value);

            bool getLeftRailingAndCatwalk() const;
            void setLeftRailingAndCatwalk(bool value);

            bool getLeftRailingLights() const;
            void setLeftRailingLights(bool value);

            glm::vec3 getLeftRailingLightsColor() const;
            void setLeftRailingLightsColor(const glm::vec3 &value);

            bool getRightRailingAndCatwalk() const;
            void setRightRailingAndCatwalk(bool value);

            bool getRightRailingLights() const;
            void setRightRailingLights(bool value);

            glm::vec3 getRightRailingLightsColor() const;
            void setRightRailingLightsColor(const glm::vec3 &value);

            bool getTransparentCatwalks() const;
            void setTransparentCatwalks(bool value);

            bool getUseRailsColor() const;
            void setUseRailsColor(bool value);

            bool getUseCrossTiesColor() const;
            void setUseCrossTiesColor(bool value);

            bool getUseMainSpineColor() const;
            void setUseMainSpineColor(bool value);

            bool getUseHandrailsColor() const;
            void setUseHandrailsColor(bool value);

            bool getUseCatwalksColor() const;
            void setUseCatwalksColor(bool value);

            glm::vec3 getRailColor() const;
            void setRailColor(const glm::vec3 &value);

            glm::vec3 getCrossTiesColor() const;
            void setCrossTiesColor(const glm::vec3 &value);

            glm::vec3 getMainSpineColor() const;
            void setMainSpineColor(const glm::vec3 &value);

            glm::vec3 getHandrailsColor() const;
            void setHandrailsColor(const glm::vec3 &value);

            glm::vec3 getCatwalksColor() const;
            void setCatwalksColor(const glm::vec3 &value);

            bool getUseSpineColorScheme() const;
            void setUseSpineColorScheme(bool value);

            Colors::SpineColorScheme getSpineColorScheme() const;
            void setSpineColorScheme(const Colors::SpineColorScheme &value);

            Tunnel getTunnel() const;
            void setTunnel(const Tunnel &value);

            uint8_t getSpineType() const;
            void setSpineType(const uint8_t &value);

            TieSpacing getTieSpacing() const;
            void setTieSpacing(const TieSpacing &value);

            WoodenSupportGenerator *getWoodenSupportGenerator() const;

            /*! \cond INTERNAL */
            std::string getChunkName() { return "SEGM"; }
            /*! \endcond */
        private:
            bool invisibleSegment;

            bool leftRailingAndCatwalk;
            bool leftRailingLights;
            glm::vec3 leftRailingLightsColor;

            bool rightRailingAndCatwalk;
            bool rightRailingLights;
            glm::vec3 rightRailingLightsColor;

            bool transparentCatwalks;

            bool useRailsColor;
            bool useCrossTiesColor;
            bool useMainSpineColor;
            bool useHandrailsColor;
            bool useCatwalksColor;

            glm::vec3 railColor;
            glm::vec3 crossTiesColor;
            glm::vec3 mainSpineColor;
            glm::vec3 handrailsColor;
            glm::vec3 catwalksColor;

            bool useSpineColorScheme;
            Colors::SpineColorScheme spineColorScheme;

            Tunnel tunnel;
            uint8_t spineType;
            TieSpacing tieSpacing;

            WoodenSupportGenerator *woodenSupportGenerator;
        };
    }
}

#endif // LIB_NL2PARK_SEGMENT_H

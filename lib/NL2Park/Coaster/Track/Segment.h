#ifndef LIB_NL2PARK_SEGMENT_H
#define LIB_NL2PARK_SEGMENT_H

#include <lib/NL2Park/Coaster/Colors.h>
#include <lib/NL2Park/Coaster/Track/WoodenSupportGenerator.h>
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
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
            }

            void read(File::File *file);

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

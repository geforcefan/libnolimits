#ifndef LIB_NL2PARK_SUPPORTNODE_H
#define LIB_NL2PARK_SUPPORTNODE_H

#include "../../../Nolimits.h"

namespace NoLimits {
    namespace NoLimits2 {
        class SupportNode
        {
        public:
            enum Flags {
                NoCapsForLODsHint = 0,
                DimAsIfItWasInATunnel = 1,
                NoStartCapHint = 4,
                NoEndCapHint = 5,
                RotationModeAzimuth = 6
            };

            enum ColorMode {
                CustomColor,
                SupportColor,
                HandrailsColor,
                CatwalkColor,
                SpineColor
            };

            SupportNode() {
                setHasNoCapsForLODsHint(false);
                setHasDimAsIfItWasInATunnel(false);
                setHasNoStartCapHint(false);
                setHasNoEndCapHint(false);
                setHasRotationModeAzimuth(false);
                setColorMode(ColorMode::SupportColor);
                setColor(glm::vec3(255.0f, 255.0f, 255.0f));
            }

            void debug() {
                std::cout << "SupportNode[getHasNoCapsForLODsHint]: " << getHasNoCapsForLODsHint() << std::endl;
                std::cout << "SupportNode[getHasDimAsIfItWasInATunnel]: " << getHasDimAsIfItWasInATunnel() << std::endl;
                std::cout << "SupportNode[getHasNoStartCapHint]: " << getHasNoStartCapHint() << std::endl;
                std::cout << "SupportNode[getHasNoEndCapHint]: " << getHasNoEndCapHint() << std::endl;
                std::cout << "SupportNode[getHasRotationModeAzimuth]: " << getHasRotationModeAzimuth() << std::endl;
                std::cout << "SupportNode[getColorMode]: " << getColorMode() << std::endl;
                std::cout << "SupportNode[getColor]: " << Helper::debug(getColor()) << std::endl;
            }

            bool getHasNoCapsForLODsHint();
            bool getHasDimAsIfItWasInATunnel();
            bool getHasNoStartCapHint();
            bool getHasNoEndCapHint();
            bool getHasRotationModeAzimuth();

            void setHasNoCapsForLODsHint(bool state);
            void setHasDimAsIfItWasInATunnel(bool state);
            void setHasNoStartCapHint(bool state);
            void setHasNoEndCapHint(bool state);
            void setHasRotationModeAzimuth(bool state);

            glm::vec3 getColor() const;
            void setColor(const glm::vec3 &value);

            ColorMode getColorMode();
            void setColorMode(ColorMode value);

            void setFlag1(const uint8_t &value);
            void setFlag2(const uint8_t &value);
            void setFlag3(const uint8_t &value);

        protected:
            bool hasFlag1(uint8_t flag);
            bool hasFlag2(uint8_t flag);
            bool hasFlag3(uint8_t flag);

            void setWithCheckFlag1(uint8_t flag, bool state);
            void setWithCheckFlag2(uint8_t flag, bool state);
            void setWithCheckFlag3(uint8_t flag, bool state);

            uint8_t flag1;
            uint8_t flag2;
            uint8_t flag3;

        private:
            glm::vec3 color;
        };
    }
}

#endif // LIB_NL2PARK_SUPPORTNODE_H

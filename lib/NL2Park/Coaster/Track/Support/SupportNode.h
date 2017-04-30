#ifndef LIB_NL2PARK_SUPPORTNODE_H
#define LIB_NL2PARK_SUPPORTNODE_H

#include <lib/nolimits.h>

namespace Library {
    namespace NL2Park {
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

        private:
            glm::vec3 color;
            ColorMode colorMode;
            uint8_t flag1;
            uint8_t flag2;
            uint8_t flag3;
        };
    }
}

#endif // LIB_NL2PARK_SUPPORTNODE_H

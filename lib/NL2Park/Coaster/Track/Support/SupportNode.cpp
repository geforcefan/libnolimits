#include "SupportNode.h"

namespace Library {
    namespace NL2Park {
        bool SupportNode::getHasNoCapsForLODsHint() {
            return hasFlag1(SupportNode::Flags::NoCapsForLODsHint);
        }

        bool SupportNode::getHasDimAsIfItWasInATunnel() {
            return hasFlag1(SupportNode::Flags::DimAsIfItWasInATunnel);
        }

        bool SupportNode::getHasNoStartCapHint() {
            return hasFlag1(SupportNode::Flags::NoStartCapHint);
        }

        bool SupportNode::getHasNoEndCapHint() {
            return hasFlag1(SupportNode::Flags::NoEndCapHint);
        }

        bool SupportNode::getHasRotationModeAzimuth() {
            return hasFlag1(SupportNode::Flags::RotationModeAzimuth);
        }

        void SupportNode::setHasNoCapsForLODsHint(bool state) {
            return setWithCheckFlag1(SupportNode::Flags::NoCapsForLODsHint, state);
        }

        void SupportNode::setHasDimAsIfItWasInATunnel(bool state) {
            return setWithCheckFlag1(SupportNode::Flags::DimAsIfItWasInATunnel, state);
        }

        void SupportNode::setHasNoStartCapHint(bool state) {
            return setWithCheckFlag1(SupportNode::Flags::NoStartCapHint, state);
        }

        void SupportNode::setHasNoEndCapHint(bool state) {
            return setWithCheckFlag1(SupportNode::Flags::NoEndCapHint, state);
        }

        void SupportNode::setHasRotationModeAzimuth(bool state) {
            return setWithCheckFlag1(SupportNode::Flags::RotationModeAzimuth, state);
        }

        glm::vec3 SupportNode::getColor() const  {
            return color;
        }

        void SupportNode::setColor(const glm::vec3 &value) {
            color = value;
        }

        SupportNode::ColorMode SupportNode::getColorMode() {
            if(hasFlag3(4) && !hasFlag3(5))
                return SupportNode::ColorMode::SupportColor;
            else if(hasFlag3(5) && !hasFlag3(4))
                return SupportNode::ColorMode::HandrailsColor;
            else if(hasFlag3(4) && hasFlag3(5))
                return SupportNode::ColorMode::CatwalkColor;
            else if(hasFlag3(6))
                return SupportNode::ColorMode::SpineColor;
            else
                return SupportNode::ColorMode::CustomColor;
        }

        void SupportNode::setColorMode(SupportNode::ColorMode value)  {
            colorMode = value;

            setWithCheckFlag3(4, false);
            setWithCheckFlag3(5, false);
            setWithCheckFlag3(6, false);

            switch(value) {
                case SupportNode::ColorMode::SpineColor:
                    setWithCheckFlag3(6, true);
                    break;
                case SupportNode::ColorMode::CatwalkColor:
                    setWithCheckFlag3(4, true);
                    setWithCheckFlag3(5, true);
                    break;
                case SupportNode::ColorMode::HandrailsColor:
                    setWithCheckFlag3(5, true);
                    break;
                case SupportNode::ColorMode::SupportColor:
                    setWithCheckFlag3(4, true);
                    break;
                case SupportNode::ColorMode::CustomColor:
                    break;
            }

            colorMode = getColorMode();
        }

        void SupportNode::setFlag1(const uint8_t &value) {
            flag1 = value;
            colorMode = getColorMode();
        }

        void SupportNode::setFlag2(const uint8_t &value) {
            flag2 = value;
            colorMode = getColorMode();
        }

        void SupportNode::setFlag3(const uint8_t &value) {
            flag3 = value;
            colorMode = getColorMode();
        }

        bool SupportNode::hasFlag1(uint8_t flag) {
            return flag1 & (1 << flag) ? true : false;
        }

        bool SupportNode::hasFlag2(uint8_t flag) {
            return flag2 & (1 << flag) ? true : false;
        }

        bool SupportNode::hasFlag3(uint8_t flag) {
            return flag3 & (1 << flag) ? true : false;
        }

        void SupportNode::setWithCheckFlag1(uint8_t flag, bool state) {
            if (state && !hasFlag1(flag)) {
                flag1 |= 1 << flag;
            } else if (!state && hasFlag1(flag)) {
                flag1 &= ~(1 << flag);
            }
        }

        void SupportNode::setWithCheckFlag2(uint8_t flag, bool state) {
            if (state && !hasFlag2(flag)) {
                flag2 |= 1 << flag;
            } else if (!state && hasFlag2(flag)) {
                flag2 &= ~(1 << flag);
            }
        }

        void SupportNode::setWithCheckFlag3(uint8_t flag, bool state) {
            if (state && !hasFlag3(flag)) {
                flag3 |= 1 << flag;
            } else if (!state && hasFlag3(flag)) {
                flag3 &= ~(1 << flag);
            }
        }
    }
}

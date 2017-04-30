#include "WoodenSupportGenerator.h"

namespace Library {
    namespace NL2Park {
        void WoodenSupportGenerator::read(File::File *file) {
            setFlag1(file->readUnsigned8());
            setFlag2(file->readUnsigned8());
        }

        bool WoodenSupportGenerator::getUseIndividualSettings() {
            return hasFlag2(Flag::IndividualSettings);
        }

        bool WoodenSupportGenerator::getUseLeftWideSupports() {
            return hasFlag2(Flag::WideSupportsLeft);
        }

        bool WoodenSupportGenerator::getUseRightWideSupports() {
            return hasFlag2(Flag::WideSupportsRight);
        }

        bool WoodenSupportGenerator::getUseLeftCatwalks() {
            return hasFlag2(Flag::CatwalksLeft);
        }

        bool WoodenSupportGenerator::getUseRightCatwalks() {
            return hasFlag2(Flag::CatwalksRight);
        }

        bool WoodenSupportGenerator::getUseLeftHandrails() {
            return hasFlag2(Flag::HandrailsLeft);
        }

        bool WoodenSupportGenerator::getUseRightHandrails() {
            return hasFlag2(Flag::HandrailsRight);
        }

        bool WoodenSupportGenerator::getCollisionDetection() {
            return hasFlag2(Flag::CollisionDetection);
        }

        bool WoodenSupportGenerator::getEnableSupports() {
            return hasFlag1(0);
        }

        void WoodenSupportGenerator::setUseIndividualSettings(bool state) {
            setWithCheckFlag2(Flag::IndividualSettings, state);
        }

        void WoodenSupportGenerator::setUseLeftWideSupports(bool state) {
            setWithCheckFlag2(Flag::WideSupportsLeft, state);
        }

        void WoodenSupportGenerator::setUseRightWideSupports(bool state) {
            setWithCheckFlag2(Flag::WideSupportsRight, state);
        }

        void WoodenSupportGenerator::setUseLeftCatwalks(bool state) {
            setWithCheckFlag2(Flag::CatwalksLeft, state);
        }

        void WoodenSupportGenerator::setUseRightCatwalks(bool state) {
            setWithCheckFlag2(Flag::CatwalksRight, state);
        }

        void WoodenSupportGenerator::setUseLeftHandrails(bool state) {
            setWithCheckFlag2(Flag::HandrailsLeft, state);
        }

        void WoodenSupportGenerator::setUseRightHandrails(bool state) {
            setWithCheckFlag2(Flag::HandrailsRight, state);
        }

        void WoodenSupportGenerator::setCollisionDetection(bool state) {
            setWithCheckFlag2(Flag::CollisionDetection, state);
        }

        void WoodenSupportGenerator::setEnableSupports(bool state) {
            setWithCheckFlag1(0, state);
        }

        void WoodenSupportGenerator::setBentSpacing(WoodenSupportGenerator::BentSpacing spacing) {
            setWithCheckFlag1(1, false);
            setWithCheckFlag1(2, false);

            switch (spacing) {
                case BentSpacing::Spacing625Ft:
                    setWithCheckFlag1(1, true);
                    break;
                case BentSpacing::Spacing45Ft:
                    setWithCheckFlag1(2, true);
                    break;
                case BentSpacing::Spacing9Ft:
                    break;
            }
        }

        WoodenSupportGenerator::BentSpacing WoodenSupportGenerator::getBentSpacing() {
            WoodenSupportGenerator::BentSpacing spacing;

            if (!hasFlag1(1) && !hasFlag1(2)) {
                spacing = WoodenSupportGenerator::BentSpacing::Spacing9Ft;
            }

            if (hasFlag1(1) && !hasFlag1(2)) {
                spacing = WoodenSupportGenerator::BentSpacing::Spacing625Ft;
            }

            if (!hasFlag1(1) && hasFlag1(2)) {
                spacing = WoodenSupportGenerator::BentSpacing::Spacing45Ft;
            }

            return spacing;
        }

        void WoodenSupportGenerator::setFlag1(const uint8_t &value) {
            flag1 = value;
        }

        void WoodenSupportGenerator::setFlag2(const uint8_t &value) {
            flag2 = value;
        }

        bool WoodenSupportGenerator::hasFlag1(uint8_t flag) {
            return flag1 & (1 << flag) ? true : false;
        }

        bool WoodenSupportGenerator::hasFlag2(uint8_t flag) {
            return flag2 & (1 << flag) ? true : false;
        }

        void WoodenSupportGenerator::setWithCheckFlag1(uint8_t flag, bool state) {
            if (state && !hasFlag1(flag)) {
                flag1 |= 1 << flag;
            } else if (!state && hasFlag1(flag)) {
                flag1 &= ~(1 << flag);
            }
        }

        void WoodenSupportGenerator::setWithCheckFlag2(uint8_t flag, bool state) {
            if (state && !hasFlag2(flag)) {
                flag2 |= 1 << flag;
            } else if (!state && hasFlag2(flag)) {
                flag2 &= ~(1 << flag);
            }
        }
    }
}

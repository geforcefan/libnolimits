#include "Segment.h"

namespace Library {
    namespace NL2Park {
        void Segment::read(File::File *file) {
            setUseMainSpineColor(file->readBoolean());
            setRailColor(file->readColor());
            setCrossTiesColor(file->readColor());
            setMainSpineColor(file->readColor());

            setTunnel((Tunnel)file->readUnsigned8());

            setLeftRailingAndCatwalk(file->readBoolean());
            setRightRailingAndCatwalk(file->readBoolean());

            setSpineType(file->readUnsigned8());

            setSpineColorScheme((Colors::SpineColorScheme)file->readUnsigned8());
            setInvisibleSegment(file->readBoolean());
            file->readNull(2);

            getWoodenSupportGenerator()->read(file);

            setHandrailsColor(file->readColor());
            setCatwalksColor(file->readColor());

            setTransparentCatwalks(file->readBoolean());
            setUseRailsColor(file->readBoolean());
            setUseCrossTiesColor(file->readBoolean());
            setUseHandrailsColor(file->readBoolean());
            setUseCatwalksColor(file->readBoolean());
            setUseSpineColorScheme(file->readBoolean());

            setLeftRailingLights(file->readBoolean());
            setLeftRailingLightsColor(file->readColor());

            setRightRailingLights(file->readBoolean());
            setRightRailingLightsColor(file->readColor());
        }

        bool Segment::getInvisibleSegment() const {
            return invisibleSegment;
        }

        void Segment::setInvisibleSegment(bool value) {
            invisibleSegment = value;
        }

        bool Segment::getLeftRailingAndCatwalk() const {
            return leftRailingAndCatwalk;
        }

        void Segment::setLeftRailingAndCatwalk(bool value) {
            leftRailingAndCatwalk = value;
        }

        bool Segment::getLeftRailingLights() const {
            return leftRailingLights;
        }

        void Segment::setLeftRailingLights(bool value) {
            leftRailingLights = value;
        }

        glm::vec3 Segment::getLeftRailingLightsColor() const {
            return leftRailingLightsColor;
        }

        void Segment::setLeftRailingLightsColor(const glm::vec3 &value) {
            leftRailingLightsColor = value;
        }

        bool Segment::getRightRailingAndCatwalk() const {
            return rightRailingAndCatwalk;
        }

        void Segment::setRightRailingAndCatwalk(bool value) {
            rightRailingAndCatwalk = value;
        }

        bool Segment::getRightRailingLights() const {
            return rightRailingLights;
        }

        void Segment::setRightRailingLights(bool value) {
            rightRailingLights = value;
        }

        glm::vec3 Segment::getRightRailingLightsColor() const {
            return rightRailingLightsColor;
        }

        void Segment::setRightRailingLightsColor(const glm::vec3 &value) {
            rightRailingLightsColor = value;
        }

        bool Segment::getTransparentCatwalks() const {
            return transparentCatwalks;
        }

        void Segment::setTransparentCatwalks(bool value) {
            transparentCatwalks = value;
        }

        bool Segment::getUseRailsColor() const {
            return useRailsColor;
        }

        void Segment::setUseRailsColor(bool value) {
            useRailsColor = value;
        }

        bool Segment::getUseCrossTiesColor() const {
            return useCrossTiesColor;
        }

        void Segment::setUseCrossTiesColor(bool value) {
            useCrossTiesColor = value;
        }

        bool Segment::getUseMainSpineColor() const {
            return useMainSpineColor;
        }

        void Segment::setUseMainSpineColor(bool value) {
            useMainSpineColor = value;
        }

        bool Segment::getUseHandrailsColor() const {
            return useHandrailsColor;
        }

        void Segment::setUseHandrailsColor(bool value) {
            useHandrailsColor = value;
        }

        bool Segment::getUseCatwalksColor() const {
            return useCatwalksColor;
        }

        void Segment::setUseCatwalksColor(bool value) {
            useCatwalksColor = value;
        }

        glm::vec3 Segment::getRailColor() const {
            return railColor;
        }

        void Segment::setRailColor(const glm::vec3 &value) {
            railColor = value;
        }

        glm::vec3 Segment::getCrossTiesColor() const {
            return crossTiesColor;
        }

        void Segment::setCrossTiesColor(const glm::vec3 &value) {
            crossTiesColor = value;
        }

        glm::vec3 Segment::getMainSpineColor() const {
            return mainSpineColor;
        }

        void Segment::setMainSpineColor(const glm::vec3 &value) {
            mainSpineColor = value;
        }

        glm::vec3 Segment::getHandrailsColor() const {
            return handrailsColor;
        }

        void Segment::setHandrailsColor(const glm::vec3 &value) {
            handrailsColor = value;
        }

        glm::vec3 Segment::getCatwalksColor() const {
            return catwalksColor;
        }

        void Segment::setCatwalksColor(const glm::vec3 &value) {
            catwalksColor = value;
        }

        bool Segment::getUseSpineColorScheme() const {
            return useSpineColorScheme;
        }

        void Segment::setUseSpineColorScheme(bool value) {
            useSpineColorScheme = value;
        }

        Colors::SpineColorScheme Segment::getSpineColorScheme() const {
            return spineColorScheme;
        }

        void Segment::setSpineColorScheme(const Colors::SpineColorScheme &value) {
            spineColorScheme = value;
        }

        Segment::Tunnel Segment::getTunnel() const {
            return tunnel;
        }

        void Segment::setTunnel(const Segment::Tunnel &value) {
            tunnel = value;
        }

        uint8_t Segment::getSpineType() const {
            return spineType;
        }

        void Segment::setSpineType(const uint8_t &value) {
            spineType = value;
        }

        Segment::TieSpacing Segment::getTieSpacing() const {
            return tieSpacing;
        }

        void Segment::setTieSpacing(const Segment::TieSpacing &value) {
            tieSpacing = value;
        }

        WoodenSupportGenerator *Segment::getWoodenSupportGenerator() const {
            return woodenSupportGenerator;
        }
    }
}

#include "SwitchTrack.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        void SwitchTrack::readSpecialTrack(File::File *file) {
            setDirection((SwitchTrack::Direction)file->readUnsignedInteger());
            setStyle((SwitchTrack::Style)file->readUnsignedInteger());
            setDefaultTrack(file->readUnsignedInteger());

            setDisplayStructure((SpecialTrack::DisplayStructure)file->readUnsigned8());

            file->readNull(27);
        }

        void SwitchTrack::writeSpecialTrack(File::File *file) {
            file->writeUnsignedInteger(getDirection());
            file->writeUnsignedInteger(getStyle());
            file->writeUnsignedInteger(getDefaultTrack());
            file->writeUnsigned8(getDisplayStructure());

            file->writeNull(27);
        }

        SwitchTrack::Direction SwitchTrack::getDirection() const {
            return direction;
        }

        void SwitchTrack::setDirection(const SwitchTrack::Direction &value) {
            direction = value;
        }

        SwitchTrack::Style SwitchTrack::getStyle() const {
            return style;
        }

        void SwitchTrack::setStyle(const SwitchTrack::Style &value) {
            style = value;
        }

        SpecialTrack::DisplayStructure SwitchTrack::getDisplayStructure() const {
            return displayStructure;
        }

        void SwitchTrack::setDisplayStructure(const SpecialTrack::DisplayStructure &value) {
            displayStructure = value;
        }

        uint32_t SwitchTrack::getDefaultTrack() const {
            return defaultTrack;
        }

        void SwitchTrack::setDefaultTrack(const uint32_t &value) {
            defaultTrack = value;
        }
    }
}

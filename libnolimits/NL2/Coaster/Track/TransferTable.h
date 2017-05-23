#ifndef LIB_NL2PARK_SWITCH_TRANSFER_TABLE_H
#define LIB_NL2PARK_SWITCH_TRANSFER_TABLE_H

#include <vector>

#include "SpecialTrack.h"
#include "Section/Section.h"

namespace NoLimits {
    namespace NoLimits2 {
        class TransferTable: public SpecialTrack  {
        public:
            TransferTable() : SpecialTrack(SpecialTrack::SpecialTrackType::Transfer) {
                section = new Section();
            }

            void readSpecialTrack(File::File *file);
            void writeSpecialTrack(File::File *file);

            uint32_t getDefaultTrack() const;
            void setDefaultTrack(const uint32_t &value);

            double getLength() const;
            void setLength(double value);

            double getDistance() const;
            void setDistance(double value);

            SpecialTrack::DisplayStructure getDisplayStructure() const;
            void setDisplayStructure(const SpecialTrack::DisplayStructure &value);

            Section *getSection() const;
            void setSection(Section *value);

            std::string getSpecialTrackChunkName() { return "TRTB"; }

        private:
            uint32_t defaultTrack;
            double length;
            double distance;
            SpecialTrack::DisplayStructure displayStructure;

            Section *section;
        };
    }
}

#endif // LIB_NL2PARK_SWITCH_TRANSFER_TABLE_H

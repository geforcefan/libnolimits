#ifndef LIB_NL2PARK_SWITCH_TRANSFER_TABLE_H
#define LIB_NL2PARK_SWITCH_TRANSFER_TABLE_H

#include <vector>

#include "SpecialTrack.h"
#include "Section/Section.h"
#include "Segment.h"

namespace NoLimits {
    namespace NoLimits2 {
        class TransferTable: public SpecialTrack  {
        public:
            TransferTable() : SpecialTrack(SpecialTrack::SpecialTrackType::Transfer) {
                section = new Section();

                setDefaultTrack(0);
                setLength(20.0f);
                setDistance(3.0f);
                setDisplayStructure(SpecialTrack::DisplayStructure::Simple);

                insertInput(0);
                insertInput(0);
                insertInput(0);

                insertOutput(0);
                insertOutput(0);
                insertOutput(0);

                setSwitchTime(15.0f);

                insertSegment(new Segment());
            }

            /*! \cond INTERNAL */
            void readSpecialTrack(File::File *file);
            void writeSpecialTrack(File::File *file);
            /*! \endcond */

            void debug() {
                SpecialTrack::debug();

                std::cout << "TransferTable[getDefaultTrack]: " << getDefaultTrack() << std::endl;
                std::cout << "TransferTable[getLength]: " << getLength() << std::endl;
                std::cout << "TransferTable[getDistance]: " << getDistance() << std::endl;
                std::cout << "TransferTable[getDisplayStructure]: " << getDisplayStructure() << std::endl;

                getSection()->debug();
            }

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

            /*! \cond INTERNAL */
            std::string getSpecialTrackChunkName() { return "TRTB"; }
            /*! \endcond */

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

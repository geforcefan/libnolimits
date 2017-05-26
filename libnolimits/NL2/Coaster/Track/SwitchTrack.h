#ifndef LIB_NL2PARK_SWITCH_TRACK_H
#define LIB_NL2PARK_SWITCH_TRACK_H

#include <vector>

#include "SpecialTrack.h"
#include "Segment.h"

namespace NoLimits {
    namespace NoLimits2 {
        class SwitchTrack: public SpecialTrack  {
        public:
            enum SwitchType {
                Fork,
                Merge
            };

            enum Direction {
                LeftRight,
                StraightLeft,
                StraightRight
            };

            enum Style {
                ShiftHorizontally,
                RotateVertically,
                RotateHorizontally
            };

            SwitchTrack(SwitchType switchType) : SpecialTrack() {
                switch(switchType) {
                case SwitchType::Merge:
                    setSpecialTrackType(SpecialTrack::SpecialTrackType::SwitchTrackMerge);

                    insertInput(0);
                    insertInput(0);

                    insertOutput(0);
                    break;
                case SwitchType::Fork:
                default:
                    setSpecialTrackType(SpecialTrack::SpecialTrackType::SwitchTrackFork);

                    insertOutput(0);
                    insertOutput(0);

                    insertInput(0);
                    break;
                }

                insertSegment(new Segment());
                insertSegment(new Segment());

                setSwitchTime(5.0f);
            }

            void debug() {
                SpecialTrack::debug();

                std::cout << "SwitchTrack[getDirection]: " << getDirection() << std::endl;
                std::cout << "SwitchTrack[getStyle]: " << getStyle() << std::endl;
                std::cout << "SwitchTrack[getDisplayStructure]: " << getDisplayStructure() << std::endl;
                std::cout << "SwitchTrack[getDefaultTrack]: " << getDefaultTrack() << std::endl;
            }

            Direction getDirection() const;
            void setDirection(const Direction &value);

            Style getStyle() const;
            void setStyle(const Style &value);

            DisplayStructure getDisplayStructure() const;
            void setDisplayStructure(const DisplayStructure &value);

            uint32_t getDefaultTrack() const;
            void setDefaultTrack(const uint32_t &value);

            /*! \cond INTERNAL */
            void readSpecialTrack(File::File *file);
            void writeSpecialTrack(File::File *file);

            std::string getSpecialTrackChunkName() { return "SWTR"; }
            /*! \endcond */
        private:
            Direction direction;
            Style style;
            DisplayStructure displayStructure;

            uint32_t defaultTrack;
        };
    }
}

#endif // LIB_NL2PARK_SWITCH_TRACK_H

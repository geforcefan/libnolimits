#ifndef LIB_NL2PARK_TRACK_H
#define LIB_NL2PARK_TRACK_H

#include <Stream/Chunk.h>
#include "Section/Section.h"

namespace Library {
    namespace NL2Park {
        class Track {
        public:
            enum TrackType {
                None,
                Custom,
                SpecialTrack
            };

            Track(TrackType trackType) : _trackType(trackType) {}
            Track() : _trackType(TrackType::None) {}
            TrackType getTrackType() const;
            void setTrackType(const TrackType &value);
            virtual Section *getSectionByName(std::string name) { return NULL; }
        private:
            TrackType _trackType;
        };
    }
}

#endif // TRACK_H

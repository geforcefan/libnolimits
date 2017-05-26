#include "Track.h"

namespace NoLimits {
    namespace NoLimits2 {
        Track::TrackType Track::getTrackType() const {
            return trackType;
        }

        void Track::setTrackType(const Track::TrackType &value) {
            trackType = value;
        }
    }
}

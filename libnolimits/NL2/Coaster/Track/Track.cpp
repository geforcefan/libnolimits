#include "Track.h"

namespace NoLimits {
    namespace NoLimits2 {
        Track::TrackType Track::getTrackType() const {
            return _trackType;
        }

        void Track::setTrackType(const Track::TrackType &value) {
            _trackType = value;
        }
    }
}

#include "Track.h"

namespace Library {
    namespace NL2Park {
        Track::TrackType Track::getTrackType() const {
            return _trackType;
        }

        void Track::setTrackType(const Track::TrackType &value) {
            _trackType = value;
        }
    }
}

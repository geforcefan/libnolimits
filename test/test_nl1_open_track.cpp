#include <iostream>
#include <libnolimits.h>

using namespace NoLimits::NoLimits1;

int main() {
    NoLimitsTrack *track = new NoLimitsTrack("nl1/track.nltrack");
    track->debug();
    track->save("nl1/track.open_track.nltrack");

    return 0;
}

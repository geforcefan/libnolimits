#include <iostream>
#include <libnolimits.h>

using namespace NoLimits::NoLimits2;

int main() {
    Park *park = new Park("nl2/park.nl2park");
    Coaster *coaster = park->getCoaster("TestCoaster1");

    coaster->getSupport()->removeFreeNode(0);

    park->save("nl2/park.beam_remove.nl2park");

    return 0;
}

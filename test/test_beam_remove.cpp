#include <iostream>
#include <libnolimits.h>

using namespace NoLimits::NoLimits2;

int main() {
    Park *park = new Park("test/TestPark/TestPark.nl2park");
    Coaster *coaster = park->getCoaster("TestCoaster1");

    coaster->getSupport()->removeFreeNode(0);

    park->save("test/TestPark/TestPark.beam_remove.nl2park");

    return 0;
}

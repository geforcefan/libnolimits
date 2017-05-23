#include <iostream>
#include <libnolimits.h>

int main() {
    NoLimits::NoLimits2::Park *park = new NoLimits::NoLimits2::Park("/Users/ercanakyurek/Desktop/TestCoaster/parks/Hydra/Hydra.nl2park");
    park->save("/Users/ercanakyurek/Desktop/TestCoaster/Hydra.clone.nl2park");
    return 0;
}

#include <iostream>
#include <src/NL2/Park.h>

using namespace std;

int main(int argc, char *argv[])
{
    NoLimits::NL2::Park *park = new NoLimits::NL2::Park("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.new2.nl2park");
    park->save("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.cloned.nl2park");

    /*NoLimits::NL2::Park *park2 = new NoLimits::NL2::Park();
    park2->getInfo()->setAuthor("Vanessa Akyürek");
    park2->getInfo()->setDescription("Test Coaster");
    park2->save("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.new.nl2park");
*/

    park->debug();

    return 0;
}

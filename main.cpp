#include <iostream>
#include <lib/NL2Park/Park.h>

using namespace std;

int main(int argc, char *argv[])
{
    Library::NL2Park::Park *park = new Library::NL2Park::Park("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.new2.nl2park");
    park->save("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.cloned.nl2park");

    /*Library::NL2Park::Park *park2 = new Library::NL2Park::Park();
    park2->getInfo()->setAuthor("Vanessa Akyürek");
    park2->getInfo()->setDescription("Test Coaster");
    park2->save("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.new.nl2park");

    park->debug();*/

    return 0;
}

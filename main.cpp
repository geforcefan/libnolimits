#include <iostream>
#include <src/NL2/Park.h>

using namespace std;

int main(int argc, char *argv[])
{
    NoLimits::NL2::Park *park = new NoLimits::NL2::Park("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.nl2park");
    park->save("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.cloned.nl2park");

    NoLimits::NL2::Park *park3 = new NoLimits::NL2::Park("/Users/ercanakyurek/Desktop/TestCoaster/Hydra.nl2park");
    park3->save("/Users/ercanakyurek/Desktop/TestCoaster/Hydra.cloned.nl2park");

    /*park->getTerrain()->saveAsBMP("/Users/ercanakyurek/Desktop/TestCoaster/TerrainData/TestCoaster.Terrain.bmp");

    for(uint32_t i = 0; i < park->getTerrain()->getNumberOfIntensityLayers(); i++) {
        std::string filepath = "/Users/ercanakyurek/Desktop/TestCoaster/TerrainData/TestCoaster.";
        filepath.append(std::to_string(i));
        filepath.append(".bmp");

        park->getTerrain()->saveAsBMP(i, filepath.c_str());
    }
*/
    NoLimits::NL2::Park *park2 = new NoLimits::NL2::Park();
    park2->getInfo()->setAuthor("Vanessa Akyürek");
    park2->getInfo()->setDescription("Test Coaster");

    NoLimits::NL2::FreeNode *f = new NoLimits::NL2::FreeNode();
    f->setPosition(glm::vec3(10.0, 10.0f, 10.0f));

    NoLimits::NL2::Coaster *c = new NoLimits::NL2::Coaster();
    c->getSupport()->insertFreeNode(f);
    park2->insertCoaster(c);

    park2->save("/Users/ercanakyurek/Desktop/TestCoaster/HandMade.nl2park");

    park2->getTerrain()->saveAsBMP("/Users/ercanakyurek/Desktop/TestCoaster/TestCoaster.Terrain.bmp");
    //park->debug();

    return 0;
}

#include <iostream>
#include <libnolimits.h>

int main() {
    NoLimits::NoLimits2::Park *park = new NoLimits::NoLimits2::Park();

    park->getInfo()->setAuthor("Ercan Akyürek");
    park->getInfo()->setDescription("Test Description");

    park->save("Test.nl2park");

    std::cout << "Author: " << park->getInfo()->getAuthor() << std::endl;
    std::cout << "Description: " << park->getInfo()->getDescription() << std::endl;

    return 0;
}
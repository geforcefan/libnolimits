#include <iostream>
#include <libnolimits.h>

using namespace NoLimits::NoLimits2;

int main() {
    Park *park = new Park();

    Coaster *coaster = new Coaster("TestCoaster");
    park->insertCoaster(coaster);

    //////////////////////////////////////////////////////////////////////
    CustomTrack *track1 = new CustomTrack();

    track1->insertVertex(new Vertex(glm::vec4(0.0f, 11.0f, 1.0f, 1.0f), false, false));
    track1->insertVertex(new Vertex(glm::vec4(0.0f, 6.0f, 6.0f, 1.0f), false, false));

    uint32_t track1Index = coaster->insertTrack(track1);
    //////////////////////////////////////////////////////////////////////
    uint32_t freeNode1Index = coaster->getSupport()->insertFreeNode(new FreeNode(glm::vec3(0.0f, 10.0f, 0.0f)));
    uint32_t freeNode2Index = coaster->getSupport()->insertFreeNode(new FreeNode(glm::vec3(5.0f, 5.0f, 5.0f)));
    //////////////////////////////////////////////////////////////////////
    Beam *beam1 = new Beam();
    beam1->setConnection1(new FreeNodeConnection(freeNode1Index));
    beam1->setConnection2(new FreeNodeConnection(freeNode2Index));
    uint32_t beam1Index = coaster->getSupport()->insertBeam(beam1);
    //////////////////////////////////////////////////////////////////////
    uint32_t beamNode1Index = beam1->insertBeamNode(new BeamNode(0.25f));
    uint32_t beamNode2Index = beam1->insertBeamNode(new BeamNode(0.75f));
    //////////////////////////////////////////////////////////////////////
    uint32_t railConnectorIndex = track1->insertRailConnector(new RailConnector(0.5f));
    //////////////////////////////////////////////////////////////////////
    Beam *beam2 = new Beam();
    beam2->setConnection1(new BeamNodeConnection(beam1Index, beamNode1Index));
    beam2->setConnection2(new RailConnectorConnection(track1Index, railConnectorIndex, 0));
    uint32_t beam2Index = coaster->getSupport()->insertBeam(beam2);

    Beam *beam3 = new Beam();
    beam3->setConnection1(new BeamNodeConnection(beam1Index, beamNode2Index));
    beam3->setConnection2(new RailConnectorConnection(track1Index, railConnectorIndex, 0));
    uint32_t beam3Index = coaster->getSupport()->insertBeam(beam3);


    park->save("nl2/park.custom_park.nl2park");
    return 0;
}

#include <NL2/Coaster/Track/CustomTrack.h>
#include <iostream>

namespace NoLimits {
    namespace NL2 {
        CustomTrack::CustomTrack() : Track(TrackType::Custom) {
            firstRollPoint = new RollPoint();
            lastRollPoint = new RollPoint();
            segment = new Segment();
            section = new Section();
        }

        void CustomTrack::read(File::File *file) {
            setClosed(file->readBoolean());

            getFirstRollPoint()->setPosition(0.0);
            getFirstRollPoint()->setRoll(file->readDouble());
            getFirstRollPoint()->setVertical(file->readBoolean());
            getFirstRollPoint()->setStrict(true);

            getLastRollPoint()->setRoll(file->readDouble());
            getLastRollPoint()->setVertical(file->readBoolean());
            getLastRollPoint()->setStrict(true);

            file->readNull(53);

            uint32_t numberOfControlPoints = file->readUnsignedInteger();
            getLastRollPoint()->setPosition(numberOfControlPoints - 1);

            for (uint32_t i = 0; i < numberOfControlPoints; i++) {
                Vertex *vertex = new Vertex();
                vertex->read(file);
                insertVertex(vertex);
            }

            file->readNull(60);

            for(int i=0; i <= file->tell(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "ROLL") {
                    RollPoint *_rollPoint = new RollPoint();
                    insertRollPoint(_rollPoint);

                    file->readChunk(_rollPoint);
                    i = file->tell() - 1;
                }

                if(chunk == "TTRG") {
                    Trigger *_trigger = new Trigger();
                    insertTrigger(_trigger);

                    file->readChunk(_trigger);
                    i = file->tell() - 1;
                }

                if(chunk == "SEGM") {
                    Segment *_segment = new Segment();
                    setSegment(_segment);

                    file->readChunk(_segment);
                    i = file->tell() - 1;
                }

                if(chunk == "SECT") {
                    Section *_section = new Section();
                    file->readChunk(_section);

                    setSection(_section->getSection());
                    i = file->tell() - 1;
                }

                if(chunk == "4DPM") {
                    Parameter4D *_parameter4D = new Parameter4D();
                    insertParameter4D(_parameter4D);

                    file->readChunk(_parameter4D);
                    i = file->tell() - 1;
                }

                if(chunk == "SRNP") {
                    RailNode *_railNode = new RailNode();
                    insertRailNode(_railNode);

                    file->readChunk(_railNode);
                    i = file->tell() - 1;
                }

                if(chunk == "SEPA") {
                    Separator *_separator = new Separator();
                    insertSeparator(_separator);

                    file->readChunk(_separator);
                    i = file->tell() - 1;
                }
            }
        }

        void CustomTrack::write(File::File *file) {
            file->writeBoolean(getClosed());

            file->writeDouble(getFirstRollPoint()->getRoll());
            file->writeBoolean(getFirstRollPoint()->getVertical());

            file->writeDouble(getLastRollPoint()->getRoll());
            file->writeBoolean(getLastRollPoint()->getVertical());

            file->writeNull(53);

            file->writeUnsignedInteger(vertex.size());

            for (uint32_t i = 0; i < vertex.size(); i++) {
                vertex[i]->write(file);
            }

            file->writeNull(60);

            for(uint32_t i = 0; i < rollPoint.size(); i++) {
                file->writeChunk(rollPoint[i]);
            }

            for(uint32_t i = 0; i < separator.size(); i++) {
                file->writeChunk(separator[i]);
            }

            for(uint32_t i = 0; i < parameter4D.size(); i++) {
                file->writeChunk(parameter4D[i]);
            }

            for(uint32_t i = 0; i < trigger.size(); i++) {
                file->writeChunk(trigger[i]);
            }

            for(uint32_t i = 0; i < railNode.size(); i++) {
                file->writeChunk(railNode[i]);
            }

            file->writeChunk(getSegment());

            // usually we use file->writeChunk, but ONLY in this case we need to "WRAP" the writing
            // process, because sections are nestes with its subtypes (lift, station, etc...) and I didn´t
            // wanted to separate section and its subtypes (how the file format internally suggests)
            getSection()->writeChunk(file);
        }

        bool CustomTrack::getClosed() const {
            return closed;
        }

        void CustomTrack::setClosed(bool value) {
            closed = value;
        }

        RollPoint *CustomTrack::getFirstRollPoint() const {
            return firstRollPoint;
        }

        RollPoint *CustomTrack::getLastRollPoint() const {
            return lastRollPoint;
        }

        std::vector<Vertex*> CustomTrack::getVertex() const {
            return vertex;
        }

        void CustomTrack::insertVertex(Vertex *value) {
            vertex.push_back(value);
        }

        std::vector<RollPoint *> CustomTrack::getRollPoint() const {
            return rollPoint;
        }

        void CustomTrack::insertRollPoint(RollPoint *value) {
            rollPoint.push_back(value);
        }

        std::vector<Trigger *> CustomTrack::getTrigger() const {
            return trigger;
        }

        void CustomTrack::insertTrigger(Trigger* value) {
            trigger.push_back(value);
        }

        std::vector<RailNode*> CustomTrack::getRailNode() const {
            return railNode;
        }

        void CustomTrack::insertRailNode(RailNode* value) {
            railNode.push_back(value);
        }

        std::vector<Parameter4D*> CustomTrack::getParameter4D() const {
            return parameter4D;
        }

        void CustomTrack::insertParameter4D(Parameter4D* value) {
            parameter4D.push_back(value);
        }

        std::vector<Separator *> CustomTrack::getSeparator() const {
            return separator;
        }

        void CustomTrack::insertSeparator(Separator* value) {
            separator.push_back(value);
        }

        Segment *CustomTrack::getSegment() const {
            return segment;
        }

        void CustomTrack::setSegment(Segment *value) {
            segment = value;
        }

        Section *CustomTrack::getSection() const {
            return section;
        }

        void CustomTrack::setSection(Section *value) {
            section = value;
        }

        Section *CustomTrack::getSectionByName(std::string name) {
            if(section->getName() == name)
                return section;

            for(int i = separator.size() - 1; i >= 0; i--) {
                if(separator[i]->getSection()->getName() == name)
                    return separator[i]->getSection();
            }

            return nullptr;
        }
    }
}

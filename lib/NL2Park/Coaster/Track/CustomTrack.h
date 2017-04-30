#ifndef LIB_NL2PARK_CUSTOM_TRACK_H
#define LIB_NL2PARK_CUSTOM_TRACK_H

#include <vector>

#include <Stream/Chunk.h>
#include <lib/NL2Park/Coaster/Track/Track.h>
#include <lib/NL2Park/Coaster/Track/RollPoint.h>
#include <lib/NL2Park/Coaster/Track/Vertex.h>
#include <lib/NL2Park/Coaster/Track/Trigger.h>
#include <lib/NL2Park/Coaster/Track/Parameter4D.h>
#include <lib/NL2Park/Coaster/Track/Segment.h>
#include <lib/NL2Park/Coaster/Track/Separator.h>
#include <lib/NL2Park/Coaster/Track/Section/Section.h>
#include <lib/NL2Park/Coaster/Track/Support/RailNode.h>

namespace Library {
    namespace NL2Park {
        class CustomTrack: public Stream::Chunk, public Track  {
        public:
            CustomTrack();
            void read(File::File *file);

            RollPoint *getFirstRollPoint() const;
            RollPoint *getLastRollPoint() const;

            std::vector<Vertex*> getVertex() const;
            void insertVertex(Vertex *value);

            std::vector<RollPoint*> getRollPoint() const;
            void insertRollPoint(RollPoint* value);

            std::vector<Trigger*> getTrigger() const;
            void insertTrigger(Trigger* value);

            std::vector<RailNode*> getRailNode() const;
            void insertRailNode(RailNode* value);

            std::vector<Parameter4D*> getParameter4D() const;
            void insertParameter4D(Parameter4D* value);

            std::vector<Separator*> getSeparator() const;
            void insertSeparator(Separator* value);

            Segment *getSegment() const;
            void setSegment(Segment *value);

            Section *getSection() const;
            void setSection(Section *value);

            virtual Section *getSectionByName(std::string);
        private:
            std::vector<Vertex*> vertex;
            std::vector<RollPoint*> rollPoint;
            std::vector<Trigger*> trigger;
            std::vector<RailNode*> railNode;
            std::vector<Parameter4D*> parameter4D;
            std::vector<Separator*> separator;

            RollPoint *firstRollPoint;
            RollPoint *lastRollPoint;

            Segment *segment;
            Section *section;
        };
    }
}

#endif // LIB_NL2PARK_CUSTOM_TRACK_H

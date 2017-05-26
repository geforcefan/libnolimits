#ifndef LIB_NL2PARK_CUSTOM_TRACK_H
#define LIB_NL2PARK_CUSTOM_TRACK_H

#include <vector>

#include "../../../Stream/Chunk.h"
#include "Track.h"
#include "RollPoint.h"
#include "Vertex.h"
#include "Trigger.h"
#include "Parameter4D.h"
#include "Segment.h"
#include "Separator.h"
#include "Section/Section.h"
#include "../Support/RailConnector.h"

namespace NoLimits {
    namespace NoLimits2 {
        class CustomTrack: public Track  {
        public:
            CustomTrack() : Track(TrackType::Custom) {
                firstRollPoint = new RollPoint();
                lastRollPoint = new RollPoint();
                segment = new Segment();
                section = new Section();

                setClosed(false);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                Track::debug();

                std::cout << "CustomTrack[getClosed]: " << getClosed() << std::endl;
                std::cout << "CustomTrack[getFirstRollPoint]: " << std::endl;
                getFirstRollPoint()->debug();

                std::cout << "Coaster[vertex.size]: " << vertex.size() << std::endl;
                if(vertex.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < vertex.size(); i++) {
                    vertex[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Coaster[rollPoint.size]: " << rollPoint.size() << std::endl;
                if(rollPoint.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < rollPoint.size(); i++) {
                    rollPoint[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Coaster[trigger.size]: " << trigger.size() << std::endl;
                if(trigger.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < trigger.size(); i++) {
                    trigger[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Coaster[railConnector.size]: " << railConnector.size() << std::endl;
                if(railConnector.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < railConnector.size(); i++) {
                    railConnector[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Coaster[parameter4D.size]: " << parameter4D.size() << std::endl;
                if(parameter4D.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < parameter4D.size(); i++) {
                    parameter4D[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Coaster[separator.size]: " << separator.size() << std::endl;
                if(separator.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < separator.size(); i++) {
                    separator[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                getSegment()->debug();
                getSection()->debug();

                std::cout << "CustomTrack[getLastRollPoint]: " << std::endl;
                getLastRollPoint()->debug();
            }

            RollPoint *getFirstRollPoint() const;
            RollPoint *getLastRollPoint() const;

            std::vector<Vertex*> getVertex() const;
            uint32_t insertVertex(Vertex *value);

            std::vector<RollPoint*> getRollPoint() const;
            uint32_t insertRollPoint(RollPoint* value);

            std::vector<Trigger*> getTrigger() const;
            uint32_t insertTrigger(Trigger* value);

            std::vector<RailConnector*> getRailConnector() const;
            uint32_t insertRailConnector(RailConnector* value);

            std::vector<Parameter4D*> getParameter4D() const;
            uint32_t insertParameter4D(Parameter4D* value);

            std::vector<Separator*> getSeparator() const;
            uint32_t insertSeparator(Separator* value);

            Segment *getSegment() const;
            void setSegment(Segment *value);

            Section *getSection() const;
            void setSection(Section *value);

            bool getClosed() const;
            void setClosed(bool value);

            virtual Section *getSectionByName(std::string);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "CUTK"; }
            /*! \endcond */
        private:
            std::vector<Vertex*> vertex;
            std::vector<RollPoint*> rollPoint;
            std::vector<Trigger*> trigger;
            std::vector<RailConnector*> railConnector;
            std::vector<Parameter4D*> parameter4D;
            std::vector<Separator*> separator;

            RollPoint *firstRollPoint;
            RollPoint *lastRollPoint;

            Segment *segment;
            Section *section;

            bool closed;
        };
    }
}

#endif // LIB_NL2PARK_CUSTOM_TRACK_H

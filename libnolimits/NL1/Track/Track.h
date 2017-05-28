#ifndef LIB_NOLIMITS_NL1_TRACK_H
#define LIB_NOLIMITS_NL1_TRACK_H

#include "../../Nolimits.h"
#include "../../Stream/Chunk.h"
#include "../Info/Info.h"
#include "Train.h"
#include "Vertex.h"
#include "Colors.h"
#include "Section/Section.h"
#include <string>

namespace NoLimits {
    namespace NoLimits1 {
        class Track : public Stream::Chunk {
        public:
            enum CoasterStyle {
                ClassicLooping = 0,
                Corkscrew = 1,
                Inverted2Seat = 2,
                TwistedSteel = 3,
                Inverted4Seat = 4,
                Hypercoaster = 5,
                Floorless = 6,
                StandUp = 7,
                Hypercoaster4Seat = 8,
                WoodenTrailored2Seat = 9,
                WoodenClassic4Seat = 10,
                WoodenClassic6Seat = 11,
                WoodenTrailored4Seat = 12,
                LIMLaunched = 13,
                InvertedFaceToFace = 14,
                InvertedImpulse = 15,
                VekomaFlyingDutchman = 18,
                MaurerSpinning = 20,
                GerstlauerEuroFighter = 36,
                VekomaMotorBike = 38,
                GerstlauerBobsled = 39,
                GerstlauerSpinning = 41,
                GerstlauerEuroFighter2 = 47,
                ModernLooping = 49
            };

            enum TrackMode {
                Continious,
                Shuttle
            };

            Track() {
                setInfo(new Info());
                setColors(new Colors());
            }

            void debug() {
                getInfo()->debug();
                getColors()->debug();

                std::cout << "Track[getTrackMode]: " << getTrackMode() << std::endl;
                std::cout << "Track[getCoasterStyle]: " << getCoasterStyle() << std::endl;

                std::cout << "Track[getTrain.size]: " << train.size() << std::endl;
                if(train.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < train.size(); i++) {
                    train[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }

                std::cout << "Track[getVertex.size]: " << vertex.size() << std::endl;
                if(vertex.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < vertex.size(); i++) {
                    vertex[i]->debug();
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            Info *getInfo() const;
            void setInfo(Info *info);

            CoasterStyle getCoasterStyle() const;
            void setCoasterStyle(CoasterStyle value);

            const std::vector<Train *, std::allocator<Train *>> &getTrain() const;
            void insertTrain(Train* value);

            const std::vector<Vertex *, std::allocator<Vertex *>> &getVertex() const;
            void insertVertex(Vertex *value);

            const std::vector<Section *, std::allocator<Section *>> &getSection() const;
            void insertSection(Section* value);

            uint32_t getNumberOfCarsPerTrain() const;
            void setNumberOfCarsPerTrain(uint32_t value);

            Colors *getColors() const;
            void setColors(Colors *value);

            TrackMode getTrackMode() const;
            void setTrackMode(TrackMode value);

            bool getClosed() const;
            void setClosed(bool closed);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "TRCK"; }
            /*! \endcond */
        private:
            Info *info;
            CoasterStyle coasterStyle;
            TrackMode trackMode;
            Colors *colors;
            std::vector<Train*> train;
            std::vector<Vertex*> vertex;
            std::vector<Section*> section;

            uint32_t numberOfCarsPerTrain;

            bool closed;
        };
    }
}


#endif //LIB_NOLIMITS_NL1_TRACK_H

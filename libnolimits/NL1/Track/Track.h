#ifndef LIB_NOLIMITS_NL1_TRACK_H
#define LIB_NOLIMITS_NL1_TRACK_H

#include "../../Nolimits.h"
#include "../../Stream/Chunk.h"
#include "../Info/Info.h"
#include "Train.h"
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

            Track() {
                setInfo(new Info());
            }

            void debug() {
                getInfo()->debug();
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

            uint32_t getNumberOfCarsPerTrain() const;
            void setNumberOfCarsPerTrain(uint32_t value);

            std::string getChunkName() { return "TRCK"; }
        private:
            Info *info;
            CoasterStyle coasterStyle;
            std::vector<Train *> train;

            uint32_t numberOfCarsPerTrain;
        };
    }
}


#endif //LIB_NOLIMITS_NL1_TRACK_H

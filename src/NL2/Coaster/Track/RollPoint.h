#ifndef LIB_NL2PARK_ROLLPOINT_H
#define LIB_NL2PARK_ROLLPOINT_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class RollPoint : public Stream::Chunk {
        public:
            RollPoint() {}

            void read(File::File *file);
            void write(File::File *file);

            double getPosition() const;
            void setPosition(double value);

            double getRoll() const;
            void setRoll(double value);

            bool getVertical() const;
            void setVertical(bool value);

            bool getStrict() const;
            void setStrict(bool value);

            std::string getChunkName() { return "ROLL"; }
        private:
            double position;
            double roll;
            bool vertical;
            bool strict;
        };
    }
}

#endif // LIB_NL2PARK_ROLLPOINT_H

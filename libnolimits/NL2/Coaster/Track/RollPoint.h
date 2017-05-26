#ifndef LIB_NL2PARK_ROLLPOINT_H
#define LIB_NL2PARK_ROLLPOINT_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class RollPoint : public Stream::Chunk {
        public:
            RollPoint() {
                setPosition(0.0f);
                setRoll(0.0f);
                setVertical(false);
                setStrict(false);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "RollPoint[getPosition]: " << getPosition() << std::endl;
                std::cout << "RollPoint[getRoll]: " << getRoll() << std::endl;
                std::cout << "RollPoint[getVertical]: " << getVertical() << std::endl;
                std::cout << "RollPoint[getStrict]: " << getStrict() << std::endl;
            }

            double getPosition() const;
            void setPosition(double value);

            double getRoll() const;
            void setRoll(double value);

            bool getVertical() const;
            void setVertical(bool value);

            bool getStrict() const;
            void setStrict(bool value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "ROLL"; }
            /*! \endcond */
        private:
            double position;
            double roll;
            bool vertical;
            bool strict;
        };
    }
}

#endif // LIB_NL2PARK_ROLLPOINT_H

#ifndef LIB_NL2PARK_PARAMETER4D_H
#define LIB_NL2PARK_PARAMETER4D_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Parameter4D : public Stream::Chunk {
        public:
            Parameter4D() {
                setPosition(0.0f);
                setAngle(0.0f);
            }

            Parameter4D(double position, double angle) {
                setPosition(position);
                setAngle(angle);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "RollPoint[getPosition]: " << getPosition() << std::endl;
                std::cout << "RollPoint[getAngle]: " << getAngle() << std::endl;
            }

            double getPosition() const;
            void setPosition(double value);

            double getAngle() const;
            void setAngle(double value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "4DPM"; }
            /*! \endcond */
        private:
            double position;
            double angle;
        };
    }
}

#endif // LIB_NL2PARK_PARAMETER4D_H

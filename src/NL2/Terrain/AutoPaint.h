#ifndef AUTOPAINT_H
#define AUTOPAINT_H

#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NL2 {
        class AutoPaint : public Stream::Chunk
        {
        public:
            AutoPaint() {
                setEnabled(false);
                setCovarage(1.0f);
                setMaxHeight(1000.0f);
                setMinHeight(-50.0f);
                setMaxSlope(90.0f);
                setMinSlope(0.0f);
                setNoise(0.0f);
                setNoiseDetail(1.0f);
            }

            void debug() {
                std::cout << "AutoPaint[getEnabled]: " << getEnabled() << std::endl;
                std::cout << "AutoPaint[getCovarage]: " << getCovarage() << std::endl;
                std::cout << "AutoPaint[getMaxHeight]: " << getMaxHeight() << std::endl;
                std::cout << "AutoPaint[getMinHeight]: " << getMinHeight() << std::endl;
                std::cout << "AutoPaint[getMinSlope]: " << getMinSlope() << std::endl;
                std::cout << "AutoPaint[getMaxSlope]: " << getMaxSlope() << std::endl;
                std::cout << "AutoPaint[getNoise]: " << getNoise() << std::endl;
                std::cout << "AutoPaint[getNoiseDetail]: " << getNoiseDetail() << std::endl;
            }

            bool getEnabled() const;
            void setEnabled(bool value);

            float getCovarage() const;
            void setCovarage(float value);

            float getMaxHeight() const;
            void setMaxHeight(float value);

            float getMinHeight() const;
            void setMinHeight(float value);

            float getMinSlope() const;
            void setMinSlope(float value);

            float getMaxSlope() const;
            void setMaxSlope(float value);

            float getNoise() const;
            void setNoise(float value);

            float getNoiseDetail() const;
            void setNoiseDetail(float value);

        private:
            bool enabled;

            float covarage;

            float maxHeight;
            float minHeight;

            float minSlope;
            float maxSlope;

            float noise;
            float noiseDetail;
        };
    }
}

#endif // AUTOPAINT_H

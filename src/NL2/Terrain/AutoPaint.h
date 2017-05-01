#ifndef AUTOPAINT_H
#define AUTOPAINT_H

namespace NoLimits {
    namespace NL2 {
        class AutoPaint
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

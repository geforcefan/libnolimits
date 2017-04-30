#include "AutoPaint.h"

namespace Library {
    namespace NL2Park {
        bool AutoPaint::getEnabled() const {
            return enabled;
        }

        void AutoPaint::setEnabled(bool value) {
            enabled = value;
        }

        float AutoPaint::getCovarage() const {
            return covarage;
        }

        void AutoPaint::setCovarage(float value) {
            covarage = value;
        }

        float AutoPaint::getMaxHeight() const {
            return maxHeight;
        }

        void AutoPaint::setMaxHeight(float value) {
            maxHeight = value;
        }

        float AutoPaint::getMinHeight() const {
            return minHeight;
        }

        void AutoPaint::setMinHeight(float value) {
            minHeight = value;
        }

        float AutoPaint::getMinSlope() const {
            return minSlope;
        }

        void AutoPaint::setMinSlope(float value) {
            minSlope = value;
        }

        float AutoPaint::getMaxSlope() const {
            return maxSlope;
        }

        void AutoPaint::setMaxSlope(float value) {
            maxSlope = value;
        }

        float AutoPaint::getNoise() const {
            return noise;
        }

        void AutoPaint::setNoise(float value) {
            noise = value;
        }

        float AutoPaint::getNoiseDetail() const {
            return noiseDetail;
        }

        void AutoPaint::setNoiseDetail(float value) {
            noiseDetail = value;
        }
    }
}

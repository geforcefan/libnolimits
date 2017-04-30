#include <NL2Park/Info/Weather.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Weather::read(File::File *file) {
           setOverwriteDefaultWeather(file->readBoolean());
           setRainIntensity(file->readFloat());
           setSnowIntensity(file->readFloat());
           setWindIntensity(Weather::convertWindIntensity(file->readFloat(), true));
           setFogIntensity(Weather::convertFogIntensity(file->readFloat(), true));
           setCloudsIntensity(file->readFloat());
           setOvercastIntensity(file->readFloat());
           setThunderIntensity(file->readFloat());
        }

        void Weather::write(File::File *file)  {
            file->writeBoolean(getOverwriteDefaultWeather());
            file->writeFloat(getRainIntensity());
            file->writeFloat(getSnowIntensity());
            file->writeFloat(Weather::convertWindIntensity(getWindIntensity(), false));
            file->writeFloat(Weather::convertFogIntensity(getFogIntensity(), false));
            file->writeFloat(getCloudsIntensity());
            file->writeFloat(getOvercastIntensity());
            file->writeFloat(getThunderIntensity());
        }

        bool Weather::getOverwriteDefaultWeather() const {
            return overwriteDefaultWeather;
        }

        void Weather::setOverwriteDefaultWeather(bool value) {
            overwriteDefaultWeather = value;
        }

        float Weather::getThunderIntensity() const {
            return thunderIntensity;
        }

        void Weather::setThunderIntensity(float value) {
            thunderIntensity = value;
        }

        float Weather::getCloudsIntensity() const {
            return cloudsIntensity;
        }

        void Weather::setCloudsIntensity(float value) {
            cloudsIntensity = value;
        }

        float Weather::getOvercastIntensity() const {
            return overcastIntensity;
        }

        void Weather::setOvercastIntensity(float value) {
            overcastIntensity = value;
        }

        float Weather::getWindIntensity() const {
            return windIntensity;
        }

        void Weather::setWindIntensity(float value) {
            windIntensity = value;
        }

        float Weather::getFogIntensity() const {
            return fogIntensity;
        }

        void Weather::setFogIntensity(float value) {
            fogIntensity = value;
        }

        float Weather::getSnowIntensity() const {
            return snowIntensity;
        }

        void Weather::setSnowIntensity(float value) {
            snowIntensity = value;
        }

        float Weather::getRainIntensity() const {
            return rainIntensity;
        }

        void Weather::setRainIntensity(float value) {
            rainIntensity = value;
        }

        float Weather::convertWindIntensity(float value, bool fromWindIntensity) {
            return value;

            // @TODO: its not a linear value, ask ole for formula. range = 0 - 0.05
            if (fromWindIntensity) {
                return (1.0f * value) / 34.7519f;
            } else {
                return (34.7519f * value) / 1.0f;
            }
        }

        float Weather::convertFogIntensity(float value, bool fromFogIntensity) {
            return value;

            // @TODO: its not a linear value, ask ole for formula. range = 0 - 34.7519
            if (fromFogIntensity) {
                return (1.0f * value) / 0.05f;
            } else {
                return (0.05f * value) / 1.0f;
            }
        }
    }
}

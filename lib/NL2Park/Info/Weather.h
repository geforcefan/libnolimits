#ifndef LIB_NL2PARK_WEATHER_H
#define LIB_NL2PARK_WEATHER_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Weather: public Stream::Chunk {
        public:
            Weather() : Stream::Chunk::Chunk() {
                setOverwriteDefaultWeather(false);
                setCloudsIntensity(0.5f);
                setFogIntensity(0.0135f);
                setWindIntensity(12.5f);
                setOvercastIntensity(0.5f);
                setRainIntensity(0.5f);
                setThunderIntensity(0.5f);
                setSnowIntensity(0.5f);
            }

            void debug() {
                std::cout << "Weather[getOverwriteDefaultWeather]: " << getOverwriteDefaultWeather() << std::endl;
                std::cout << "Weather[getRainIntensity]: " << getRainIntensity() << std::endl;
                std::cout << "Weather[getSnowIntensity]: " << getSnowIntensity() << std::endl;
                std::cout << "Weather[getFogIntensity]: " << getFogIntensity() << std::endl;
                std::cout << "Weather[getWindIntensity]: " << getWindIntensity() << std::endl;
                std::cout << "Weather[getCloudsIntensity]: " << getCloudsIntensity() << std::endl;
                std::cout << "Weather[getOvercastIntensity]: " << getOvercastIntensity() << std::endl;
                std::cout << "Weather[getThunderIntensity]: " << getThunderIntensity() << std::endl;
            }

            void read(File::File *file);
            void write(File::File *file);

            float getRainIntensity() const;
            void setRainIntensity(float value);

            float getSnowIntensity() const;
            void setSnowIntensity(float value);

            float getFogIntensity() const;
            void setFogIntensity(float value);

            float getWindIntensity() const;
            void setWindIntensity(float value);

            float getOvercastIntensity() const;
            void setOvercastIntensity(float value);

            float getCloudsIntensity() const;
            void setCloudsIntensity(float value);

            float getThunderIntensity() const;
            void setThunderIntensity(float value);

            bool getOverwriteDefaultWeather() const;
            void setOverwriteDefaultWeather(bool value);

            static float convertWindIntensity(float value, bool fromWindIntensity);
            static float convertFogIntensity(float value, bool fromFogIntensity);
        private:
            float rainIntensity;
            float snowIntensity;
            float fogIntensity;
            float windIntensity;
            float overcastIntensity;
            float cloudsIntensity;
            float thunderIntensity;
            bool overwriteDefaultWeather;
        };
    }
}

#endif // WEATHER_H

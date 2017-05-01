#ifndef LIB_NL2PARK_INFO_H
#define LIB_NL2PARK_INFO_H

#include <Stream/Chunk.h>
#include <src/NL2/Info/Weather.h>
#include <src/NL2/Info/Sky.h>
#include "Version.h"

namespace NoLimits {
    namespace NL2 {
        class Info: public Stream::Chunk {
        public:
            enum RideView {
                ClosestCoasterFirstTrain = 0,
                ClosestCoasterClosestTrain = 1,
                FlyView = 2,
                WalkView = 3
            };

            Info() {
                weather = new Weather();
                sky = new Sky();
                version = new Version();

                setAuthor("");
                setDescription("");
                setEnvironment("intern:data/environments/default/Default.nl2env");
                setInitialPositionAndRotationEnabled(false);
                setInitialPosition(glm::vec3(0.0f));
                setInitialRotation(glm::vec2(0.0f));
                setInitialView(NoLimits::NL2::Info::RideView::ClosestCoasterFirstTrain);
            }

            void debug() {
                std::cout << "Info[getAuthor]: " << getAuthor() << std::endl;
                std::cout << "Info[getDescription]: " << getDescription() << std::endl;
                std::cout << "Info[getEnvironment]:" << getEnvironment() << std::endl;
                std::cout << "Info[getInitialPositionAndRotationEnabled]: " << getInitialPositionAndRotationEnabled() << std::endl;
                std::cout << "Info[getInitialPosition]: " << Helper::debug(getInitialPosition()) << std::endl;
                std::cout << "Info[getInitialRotation]: " << Helper::debug(getInitialRotation()) << std::endl;
                std::cout << "Info[getInitialView]: " << getInitialView() << std::endl;

                getWeather()->debug();
                getSky()->debug();
                getVersion()->debug();
            }

            void read(File::File *file);
            void write(File::File *file);

            Weather *getWeather() const;
            Sky *getSky() const;

            std::string getAuthor() const;
            void setAuthor(const std::string &value);

            std::string getDescription() const;
            void setDescription(const std::string &value);

            std::string getPreview() const;
            void setPreview(const std::string &value);

            std::string getEnvironment() const;
            void setEnvironment(const std::string &value);

            glm::vec3 getInitialPosition() const;
            void setInitialPosition(const glm::vec3 &value);

            glm::vec2 getInitialRotation() const;
            void setInitialRotation(const glm::vec2 &value);

            RideView getInitialView();
            void setInitialView(RideView value);

            Version *getVersion() const;
            void setVersion(Version *value);

            bool getInitialPositionAndRotationEnabled() const;
            void setInitialPositionAndRotationEnabled(bool value);

        private:
            Weather *weather;
            Sky *sky;
            Version *version;

            std::string author;
            std::string description;
            std::string preview;
            std::string environment;

            bool initialPositionAndRotationEnabled;
            glm::vec3 initialPosition;
            glm::vec2 initialRotation;
            RideView initialView;

        protected:
            std::string getChunkName() { return "INFO"; }
        };
    }
}

#endif // LIB_NL2PARK_INFO_H

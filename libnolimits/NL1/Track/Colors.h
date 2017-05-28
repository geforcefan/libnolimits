#ifndef LIB_NOLIMITS_NL1_COLORS_H
#define LIB_NOLIMITS_NL1_COLORS_H

#include "../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits1 {
        class Colors: public Stream::Chunk {
        public:
            Colors() {
                setTrackSpine(glm::vec3(255.0f, 255.0f, 255.0f));
                setTrackRail(glm::vec3(255.0f, 255.0f, 255.0f));
                setTrackCrosstie(glm::vec3(255.0f, 255.0f, 255.0f));
                setSupports(glm::vec3(255.0f, 255.0f, 255.0f));
                setTrainSeat(glm::vec3(255.0f, 255.0f, 255.0f));
                setTrainRestraint(glm::vec3(255.0f, 255.0f, 255.0f));
                setTrain(glm::vec3(255.0f, 255.0f, 255.0f));
                setTrainGear(glm::vec3(255.0f, 255.0f, 255.0f));
                setUseTunnelColor(false);
                setTunnel(glm::vec3(255.0f, 255.0f, 255.0f));
            }

            void debug() {
                std::cout << "Colors[getTrackSpine]: " << Helper::debug(getTrackSpine()) << std::endl;
                std::cout << "Colors[getTrackRail]: " << Helper::debug(getTrackRail()) << std::endl;
                std::cout << "Colors[getTrackCrosstie]: " << Helper::debug(getTrackCrosstie()) << std::endl;
                std::cout << "Colors[getSupports]: " << Helper::debug(getSupports()) << std::endl;
                std::cout << "Colors[getTrainSeat]: " << Helper::debug(getTrainSeat()) << std::endl;
                std::cout << "Colors[getTrainRestraint]: " << Helper::debug(getTrainRestraint()) << std::endl;
                std::cout << "Colors[getTrain]: " << Helper::debug(getTrain()) << std::endl;
                std::cout << "Colors[getTrainGear]: " << Helper::debug(getTrainGear()) << std::endl;
                std::cout << "Colors[getUseTunnelColor]: " << getUseTunnelColor() << std::endl;
                std::cout << "Colors[getTunnel]: " << Helper::debug(getTunnel()) << std::endl;
            }

            const glm::vec3 &getTrackSpine() const;
            void setTrackSpine(const glm::vec3 &trackSpine);

            const glm::vec3 &getTrackRail() const;
            void setTrackRail(const glm::vec3 &trackRail);

            const glm::vec3 &getTrackCrosstie() const;
            void setTrackCrosstie(const glm::vec3 &trackCrosstie);

            const glm::vec3 &getSupports() const;
            void setSupports(const glm::vec3 &supports);

            const glm::vec3 &getTrainSeat() const;
            void setTrainSeat(const glm::vec3 &trainSeat);

            const glm::vec3 &getTrainRestraint() const;
            void setTrainRestraint(const glm::vec3 &trainRestraint);

            const glm::vec3 &getTrain() const;
            void setTrain(const glm::vec3 &train);

            const glm::vec3 &getTrainGear() const;
            void setTrainGear(const glm::vec3 &trainGear);

            bool getUseTunnelColor() const;
            void setUseTunnelColor(bool useTunnelColor);

            const glm::vec3 &getTunnel() const;
            void setTunnel(const glm::vec3 &tunnel);

        private:
            glm::vec3 trackSpine;
            glm::vec3 trackRail;
            glm::vec3 trackCrosstie;
            glm::vec3 supports;
            glm::vec3 trainSeat;
            glm::vec3 trainRestraint;
            glm::vec3 train;
            glm::vec3 trainGear;

            bool useTunnelColor;
            glm::vec3 tunnel;
        };
    }
}

#endif // LIB_NOLIMITS_NL1_COLORS_H

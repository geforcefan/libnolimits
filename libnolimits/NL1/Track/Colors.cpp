#include "Colors.h"

namespace NoLimits {
    namespace NoLimits1 {
        const glm::vec3 &Colors::getTrackSpine() const {
            return trackSpine;
        }

        void Colors::setTrackSpine(const glm::vec3 &value) {
            trackSpine = value;
        }

        const glm::vec3 &Colors::getTrackRail() const {
            return trackRail;
        }

        void Colors::setTrackRail(const glm::vec3 &value) {
            trackRail = value;
        }

        const glm::vec3 &Colors::getTrackCrosstie() const {
            return trackCrosstie;
        }

        void Colors::setTrackCrosstie(const glm::vec3 &value) {
            trackCrosstie = value;
        }

        const glm::vec3 &Colors::getSupports() const {
            return supports;
        }

        void Colors::setSupports(const glm::vec3 &value) {
            supports = value;
        }

        const glm::vec3 &Colors::getTrainSeat() const {
            return trainSeat;
        }

        void Colors::setTrainSeat(const glm::vec3 &value) {
            trainSeat = value;
        }

        const glm::vec3 &Colors::getTrainRestraint() const {
            return trainRestraint;
        }

        void Colors::setTrainRestraint(const glm::vec3 &value) {
            trainRestraint = value;
        }

        const glm::vec3 &Colors::getTrain() const {
            return train;
        }

        void Colors::setTrain(const glm::vec3 &value) {
            train = value;
        }

        const glm::vec3 &Colors::getTrainGear() const {
            return trainGear;
        }

        void Colors::setTrainGear(const glm::vec3 &value) {
            trainGear = value;
        }

        bool Colors::getUseTunnelColor() const {
            return useTunnelColor;
        }

        void Colors::setUseTunnelColor(bool value) {
            useTunnelColor = value;
        }

        const glm::vec3 &Colors::getTunnel() const {
            return tunnel;
        }

        void Colors::setTunnel(const glm::vec3 &value) {
            tunnel = value;
        }
    }
}

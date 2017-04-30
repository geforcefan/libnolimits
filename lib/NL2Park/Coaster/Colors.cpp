#include <NL2Park/Coaster/Colors.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        Colors::Colors() {
        }

        glm::vec3 Colors::getWireframeTrack() const {
            return wireframeTrack;
        }

        void Colors::setWireframeTrack(const glm::vec3 &value) {
            wireframeTrack = value;
        }

        glm::vec3 Colors::getRails() const {
            return rails;
        }

        void Colors::setRails(const glm::vec3 &value) {
            rails = value;
        }

        glm::vec3 Colors::getCrossTies() const {
            return crossTies;
        }

        void Colors::setCrossTies(const glm::vec3 &value) {
            crossTies = value;
        }

        glm::vec3 Colors::getMainSpine() const {
            return mainSpine;
        }

        void Colors::setMainSpine(const glm::vec3 &value) {
            mainSpine = value;
        }

        glm::vec3 Colors::getCar() const {
            return car;
        }

        void Colors::setCar(const glm::vec3 &value) {
            car = value;
        }

        glm::vec3 Colors::getSeat() const {
            return seat;
        }

        void Colors::setSeat(const glm::vec3 &value) {
            seat = value;
        }

        glm::vec3 Colors::getHarness() const {
            return harness;
        }

        void Colors::setHarness(const glm::vec3 &value) {
            harness = value;
        }

        glm::vec3 Colors::getBogie() const {
            return bogie;
        }

        void Colors::setBogie(const glm::vec3 &value) {
            bogie = value;
        }

        glm::vec3 Colors::getChasiss() const {
            return chasiss;
        }

        void Colors::setChasiss(const glm::vec3 &value) {
            chasiss = value;
        }

        glm::vec3 Colors::getSupports() const {
            return supports;
        }

        void Colors::setSupports(const glm::vec3 &value) {
            supports = value;
        }

        glm::vec3 Colors::getTunnel() const {
            return tunnel;
        }

        void Colors::setTunnel(const glm::vec3 &value) {
            tunnel = value;
        }

        glm::vec3 Colors::getHandrails() const {
            return handrails;
        }

        void Colors::setHandrails(const glm::vec3 &value) {
            handrails = value;
        }

        glm::vec3 Colors::getCatwalks() const {
            return catwalks;
        }

        void Colors::setCatwalks(const glm::vec3 &value) {
            catwalks = value;
        }

        Colors::SpineColorScheme Colors::getSpineColorScheme() const {
            return spineColorScheme;
        }

        void Colors::setSpineColorScheme(const Colors::SpineColorScheme &value) {
            spineColorScheme = value;
        }

        void Colors::read(File::File *file) {
        }
    }
}

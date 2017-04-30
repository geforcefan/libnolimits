#include <NL2Park/Coaster/Style.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        Style::Style() {
        }

        void Style::read(File::File *file) {
        }

        Style::StyleType Style::getStyleType() const {
            return styleType;
        }

        void Style::setStyleType(const Style::StyleType &value) {
            styleType = value;
        }

        Style::WornType Style::getWornType() const {
            return wornType;
        }

        void Style::setWornType(const Style::WornType &value) {
            wornType = value;
        }

        Style::RailType Style::getRailType() const {
            return railType;
        }

        void Style::setRailType(const Style::RailType &value) {
            railType = value;
        }

    }
}

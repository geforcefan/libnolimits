#include <src/NL2/Coaster/Style.h>
#include <iostream>

namespace NoLimits {
    namespace NL2 {
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

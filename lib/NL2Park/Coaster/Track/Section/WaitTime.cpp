#include "WaitTime.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        double WaitTime::getAvarage() const {
            return avarage;
        }

        void WaitTime::setAvarage(double value) {
            avarage = value;
        }

        double WaitTime::getMinimum() const {
            return minimum;
        }

        void WaitTime::setMinimum(double value) {
            minimum = value;
        }

        double WaitTime::getMaximum() const {
            return maximum;
        }

        void WaitTime::setMaximum(double value) {
            maximum = value;
        }

        double WaitTime::getDeviation() const {
            return deviation;
        }

        void WaitTime::setDeviation(double value) {
            deviation = value;
        }

        std::vector<uint32_t> WaitTime::getSynchronizeDispatchWith() const {
            return synchronizeDispatchWith;
        }

        void WaitTime::insertSynchronizeDispatchWith(uint32_t value) {
            synchronizeDispatchWith.push_back(value);
        }
    }
}

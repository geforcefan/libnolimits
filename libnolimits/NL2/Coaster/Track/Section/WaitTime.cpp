#include "WaitTime.h"

#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        double WaitTime::getAverage() const {
            return average;
        }

        void WaitTime::setAverage(double value) {
            average = value;
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

        uint32_t WaitTime::insertSynchronizeDispatchWith(uint32_t value) {
            synchronizeDispatchWith.push_back(value);
            return synchronizeDispatchWith.size();
        }
    }
}

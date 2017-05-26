#ifndef LIB_NL2PARK_WAITTIME_H
#define LIB_NL2PARK_WAITTIME_H

#include <vector>
#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class WaitTime {
        public:
            WaitTime() {
                setAverage(50.0f);
                setMinimum(40.0f);
                setMaximum(60.0f);
                setDeviation(5.0f);
            }

            void debug() {
                std::cout << "WaitTime[getAverage]: " << getAverage() << std::endl;
                std::cout << "WaitTime[getMinimum]: " << getMinimum() << std::endl;
                std::cout << "WaitTime[getMaximum]: " << getMaximum() << std::endl;
                std::cout << "WaitTime[getDeviation]: " << getDeviation() << std::endl;

                std::cout << "WaitTime[synchronizeDispatchWith.size]: " << synchronizeDispatchWith.size() << std::endl;
                if(synchronizeDispatchWith.size())
                    std::cout << "---------------------------------------" << std::endl;
                for(uint32_t i = 0; i < synchronizeDispatchWith.size(); i++) {
                    std::cout << "WaitTime[synchronizeDispatchWith][" << i << "]: " << synchronizeDispatchWith[i] << std::endl;
                    std::cout << "---------------------------------------" << std::endl;
                }
            }

            double getAverage() const;
            void setAverage(double value);

            double getMinimum() const;
            void setMinimum(double value);

            double getMaximum() const;
            void setMaximum(double value);

            double getDeviation() const;
            void setDeviation(double value);

            std::vector<uint32_t> getSynchronizeDispatchWith() const;
            uint32_t insertSynchronizeDispatchWith(uint32_t value);
        private:
            double average;
            double minimum;
            double maximum;
            double deviation;
            std::vector<uint32_t> synchronizeDispatchWith;
        };
    }
}

#endif // LIB_NL2PARK_WAITTIME_H

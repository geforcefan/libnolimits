#ifndef LIB_NL2PARK_WAITTIME_H
#define LIB_NL2PARK_WAITTIME_H

#include <vector>
#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class WaitTime {
        public:
            WaitTime() {}
            double getAvarage() const;
            void setAvarage(double value);

            double getMinimum() const;
            void setMinimum(double value);

            double getMaximum() const;
            void setMaximum(double value);

            double getDeviation() const;
            void setDeviation(double value);

            std::vector<uint32_t> getSynchronizeDispatchWith() const;
            void insertSynchronizeDispatchWith(uint32_t value);

        private:
            double avarage;
            double minimum;
            double maximum;
            double deviation;
            std::vector<uint32_t> synchronizeDispatchWith;
        };
    }
}

#endif // LIB_NL2PARK_WAITTIME_H

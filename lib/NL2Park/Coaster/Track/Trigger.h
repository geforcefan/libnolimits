#ifndef LIB_NL2PARK_TRIGGER_H
#define LIB_NL2PARK_TRIGGER_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Trigger : public Stream::Chunk {
        public:
            enum TrainEvent {
                None,
                UnlockSpinning,
                LockSpinning,
                UnlockSwinging,
                LockSwinging
            };

            Trigger() {}
            void read(File::File *file);

            double getPosition() const;
            void setPosition(double value);

            std::string getName() const;
            void setName(const std::string &value);

            TrainEvent getTrainEvent() const;
            void setTrainEvent(const TrainEvent &value);

        private:
            double position;
            std::string name;
            TrainEvent trainEvent;
        };
    }
}

#endif // LIB_NL2PARK_TRIGGER_H

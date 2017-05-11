#ifndef LIB_NL2PARK_TRIGGER_H
#define LIB_NL2PARK_TRIGGER_H

#include <Stream/Chunk.h>

namespace NoLimits {
    namespace NL2 {
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
            void write(File::File *file);

            double getPosition() const;
            void setPosition(double value);

            std::string getName() const;
            void setName(const std::string &value);

            TrainEvent getTrainEvent() const;
            void setTrainEvent(const TrainEvent &value);

            std::string getChunkName() { return "TTRG"; }
        private:
            double position;
            std::string name;
            TrainEvent trainEvent;
        };
    }
}

#endif // LIB_NL2PARK_TRIGGER_H

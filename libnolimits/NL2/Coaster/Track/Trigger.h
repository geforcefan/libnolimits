#ifndef LIB_NL2PARK_TRIGGER_H
#define LIB_NL2PARK_TRIGGER_H

#include "../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Trigger : public Stream::Chunk {
        public:
            enum TrainEvent {
                None,
                UnlockSpinning,
                LockSpinning,
                UnlockSwinging,
                LockSwinging
            };

            Trigger() {
                setPosition(0.0f);
                setName("");
                setTrainEvent(TrainEvent::None);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                std::cout << "Vertex[getPosition]: " << getPosition() << std::endl;
                std::cout << "Vertex[getName]: " << getName() << std::endl;
                std::cout << "Vertex[getTrainEvent]: " << getTrainEvent() << std::endl;
            }

            double getPosition() const;
            void setPosition(double value);

            std::string getName() const;
            void setName(const std::string &value);

            TrainEvent getTrainEvent() const;
            void setTrainEvent(const TrainEvent &value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "TTRG"; }
            /*! \endcond */
        private:
            double position;
            std::string name;
            TrainEvent trainEvent;
        };
    }
}

#endif // LIB_NL2PARK_TRIGGER_H

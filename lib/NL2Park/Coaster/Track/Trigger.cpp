#include "Trigger.h"

namespace Library {
    namespace NL2Park {
        void Trigger::read(File::File *file) {
            setPosition(file->readDouble());
            setName(file->readString());
            file->readNull(3);
            setTrainEvent((Trigger::TrainEvent)file->readUnsigned8());
            file->readNull(23);
        }

        double Trigger::getPosition() const {
            return position;
        }

        void Trigger::setPosition(double value) {
            position = value;
        }

        std::string Trigger::getName() const {
            return name;
        }

        void Trigger::setName(const std::string &value) {
            name = value;
        }

        Trigger::TrainEvent Trigger::getTrainEvent() const {
            return trainEvent;
        }

        void Trigger::setTrainEvent(const Trigger::TrainEvent &value) {
            trainEvent = value;
        }
    }

}

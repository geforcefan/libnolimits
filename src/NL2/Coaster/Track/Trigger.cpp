#include "Trigger.h"

namespace NoLimits {
    namespace NL2 {
        void Trigger::read(File::File *file) {
            setPosition(file->readDouble());
            setName(file->readString());
            file->readNull(3);
            setTrainEvent((Trigger::TrainEvent)file->readUnsigned8());
            file->readNull(26);
        }

        void Trigger::write(File::File *file) {
            file->writeDouble(getPosition());
            file->writeString(getName());
            file->writeNull(3);
            file->writeUnsigned8(getTrainEvent());
            file->writeNull(26);
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

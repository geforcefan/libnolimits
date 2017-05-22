#include "SupportParameter.h"

namespace NoLimits {
    namespace NoLimits2 {
        void SupportParameter::read(File::File *file) {
            setType((Type)file->readUnsignedInteger());
            setValue(file->readDouble());
        }

        void SupportParameter::write(File::File *file) {
            file->writeUnsignedInteger(getType());
            file->writeDouble(getValue());
        }

        double SupportParameter::getValue() const {
            return value;
        }

        void SupportParameter::setValue(double val) {
            value = val;
        }

        SupportParameter::Type SupportParameter::getType() const {
            return type;
        }

        void SupportParameter::setType(const SupportParameter::Type &value) {
            type = value;
        }
    }
}

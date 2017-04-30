#include <NL2Park/Info/Sky.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Sky::read(File::File *file) {
            setOverrideDefaultDateTime(file->readBoolean());
            setCurrentDate(file->readIntVec2());
            setCurrentTime(file->readIntVec2());
        }

        void Sky::write(File::File *file) {
            file->writeBoolean(getOverrideDefaultDateTime());
            file->writeIntVec2(getCurrentDate());
            file->writeIntVec2(getCurrentTime());
        }

        glm::vec2 Sky::getCurrentTime() const {
            return currentTime;
        }

        void Sky::setCurrentTime(const glm::vec2 &value) {
            currentTime = value;
        }

        glm::vec2 Sky::getCurrentDate() const {
            return currentDate;
        }

        void Sky::setCurrentDate(const glm::vec2 &value) {
            currentDate = value;
        }

        bool Sky::getOverrideDefaultDateTime() const {
            return overrideDefaultDateTime;
        }

        void Sky::setOverrideDefaultDateTime(bool value) {
            overrideDefaultDateTime = value;
        }
    }
}

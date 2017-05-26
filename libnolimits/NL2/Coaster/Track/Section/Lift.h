#ifndef LIB_NL2PARK_LIFT_H
#define LIB_NL2PARK_LIFT_H

#include "Section.h"
#include "../../../../Stream/Chunk.h"

namespace NoLimits {
    namespace NoLimits2 {
        class Lift : public Section {
        public:
            enum LiftType {
                Chain,
                FrictionWheels
            };

            enum MotorLocation {
                AtStart,
                AtEnd,
                Silent
            };

            Lift() : Section(Section::SectionType::Lift) {
                setSpeed(Helper::kphToMs(8.0f));
                setAcceleration(Helper::GToNewton(0.5f));
                setDeceleration(Helper::GToNewton(0.1f));
                setLiftType(LiftType::Chain);
                setMotorLocation(MotorLocation::AtStart);
                setHasAntiRollbackDevice(false);
                setShuttleModeGentle2ndPassRelease(false);
                setDiveCoasterDropReleaseMode(false);
            }

            /*! \cond INTERNAL */
            void read(File::File *file);
            void write(File::File *file);
            /*! \endcond */

            void debug() {
                Section::debug();

                std::cout << "Lift[getSpeed]: " << getSpeed() << std::endl;
                std::cout << "Lift[getAcceleration]: " << getAcceleration() << std::endl;
                std::cout << "Lift[getDeceleration]: " << getDeceleration() << std::endl;
                std::cout << "Lift[getLiftType]: " << getLiftType() << std::endl;
                std::cout << "Lift[getMotorLocation]: " << getMotorLocation() << std::endl;
                std::cout << "Lift[getHasAntiRollbackDevice]: " << getHasAntiRollbackDevice() << std::endl;
                std::cout << "Lift[getShuttleModeGentle2ndPassRelease]: " << getShuttleModeGentle2ndPassRelease() << std::endl;
                std::cout << "Lift[getDiveCoasterDropReleaseMode]: " << getDiveCoasterDropReleaseMode() << std::endl;
            }

            double getSpeed() const;
            void setSpeed(double value);

            double getAcceleration() const;
            void setAcceleration(double value);

            double getDeceleration() const;
            void setDeceleration(double value);

            LiftType getLiftType() const;
            void setLiftType(const LiftType &value);

            MotorLocation getMotorLocation() const;
            void setMotorLocation(const MotorLocation &value);

            bool getHasAntiRollbackDevice() const;
            void setHasAntiRollbackDevice(bool value);

            bool getShuttleModeGentle2ndPassRelease() const;
            void setShuttleModeGentle2ndPassRelease(bool value);

            bool getDiveCoasterDropReleaseMode() const;
            void setDiveCoasterDropReleaseMode(bool value);

            double getExtraBlockLength() const;
            void setExtraBlockLength(double value);

            /*! \cond INTERNAL */
            std::string getChunkName() { return "LIFT"; }
            /*! \endcond */
        private:
            double speed;
            double acceleration;
            double deceleration;

            LiftType liftType;
            MotorLocation motorLocation;

            bool hasAntiRollbackDevice;
            bool shuttleModeGentle2ndPassRelease;
            bool diveCoasterDropReleaseMode;

            double extraBlockLength;
        };
    }
}

#endif // LIB_NL2PARK_LIFT_H

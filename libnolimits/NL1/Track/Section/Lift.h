#ifndef LIB_NOLIMITS_NL1_LIFT_H
#define LIB_NOLIMITS_NL1_LIFT_H

#include "Section.h"

namespace NoLimits {
    namespace NoLimits1 {
        class Lift : public Section {
        public:
            enum LiftFlags {
                MotorAtEnd,
                ReleaseAtEnd,
                ReverseCableLift
            };

            enum LiftStyle {
                Chain,
                FrictionWheels
            };

            Lift() {
                setSectionType(Section::SectionType::Lift);
            }

            LiftStyle getLiftStyle() const;
            void setLiftStyle(LiftStyle liftStyle);

            float getSpeed() const;
            void setSpeed(float speed);

            float getAcceleration() const;
            void setAcceleration(float acceleration);

            float getDeceleration() const;
            void setDeceleration(float deceleration);

            bool getRailingLeft() const;
            void setRailingLeft(bool railingLeft);

            bool getRailingRight() const;
            void setRailingRight(bool railingRight);

            /*! \cond INTERNAL */
            void readSection(File::File *file);
            void writeSection(File::File *file);
            /*! \endcond */
        private:
            LiftStyle liftStyle;

            float speed;
            float acceleration;
            float deceleration;

            bool railingLeft;
            bool railingRight;
        };
    }
}


#endif //LIB_NOLIMITS_NL1_LIFT_H

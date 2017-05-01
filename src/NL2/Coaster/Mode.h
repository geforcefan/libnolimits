#ifndef LIB_NL2PARK_MODE_H
#define LIB_NL2PARK_MODE_H

#include <Stream/Chunk.h>
#include <src/NL2/Coaster/CustomFriction.h>

namespace NoLimits {
    namespace NL2 {
        class Mode: public Stream::Chunk {
        public:
            enum Operation {
                ClosedCircuit = 0,
                Shuttle = 1,
                Scripted = 2
            };

            enum SplinePosition {
                CenterOfRail = 0,
                HeartLineCurrentStyle = 1,
                Custom = 2
            };

            enum PhysicsModel {
                NoLimits2 = 0,
                NoLimits2CustomFriction = 3,
                NoLimits22 = 4,
                NoLimits16 = 1,
                NoLimits1 = 2
            };

            Mode() {
                customFriction = new CustomFriction();

                setOperationMode(Operation::ClosedCircuit);
                setPhysicsModel(PhysicsModel::NoLimits22);
                setSplinePosition(SplinePosition::CenterOfRail);
                setSplinePositionOffset(glm::vec2(0.0f));
            }

            void debug() {
                std::cout << "Mode[getOperationMode]: " << getOperationMode() << std::endl;
                std::cout << "Mode[getPhysicsModel]: " << getPhysicsModel() << std::endl;
                std::cout << "Mode[getSplinePosition]: " << getSplinePosition() << std::endl;
                std::cout << "Mode[getSplinePositionOffset]: " << Helper::debug(getSplinePositionOffset()) << std::endl;

                getCustomFriction()->debug();
            }

            Operation getOperationMode() const;
            void setOperationMode(const Operation &value);

            PhysicsModel getPhysicsModel() const;
            void setPhysicsModel(const PhysicsModel &value);

            SplinePosition getSplinePosition() const;
            void setSplinePosition(const SplinePosition &value);

            CustomFriction *getCustomFriction() const;

            glm::vec2 getSplinePositionOffset() const;
            void setSplinePositionOffset(const glm::vec2 &value);

        private:
            Operation operationMode;
            PhysicsModel physicsModel;
            SplinePosition splinePosition;
            glm::vec2 splinePositionOffset;
            CustomFriction *customFriction;
        };
    }
}

#endif // LIB_NL2PARK_MODE_H

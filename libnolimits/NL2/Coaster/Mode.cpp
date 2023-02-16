#include "Mode.h"
#include <iostream>

namespace NoLimits {
    namespace NoLimits2 {
        Mode::Operation Mode::getOperationMode() const {
            return operationMode;
        }

        void Mode::setOperationMode(const Mode::Operation &value) {
            operationMode = value;
        }

        Mode::PhysicsModel Mode::getPhysicsModel() const {
            return physicsModel;
        }

        void Mode::setPhysicsModel(const Mode::PhysicsModel &value) {
            physicsModel = value;
        }

        Mode::SplinePosition Mode::getSplinePosition() const {
            return splinePosition;
        }

        void Mode::setSplinePosition(const Mode::SplinePosition &value) {
            splinePosition = value;
        }
        
        glm::dvec2 Mode::getSplinePositionOffset() const {
            return splinePositionOffset;
        }
        
        void Mode::setSplinePositionOffset(const glm::dvec2 &value) {
            splinePositionOffset = value;
        }
        
        CustomFriction *Mode::getCustomFriction() const {
            return customFriction;
        }
    }
}

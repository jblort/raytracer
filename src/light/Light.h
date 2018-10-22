#pragma once

#include "math/Ray.h"

#include <glm/glm.hpp>

namespace rt {

    class Light {
    public:
        virtual ~Light(){}

    public:
        virtual Color color() const = 0;
        virtual double intensityAt(const RayIntersection& intersection) const = 0;
        virtual glm::vec3 directionRelativeTo(const RayIntersection& intersection) const = 0;
    };
}

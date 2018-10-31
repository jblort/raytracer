#pragma once

#include "math/Ray.h"
#include "std_helpers/optional.h"

#include <utility>

namespace rt {

    struct Intersection {
        glm::vec3 position;
        glm::vec3 normal;
    };

    namespace intersections {
        optional<Intersection> raySphere(const Ray& ray, const glm::vec3& center, const double radius);
        optional<Intersection> rayPlane(const Ray& ray, const glm::vec3& planeNormal, const glm::vec3& planeOrigin);
        optional<Intersection> rayTriangle(const Ray& ray, const glm::vec3& v0,
                                                           const glm::vec3& v1,
                                                           const glm::vec3& v2);
    }
}

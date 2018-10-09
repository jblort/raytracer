#pragma once

#include <glm/glm.hpp>

#include "traceables/shapes/Sphere.h"
#include "std_helpers/std_helpers.h"

namespace rt {
    class Camera;

    struct Ray {
        glm::vec3 origin;
        glm::vec3 direction;
    };

    struct RayIntersection {
        glm::vec3 position;
        glm::vec3 normal;
    };

    namespace RayUtils {
        Ray makePrimaryRay(float u, float v, const Camera& camera);
        Ray makeShadowRay(const glm::vec3& intersectionPosition, const glm::vec3& lightPosition);

        optional<RayIntersection> sphericalIntersection(const Ray& ray, const Sphere& sphere);

        Ray transform(const Ray& ray, const glm::mat4& transform);
    }
}

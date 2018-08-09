#pragma once

#include <glm/glm.hpp>

#include "shapes/Sphere.h"
#include "std_helpers/std_helpers.h"

namespace rt {

    struct Ray {
        glm::vec3 origin;
        glm::vec3 direction;
    };

    struct RayIntersection {
        glm::vec3 position;
        glm::vec3 normal;
    };

    namespace RayUtils {
        Ray makePrimaryRay(int gridX, int gridY, glm::vec3 cameraCenter);
        Ray makeShadowRay(glm::vec3 intersectionPosition, glm::vec3 lightPosition);

        optional<RayIntersection> sphericalIntersection(const Ray& ray, const Sphere& sphere);
    }
}

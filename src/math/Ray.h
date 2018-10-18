#pragma once

#include <glm/glm.hpp>

#include "materials/SimpleMaterial.h"
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
        SimpleMaterial localMaterial;
    };

    namespace RayUtils {
        Ray makePrimaryRay(float u, float v, const Camera& camera);
        Ray makeShadowRay(const glm::vec3& intersectionPosition, const glm::vec3& lightPosition);
        Ray transform(const Ray& ray, const glm::mat4& transform);
    }
}

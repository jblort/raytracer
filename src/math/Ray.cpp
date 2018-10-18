#include "math/Ray.h"

#include <cmath>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "camera/Camera.h"
#include "logging/Logger.h"
#include "math/MathUtils.h"
#include "math/QuadraticSolver.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

Ray RayUtils::makePrimaryRay(float u, float v, const Camera& camera) {
    Ray ray;

    ray.origin = glm::vec3(0.0, 0.0, 0.0);
    ray.direction = glm::normalize(glm::vec3(u * camera.fovFactor(), v * camera.fovFactor(), -1.0));

    // View transform transforms from world to view, we want the opposite
    auto cameraToWorld = glm::inverse(camera.viewTransform());
    auto primaryRay = RayUtils::transform(ray, cameraToWorld);

    return primaryRay;
}

Ray RayUtils::makeShadowRay(const glm::vec3& intersectionPosition, const glm::vec3& lightPosition) {
    Ray ray{intersectionPosition, glm::normalize(lightPosition - intersectionPosition)};
    return ray;
}

Ray RayUtils::transform(const Ray& ray, const glm::mat4& transform) {
    Ray transformedRay;

    auto origin = transform *  glm::vec4(ray.origin, 1.0);
    auto direction = transform * glm::vec4(ray.direction, 0.0);

    transformedRay.origin = glm::vec3(origin);
    transformedRay.direction = glm::normalize(glm::vec3(direction));

    return transformedRay;
}

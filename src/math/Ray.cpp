#include "math/Ray.h"

#include <cmath>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "camera/Camera.h"
#include "logging/Logger.h"
#include "math/MathUtils.h"
#include "math/QuadraticSolver.h"
#include "traceables/Traceable.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

Ray Raytracing::makePrimaryRay(float x, float y, float w, float h, const Camera& camera) {
    auto ratio = w / h;
    auto pixelNDCx = (x + 0.5) / w;
    auto pixelNDCy = (y + 0.5) / h;
    auto pixelScreenX = 2 * pixelNDCx - 1;
    auto pixelScreenY = 1 - 2 * pixelNDCy;
    auto pixelCameraX = pixelScreenX * ratio * camera.fovFactor();
    auto pixelCameraY = pixelScreenY * camera.fovFactor();
    auto ray = Ray{glm::vec3{0.0, 0.0, 0.0}, glm::vec3{pixelCameraX, pixelCameraY, -1.0}};

    // View transform transforms from world to view, we want the opposite
    auto cameraToWorld = glm::inverse(camera.viewTransform());
    auto primaryRay = Raytracing::transform(ray, cameraToWorld);

    return primaryRay;
}

Ray Raytracing::makeShadowRay(const glm::vec3& intersectionPosition, const glm::vec3& lightPosition) {
    Ray ray{intersectionPosition, glm::normalize(lightPosition - intersectionPosition)};
    return ray;
}

Ray Raytracing::transform(const Ray& ray, const glm::mat4& transform) {
    Ray transformedRay;

    auto origin = transform *  glm::vec4(ray.origin, 1.0);
    auto direction = transform * glm::vec4(ray.direction, 0.0);

    transformedRay.origin = glm::vec3(origin);
    transformedRay.direction = glm::normalize(glm::vec3(direction));

    return transformedRay;
}

optional<RayIntersection> Raytracing::closestIntersection(const Ray& ray, const std::list<sptr<Traceable>>& traceables) {
    auto closestIntersection = optional<RayIntersection>();
    auto closestIntersectionDist = std::numeric_limits<double>::max();

    for (auto& traceable : traceables) {
        auto intersection = traceable->intersectionWith(ray);
        if (intersection) {
            auto dist =  rt::norm(intersection->position - ray.origin);

            // Prevent surface acne by enforcing that intersection should be
            // further than a specific small value
            if (dist < closestIntersectionDist && dist > 0.001) {
                closestIntersectionDist = dist;
                closestIntersection = intersection;
            }
        }
    }

    return closestIntersection;
}

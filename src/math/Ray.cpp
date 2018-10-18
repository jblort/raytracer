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

optional<RayIntersection> RayUtils::sphericalIntersection(const Ray& ray, const Sphere& sphere) {

    auto intersection = optional<RayIntersection>();

    glm::vec3 dir = ray.direction;
    glm::vec3 o = ray.origin;
    glm::vec3 center = sphere.center;
    glm::vec3 L = o - center;
    double r = sphere.radius;
    double a = glm::dot(dir, dir);
    double b = 2 * glm::dot(dir , L);
    double c = glm::dot(L, L) - r * r;
    auto solutions = Solver::solveQuadratic(a, b, c);

    if (solutions.count() == 0) {
        return intersection;
    }

    if (solutions.count() == 1) {
        auto value = solutions[0];
        if (value < 0) {
            return intersection;
        }
    }

    auto t0 = solutions[0];
    auto t1 = solutions[1];

    float dist = 0.0f;

    // We discard the first solution if it's negative
    if (t0 < 0) {
        t0 = t1;
        // We don't care if the other intersection is behind the ray origin.
        if (t0 < 0) {
            return intersection;
        }
        dist = t0;
    } else {
        dist = t0 < t1 ? t0 : t1;
    }

    auto intersectionPoint = o + dist * dir;
    auto intersectionNormal = glm::normalize(intersectionPoint - center);
    intersection = optional<RayIntersection>(RayIntersection{intersectionPoint, intersectionNormal});

    return intersection;
}

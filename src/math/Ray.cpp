#include "math/Ray.h"

#include <cmath>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "camera/Camera.h"
#include "math/MathUtils.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

Ray RayUtils::makePrimaryRay(int u, int v, const Camera& camera) {
    Ray ray;

    ray.origin = glm::vec3(0.0, 0.0, 0.0);
    ray.direction = glm::normalize(glm::vec3(u, v, camera.fovFactor()));

    auto primaryRay = RayUtils::transform(ray, camera.viewTransform());

    return ray;
}

Ray RayUtils::makeShadowRay(const glm::vec3& intersectionPosition, const glm::vec3& lightPosition) {
    Ray ray{intersectionPosition, glm::normalize(lightPosition - intersectionPosition)};
    return ray;
}

Ray RayUtils::transform(const Ray& ray, const glm::mat4& transform) {
    Ray transformedRay;

    auto origin = transform *  glm::vec4(ray.origin, 1.0);
    auto direction = transform * glm::vec4(ray.direction, 1.0);

    transformedRay.origin = glm::vec3(origin);
    transformedRay.direction = glm::normalize(glm::vec3(direction));

    return transformedRay;
}

optional<RayIntersection> RayUtils::sphericalIntersection(const Ray& ray, const Sphere& sphere) {
    auto intersection = optional<RayIntersection>();

    glm::vec3 l = ray.direction;
    glm::vec3 o = ray.origin;
    glm::vec3 c = sphere.center;
    double r = sphere.radius;
    double loc = glm::dot(l, (o - c));
    double delta = std::pow(loc, 2.0) - std::pow(norm(o - c), 2.0) + r*r;

    // The quadratic equation we solve to find the intersection has one solution
    if (isEqual(delta, 0.0, 0.01)) {
        float dist = - loc;
        glm::vec3 intersectionPoint = o + l * dist;
        glm::vec3 intersectionNormal = glm::normalize(intersectionPoint - c);

        intersection = optional<RayIntersection>(RayIntersection{intersectionPoint, intersectionNormal});
    }
    // The quadratic equation we solve to find the intersection has two solution
    else if (delta > 0.0) {
        float deltaSq = std::sqrt(delta);

        float dist1 = - loc + deltaSq;
        float dist2 = - loc - deltaSq;

        float dist = dist1 > dist2 ? dist2 : dist1;

        glm::vec3 intersectionPoint = o + dist * l;
        glm::vec3 intersectionNormal = glm::normalize(intersectionPoint - c);
        intersection = optional<RayIntersection>(RayIntersection{intersectionPoint, intersectionNormal});
    }

    return intersection;
}



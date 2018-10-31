#include "math/RayIntersection.h"

#include "math/QuadraticSolver.h"

using namespace rt;

optional<Intersection> intersections::rayPlane(const Ray& ray, const glm::vec3& planeNormal, const glm::vec3& planeOrigin) {
    auto intersection = optional<Intersection>{};

    return intersection;
}

optional<Intersection> intersections::rayTriangle(const Ray& ray,
                                                  const glm::vec3& v0,
                                                  const glm::vec3& v1,
                                                  const glm::vec3& v2) {
    return optional<Intersection>{};
}

optional<Intersection> intersections::raySphere(const Ray& ray, const glm::vec3& center, const double radius) {
    auto intersection = optional<Intersection>();
    glm::vec3 dir = ray.direction;
    glm::vec3 o = ray.origin;
    glm::vec3 L = o - center;
    double r = radius;
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
    intersection = optional<Intersection>({intersectionPoint, intersectionNormal});
    return intersection;
}

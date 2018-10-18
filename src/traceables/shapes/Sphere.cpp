#include "traceables/shapes/Sphere.h"

#include "math/QuadraticSolver.h"

using namespace rt;

Sphere::Sphere(const glm::vec3& center, double radius, const SimpleMaterial& material):
_center{center},
_radius{radius},
_material{material}
{}

Sphere::~Sphere() {}

optional<RayIntersection> Sphere::intersectionWith(const Ray& ray) {
    auto intersection = optional<RayIntersection>();

    glm::vec3 dir = ray.direction;
    glm::vec3 o = ray.origin;
    glm::vec3 center = this->_center;
    glm::vec3 L = o - center;
    double r = this->_radius;
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
    intersection = optional<RayIntersection>(RayIntersection{intersectionPoint, intersectionNormal, _material});

    return intersection;

}

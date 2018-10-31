#include "traceables/shapes/Sphere.h"

#include "math/QuadraticSolver.h"
#include "math/RayIntersection.h"

using namespace rt;

Sphere::Sphere(const glm::vec3& center, double radius, const SimpleMaterial& material):
_center{center},
_radius{radius},
_material{material}
{}

Sphere::~Sphere() {}

optional<RayIntersection> Sphere::intersectionWith(const Ray& ray) const {
    auto intersection = intersections::raySphere(ray, _center, _radius);

    if(intersection) {
        return optional<RayIntersection>(RayIntersection{intersection->position, intersection->normal, _material});
    }

    return optional<RayIntersection>();
}

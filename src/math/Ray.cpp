#include "math/Ray.h"

#include <cmath>

#include "math/VectorHelpers.h"
#include "shapes/Sphere.h"

using namespace rt;

Ray RayUtils::makePrimaryRay(int gridX, int gridY, glm::vec3 cameraCenter) {
    Ray ray;

    return ray;
}

Ray RayUtils::makeShadowRay(glm::vec3 intersectionPosition, glm::vec3 lightPosition) {
    Ray ray;

    return ray;
}

optional<RayIntersection> RayUtils::sphericalIntersection(const Ray& ray, const Sphere& sphere) {
    auto intersection = optional<RayIntersection>();

    glm::vec3 l = ray.direction;
    glm::vec3 o = ray.origin;
    glm::vec3 c = sphere.center;
    double r = sphere.radius;
    double delta;
    double loc = glm::dot(l, (o - c));
    delta = std::pow(loc, 2.0) - std::pow(norm(o - c), 2.0)+ r*r;

    // The quadratic equation we solve to find intersection has no solution
    if (delta < 0.0) {
        return intersection;
    }


    // The quadratic equation we solve to find the intersection has one solution
    if (delta == 0.0 ) {
        float dist = - loc;
        glm::vec3 intersectionPoint = o + l * dist;
        glm::vec3 intersectionNormal = glm::normalize(intersectionPoint - c);
        intersection = optional<RayIntersection>(RayIntersection{intersectionPoint, intersectionNormal});
    }
    // The quadratic equation we solve to find the intersection has two solution
    else {
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



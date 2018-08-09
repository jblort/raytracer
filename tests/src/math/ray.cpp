#include <catch.hpp>
#include <glm/glm.hpp>

#include "math/Ray.h"
#include "shapes/Sphere.h"

using namespace rt;

SCENARIO("Ray intersection") {
    GIVEN("a ray and a sphere that intersect") {
        Ray ray = Ray{glm::vec3(0.0, 0.0, 10.0), glm::vec3(0.0, 0.0, -1.0)};
        Sphere sphere = Sphere{glm::vec3(0.0, 0.0, 0.0), 2.0};

        WHEN("computing the intersection") {
            auto intersection = RayUtils::sphericalIntersection(ray, sphere);

            THEN("it returns the position and normal of the intersection") {
                REQUIRE(intersection);
                REQUIRE(intersection->position == glm::vec3(0.0, 0.0, 2.0));
                REQUIRE(intersection->normal == glm::vec3(0.0, 0.0, 1.0));
            }
        }
    }

    GIVEN("a ray and a sphere that don't intersect") {
        Ray ray = Ray{glm::vec3(0.0, 0.0, 10.0), glm::vec3(0.0, 1.0, 0.0)};
        Sphere sphere = Sphere{glm::vec3(0.0, 0.0, 0.0), 2.0};

        WHEN("computing the intersection") {
            auto intersection = RayUtils::sphericalIntersection(ray, sphere);
            THEN("none is found") {
                REQUIRE(!intersection);
            }
        }
    }
}

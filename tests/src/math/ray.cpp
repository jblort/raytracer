#include <iostream>

#include <catch.hpp>
#include <glm/glm.hpp>

#include "math/Ray.h"
#include "math/MathUtils.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

SCENARIO("Ray intersection") {
    GIVEN("a ray and a sphere that intersect") {
        Ray ray = Ray{glm::vec3(0.0, 0.0, -10.0), glm::vec3(0.0, 0.0, 1.0)};
        Sphere sphere = Sphere{glm::vec3(0.0, 0.0, 0.0), 2.0};

        WHEN("computing the intersection") {
            auto intersection = sphere.intersectionWith(ray);

            THEN("it returns the position and normal of the intersection") {
                REQUIRE(intersection);
                REQUIRE(isEqual(intersection->position, glm::vec3(0.0, 0.0, -2.0)));
                REQUIRE(isEqual(intersection->normal, glm::vec3(0.0, 0.0, -1.0)));
            }
        }
    }

    GIVEN("a ray and a sphere that don't intersect") {
        Ray ray = Ray{glm::vec3(0.0, 0.0, 10.0), glm::vec3(0.0, 1.0, 0.0)};
        Sphere sphere = Sphere{glm::vec3(0.0, 0.0, 0.0), 2.0};

        WHEN("computing the intersection") {
            auto intersection = sphere.intersectionWith(ray);
            THEN("none is found") {
                REQUIRE(!intersection);
            }
        }
    }
}

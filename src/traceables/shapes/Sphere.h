#pragma once

#include <glm/glm.hpp>

#include "traceables/Traceable.h"

namespace rt {

// A default red material for spheres
const SimpleMaterial DefaultMaterial = SimpleMaterial{
                                           Color{0.3, 0.0, 0.0},
                                           Color{0.7, 0.0, 0.0},
                                           Color{1.0, 1.0, 1.0},
                                           40.0
                                       };

class Sphere: public Traceable {
public:
    Sphere(const glm::vec3& center, double radius, const SimpleMaterial& material = DefaultMaterial);

    virtual ~Sphere();
public:

    virtual optional<RayIntersection> intersectionWith(const Ray& ray) override;

private:
    glm::vec3 _center;
    double _radius;
    SimpleMaterial _material;
};

}

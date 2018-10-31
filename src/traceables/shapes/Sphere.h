#pragma once

#include <glm/glm.hpp>

#include "materials/SimpleMaterial.h"
#include "traceables/Traceable.h"

namespace rt {

class Sphere: public Traceable {
public:
    Sphere(const glm::vec3& center, double radius, const SimpleMaterial& material = DefaultMaterial);

    virtual ~Sphere();
public:

    virtual optional<RayIntersection> intersectionWith(const Ray& ray) const override;

private:
    glm::vec3 _center;
    double _radius;
    SimpleMaterial _material;
};

}

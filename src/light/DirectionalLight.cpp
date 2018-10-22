#include "light/DirectionalLight.h"

using namespace rt;

DirectionalLight::DirectionalLight(const Color& color, const glm::vec3& direction):
_color{color},
_direction{glm::normalize(direction)}
{}

DirectionalLight::~DirectionalLight() {
}

double DirectionalLight::intensityAt(const RayIntersection& intersection) const {
    return 1.0;
}

Color DirectionalLight::color() const {
    return _color;
}

glm::vec3 DirectionalLight::directionRelativeTo(const RayIntersection& intersection) const {
    return _direction;
}


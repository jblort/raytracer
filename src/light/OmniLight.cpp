#include "light/OmniLight.h"

using namespace rt;

OmniLight::OmniLight(const Color& color, const glm::vec3& position, float falloff):
_lightColor{color},
_position{position},
_falloffDistance{falloff}
{}

OmniLight::~OmniLight(){
}

Color OmniLight::color() const {
    return _lightColor;
}

double OmniLight::intensityAt(const RayIntersection& i) const {
    return 1.0f; // For now use full intensity at all ranges
}

glm::vec3 OmniLight::directionRelativeTo(const RayIntersection& i) const {
    return glm::normalize(_position - i.position);
}

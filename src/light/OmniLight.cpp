#include "light/OmniLight.h"
#include "math/FloatingComp.h"


#include <cmath>

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
    auto dist = glm::length(_position - i.position);
    if (dist > _falloffDistance) { return 0.0; }
    if (isEqual(dist, 0.0)) { return 1.0; }
    auto relDist = dist / _falloffDistance;
    // Apply simple inverse square law for light dimming
    return 1.0 - 1.0 / std::sqrt(relDist);
}

glm::vec3 OmniLight::directionRelativeTo(const RayIntersection& i) const {
    return glm::normalize(_position - i.position);
}

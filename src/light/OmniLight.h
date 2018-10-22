#pragma once

#include "light/Light.h"

namespace rt {

    class OmniLight : public Light {
    public:
        OmniLight(const Color& color, const glm::vec3& position, float falloff = 1.0);
        virtual ~OmniLight();

    public:
        virtual Color color() const override;
        virtual double intensityAt(const RayIntersection& i) const override;
        virtual glm::vec3 directionRelativeTo(const RayIntersection& i) const override;

    private:
        Color _lightColor;
        glm::vec3 _position;
        float _falloffDistance;
    };

}

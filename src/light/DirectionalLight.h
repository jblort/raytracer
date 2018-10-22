#pragma once

#include "light/Light.h"

#include <glm/glm.hpp>

namespace rt {
    class DirectionalLight : public Light {
    public:
        DirectionalLight(const Color& color, const glm::vec3& direction);
        virtual ~DirectionalLight();

    public:
        virtual double intensityAt(const RayIntersection& intersection) const override;
        virtual Color color() const override;
        virtual glm::vec3 directionRelativeTo(const RayIntersection& intersection) const override;

    private:
        Color _color;
        glm::vec3 _direction;
    };
}

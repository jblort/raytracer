#pragma once

#include <glm/glm.hpp>

namespace rt {

    class Camera {
    public:
        // Initializes a camera with default properties
        Camera(const glm::vec3& position, const glm::vec3& orientation);

        glm::mat4 viewTransform() const;
        double    fovFactor() const;


    private:
        glm::mat4 _viewTransform;
        glm::vec3 _position;
        glm::vec3 _orientation;
        double    _fov;
        double    _fovFactor;
    };

}

#pragma once

#include <glm/glm.hpp>

namespace rt {

    class Camera {
    public:
        // Initializes a camera with default properties
        Camera(const glm::vec3& position, const glm::vec3& lootAt);

        glm::mat4 viewTransform() const;
        double    fovFactor() const;
        glm::vec3 position() const;

    private:
        glm::mat4 _viewTransform;
        glm::vec3 _position;
        glm::vec3 _lookAt;
        double    _fov;
        double    _fovFactor;
    };

}

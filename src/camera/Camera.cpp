#include "camera/Camera.h"

#include <glm/gtc/matrix_transform.hpp>

#include <cmath>

using namespace rt;

namespace {
    glm::mat4 makeViewTransform(const glm::vec3& position, const glm::vec3& orientation) {
        glm::mat4 viewTransform{1.0};

        viewTransform = glm::translate(viewTransform, position);
        viewTransform = glm::rotate(viewTransform, orientation.x, glm::vec3(1.0, 0.0, 0.0));
        viewTransform = glm::rotate(viewTransform, orientation.y, glm::vec3(0.0, 1.0, 0.0));
        viewTransform = glm::rotate(viewTransform, orientation.z, glm::vec3(0.0, 0.0, 1.0));

        return viewTransform;
    }
}

Camera::Camera(const glm::vec3& position, const glm::vec3& orientation):
_viewTransform{makeViewTransform(position, orientation)},
_position{position},
_orientation{orientation},
_fov{70.0},
_fovFactor{1 / std::tan(_fov / 2.0)}
{
}

glm::mat4 Camera::viewTransform() const {
    return _viewTransform;
}

double Camera::fovFactor() const {
    return _fovFactor;
}

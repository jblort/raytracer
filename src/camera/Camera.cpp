#include "camera/Camera.h"

#include "logging/Logger.h"

#include <glm/gtc/matrix_transform.hpp>

#include <cmath>

using namespace rt;

namespace {
    glm::mat4 makeViewTransform(const glm::vec3& position, const glm::vec3& lookAt) {
        auto eye = position;
        auto center = lookAt;
        auto up = glm::vec3{0.0, 1.0, 0.0};
        auto viewTransform = glm::lookAt(eye, center, up);
        return viewTransform;
    }
}

Camera::Camera(const glm::vec3& position, const glm::vec3& lookAt):
_viewTransform{makeViewTransform(position, lookAt)},
_position{position},
_lookAt{lookAt},
_fov{80.0},
_fovFactor{std::tan(_fov * M_PI * 0.5 / 180.0)}
{
}

glm::mat4 Camera::viewTransform() const {
    return _viewTransform;
}

double Camera::fovFactor() const {
    return _fovFactor;
}

glm::vec3 Camera::position() const {
    return _position;
}

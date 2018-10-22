#pragma once

#include "camera/Camera.h"
#include "image/Color.h"
#include "light/Light.h"
#include "math/Ray.h"

namespace rt {

    namespace PhongShading {
        Color simpleShading(const RayIntersection& intersection,
                            const Light& light,
                            const Camera& eye);
    }
}

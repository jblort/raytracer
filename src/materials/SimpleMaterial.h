#pragma once

#include "image/Color.h"

namespace rt {

    struct SimpleMaterial {
        Color ambientColor;
        Color diffuseColor;
        Color specularColor;
        double shininess;
    };

    const SimpleMaterial DefaultMaterial = SimpleMaterial{
                                           Color{0.3, 0.0, 0.0},
                                           Color{0.7, 0.0, 0.0},
                                           Color{1.0, 1.0, 1.0},
                                           40.0
                                       };
}

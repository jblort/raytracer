#pragma once

#include "image/Color.h"

namespace rt {

    struct SimpleMaterial {
        Color ambientColor;
        Color diffuseColor;
        Color specularColor;
        double shininess;
    };

}

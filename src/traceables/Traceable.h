#pragma once

#include "math/Ray.h"
#include "std_helpers/std_helpers.h"

namespace rt {

class Traceable {
public:
    virtual ~Traceable(){};

    virtual optional<RayIntersection> intersectionWith(const Ray& ray) = 0;
};

}

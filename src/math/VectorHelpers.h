#pragma once

#include <iostream>

#include <glm/glm.hpp>

namespace rt {

    template<typename T>
    float norm(const T& vec) {
        auto sum = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
        return std::sqrt(sum);
    }
}

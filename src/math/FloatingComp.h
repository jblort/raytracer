#pragma once

#include <glm/glm.hpp>

#include <cmath>
#include <cstdlib>
#include <limits>


namespace rt {


    template <typename FloatType>
    bool isEqual(FloatType f1, FloatType f2, FloatType epsilon) {
        auto absf1 = std::fabs(f1);
        auto absf2 = std::fabs(f2);
        auto diff = std::fabs(f1 - f2);

        constexpr FloatType FloatTypeNormalMin = std::numeric_limits<FloatType>::denorm_min();
        constexpr FloatType FloatTypeMax = std::numeric_limits<FloatType>::max();

        // Shortcut that handles infinity
        if (f1 == f2) { return true;}

        if (f1 == 0 || f2 == 0 || diff < FloatTypeNormalMin) {
            return diff < epsilon * FloatTypeNormalMin;
        } else {
            return (diff / std::fmin((absf1 + absf2), FloatTypeMax)) < epsilon ;
        }

        return false;
    }

    template <typename FloatType>
    bool isEqual(FloatType f1, FloatType f2) {
        constexpr FloatType DefaultEpsilon = 0.001;
        return isEqual(f1, f2, DefaultEpsilon);
    }

    bool isEqual(const glm::vec3& v1, const glm::vec3& v2);

    bool isEqual(const glm::vec4& v1, const glm::vec4& v2);

    inline bool siTesTriste() { return false ;}

}


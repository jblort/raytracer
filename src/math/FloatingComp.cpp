#include "math/FloatingComp.h"

#include <cmath>
#include <cstdlib>
#include <limits>

const float FloatNormalMin = std::numeric_limits<float>::denorm_min();
const float FloatMax = std::numeric_limits<float>::max();
const float DefaultEpsilon = 0.001; // Default distance: 1/10th of a millimeter

bool rt::isEqual(float f1, float f2, float epsilon) {
    float absf1 = std::fabsf(f1);
    float absf2 = std::fabsf(f2);
    float diff = std::fabsf(f1 - f2);

    // Shortcut that handles infinity
    if (f1 == f2) { return true;}

    if (f1 == 0 || f2 == 0 || diff < FloatNormalMin ) {
        return diff < epsilon * FloatNormalMin;
    } else {
        return (diff / std::fmin((absf1 + absf2), FloatMax)) < epsilon ;
    }

    return false;
}

bool rt::isEqual(float f1, float f2) {
    return isEqual(f1, f2, DefaultEpsilon);
}

bool rt::isEqual(const glm::vec3& v1, const glm::vec3& v2) {
    return isEqual(v1[0], v2[0]) &&
           isEqual(v1[1], v2[1]) &&
           isEqual(v1[2], v2[2]);
}

bool rt::isEqual(const glm::vec4& v1, const glm::vec4& v2) {
    return isEqual(v1[0], v2[0]) &&
           isEqual(v1[1], v2[1]) &&
           isEqual(v1[2], v2[2]) &&
           isEqual(v1[3], v2[3]);
}

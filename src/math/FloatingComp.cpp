#include "math/FloatingComp.h"

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

#include "math/VectorHelpers.h"

std::ostream& rt::operator<<(std::ostream& os, const glm::vec3& v) {
    os << v[0] << " " << v[1] << " " << v[2];
    return os;
}

std::ostream& rt::operator<<(std::ostream& os, const glm::vec4& v) {
    os << v[0] << " " << v[1] << " " << v[2] << " " << v[3];
    return os;
}

#include "logging/StreamableGlm.h"

std::ostream& rt::operator<<(std::ostream& os, const glm::vec3& vec) {
    os << "[vec3]: " << "(" << vec.x << ", "
                            << vec.y << ", "
                            << vec.z << ")";
    return os;
}

std::ostream& rt::operator<<(std::ostream& os, const glm::vec4& vec) {
    os << "[vec4]: " << "(" << vec.x << ", "
                            << vec.y << ", "
                            << vec.z << ", "
                            << vec.w << ")";
    return os;

}
std::ostream& rt::operator<<(std::ostream& os, const glm::mat3& mat) {
    os << "[mat3]:\n"
       << "┌ " << mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << " ┐\n"
       << "│ " << mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << " │\n"
       << "└ " << mat[2][0] << " " << mat[2][1] << " " << mat[2][2] << " ┘\n";

    return os;
}

std::ostream& rt::operator<<(std::ostream& os, const glm::mat4& mat) {
    os << "[mat4]:\n"
       << "┌ " << mat[0][0] << " " << mat[0][1] << " " << mat[0][2] << " " << mat[0][3] << " ┐\n"
       << "│ " << mat[1][0] << " " << mat[1][1] << " " << mat[1][2] << " " << mat[1][3] << " │\n"
       << "│ " << mat[2][0] << " " << mat[2][1] << " " << mat[2][2] << " " << mat[2][3] << " │\n"
       << "└ " << mat[3][0] << " " << mat[3][1] << " " << mat[3][2] << " " << mat[3][3] << " ┘\n";

    return os;
}

#pragma once

#include <glm/glm.hpp>

#include <ostream>

namespace rt {

    std::ostream& operator<<(std::ostream& os, const glm::vec3& vec);
    std::ostream& operator<<(std::ostream& os, const glm::vec4& vec);
    std::ostream& operator<<(std::ostream& os, const glm::mat3& mat);
    std::ostream& operator<<(std::ostream& os, const glm::mat4& mat);

}

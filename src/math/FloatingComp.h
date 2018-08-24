#pragma once

#include <glm/glm.hpp>

namespace rt {

    bool isEqual(float f1, float f2);

    bool isEqual(float f1, float f2, float epsilon);

    bool isEqual(const glm::vec3& v1, const glm::vec3& v2);

    bool isEqual(const glm::vec4& v1, const glm::vec4& v2);

    inline bool siTesTriste() { return false ;}

}


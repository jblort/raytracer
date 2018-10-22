#include "shading/PhongShading.h"

#include <algorithm>

using namespace rt;

Color PhongShading::simpleShading(const RayIntersection& intersection,
                                  const Light& light,
                                  const Camera& eye) {
    auto L = light.directionRelativeTo(intersection);
    auto N = intersection.normal;
    auto R = glm::normalize(glm::reflect(L, N));
    auto V = glm::normalize(intersection.position - eye.position());
    auto RV = std::fmax(glm::dot(R,V), 0.0f);
    auto NL = std::fmax(glm::dot(L, N), 0.0f);
    auto diffuseColor = intersection.localMaterial.diffuseColor;
    auto specularColor = intersection.localMaterial.specularColor;
    auto shininess = intersection.localMaterial.shininess;
    auto intensity = light.intensityAt(intersection);
    auto phongCol = diffuseColor * light.color() * intensity * NL + specularColor * intensity * std::pow(RV, shininess);

    return phongCol;
}

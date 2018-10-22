#include "shading/PhongShading.h"

using namespace rt;

Color PhongShading::simpleShading(const RayIntersection& intersection,
                                  const Light& light,
                                  const Camera& eye) {
    auto L = light.directionRelativeTo(intersection);
    auto N = intersection.normal;
    auto R = glm::normalize(glm::reflect(L, N));
    auto V = glm::normalize(intersection.position - eye.position());
    auto RV = glm::dot(R,V);
    RV = RV > 0 ? RV : 0;
    auto NL = glm::dot(L, N);
    NL = NL > 0 ? NL : 0;
    auto diffuseColor = intersection.localMaterial.diffuseColor;
    auto specularColor = intersection.localMaterial.specularColor;
    auto shininess = intersection.localMaterial.shininess;
    auto phongCol = diffuseColor * NL + specularColor * std::pow(RV, shininess);

    return phongCol;
}

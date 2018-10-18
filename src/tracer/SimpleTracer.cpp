#include "tracer/SimpleTracer.h"

#include "camera/Camera.h"
#include "image/Color.h"
#include "image/Image.h"
#include "logging/Logger.h"
#include "math/Ray.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

Image SimpleTracer::trace(TracerOptions options) {
    auto sphere = Sphere{glm::vec3{0.0, 0.0, 0.0}, 2.0};
    auto camera = Camera{glm::vec3{0.0, 0.0, -5.0}, glm::vec3{0.0, 0.0, 0.0}};
    auto lightPosition = glm::vec3{0.0, 3.0, -3.0};
    auto lightColor = Color{0.8, 0.8, 0.8};
    auto clearColor = Color{0.1, 0.1, 0.1};
    auto w = options.traceWidth;
    auto h = options.traceHeight;
    auto resultImage = rt::emptyImage(options.traceWidth,
                                      options.traceHeight,
                                      options.traceFormat);

    for (unsigned int y = 0; y < resultImage.height(); ++y) {
        for (unsigned int x = 0; x < resultImage.width(); ++x) {

            // Reverse y so we implicitly flip the resulting image
            auto primaryRay = Raytracing::makePrimaryRay(x, h - y, w, h, camera);
            auto intersection = sphere.intersectionWith(primaryRay);

            if (intersection) {
                auto L = glm::normalize(lightPosition - intersection->position);
                auto N = intersection->normal;
                auto R = glm::normalize(glm::reflect(L, N));
                auto V = glm::normalize(intersection->position - camera.position());
                auto RV = glm::dot(R,V);
                RV = RV > 0 ? RV : 0;
                auto NL = glm::dot(L, N);
                NL = NL > 0 ? NL : 0;
                auto diffuseColor = intersection->localMaterial.diffuseColor;
                auto specularColor = intersection->localMaterial.specularColor;
                auto shininess = intersection->localMaterial.shininess;
                auto phongCol = diffuseColor * NL + specularColor * std::pow(RV, shininess);

                resultImage.fillColorAt(x, y, phongCol);
            } else {
                resultImage.fillColorAt(x, y, clearColor);
            }
        }
    }

    return resultImage;
}

#include "tracer/SimpleTracer.h"

#include "camera/Camera.h"
#include "image/Color.h"
#include "image/Image.h"
#include "light/OmniLight.h"
#include "logging/Logger.h"
#include "math/Ray.h"
#include "math/VectorHelpers.h"
#include "shading/PhongShading.h"
#include "traceables/shapes/Sphere.h"

#include <limits>

using namespace rt;

Image SimpleTracer::trace(TracerOptions options) {
    auto sphere = std::make_shared<Sphere>(glm::vec3{0.0, 0.0, 0.0}, 2.0);
    auto smallSphere = std::make_shared<Sphere>(glm::vec3{6.0, 0.0, 0.0}, 2.0);
    auto otherSphere = std::make_shared<Sphere>(glm::vec3{-6.0, 0.0, 0.0}, 2.0);
    auto shadowSphere = std::make_shared<Sphere>(glm::vec3{0.0, 2.5, 2.5}, 0.3);
    auto camera = Camera{glm::vec3{0.0, 0.0, 10.0}, glm::vec3{0.0, 0.0, 0.0}};
    auto lightPosition = glm::vec3{0.0, 5.0, 5.0};
    auto lightColor = Color{0.8, 0.8, 0.8};
    auto light = OmniLight{lightColor, lightPosition, 30.0};
    auto clearColor = Color{0.1, 0.1, 0.1};
    auto w = options.traceWidth;
    auto h = options.traceHeight;
    auto resultImage = rt::emptyImage(options.traceWidth,
                                      options.traceHeight,
                                      options.traceFormat);

    auto traceables = std::list<sptr<Traceable>>{sphere, smallSphere, otherSphere, shadowSphere};

    for (unsigned int y = 0; y < resultImage.height(); ++y) {
        for (unsigned int x = 0; x < resultImage.width(); ++x) {

            // Reverse y so we implicitly flip the resulting image
            auto primaryRay = Raytracing::makePrimaryRay(x, y, w, h, camera);

            auto closestIntersection = Raytracing::closestIntersection(primaryRay, traceables);

            if (closestIntersection) {
                auto shadowRay = Raytracing::makeShadowRay(closestIntersection->position, lightPosition);

                auto shadowIntersection = Raytracing::closestIntersection(shadowRay, traceables);

                if (shadowIntersection) {
                    resultImage.fillColorAt(x, y, Color{0.0, 0.0, 0.0, 1.0});
                }
                else {
                    auto color = PhongShading::simpleShading(*closestIntersection, light, camera);
                    resultImage.fillColorAt(x, y, color);
                }
            } else {
                resultImage.fillColorAt(x, y, clearColor);
            }
        }
    }

    return resultImage;
}

#include "tracer/SimpleTracer.h"

#include "camera/Camera.h"
#include "image/Color.h"
#include "image/Image.h"
#include "light/OmniLight.h"
#include "logging/Logger.h"
#include "math/Ray.h"
#include "shading/PhongShading.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

Image SimpleTracer::trace(TracerOptions options) {
    auto sphere = Sphere{glm::vec3{0.0, 0.0, 0.0}, 2.0};
    auto camera = Camera{glm::vec3{0.0, 0.0, -5.0}, glm::vec3{0.0, 0.0, 0.0}};
    auto lightPosition = glm::vec3{0.0, 3.0, -3.0};
    auto lightColor = Color{0.8, 0.8, 0.8};
    auto light = OmniLight{lightColor, lightPosition};
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
                auto color = PhongShading::simpleShading(*intersection, light, camera);
                resultImage.fillColorAt(x, y, color);
            } else {
                resultImage.fillColorAt(x, y, clearColor);
            }
        }
    }

    return resultImage;
}

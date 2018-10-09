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
    auto sphereColor = Color{0.6, 0.0, 0.0};
    auto lightPosition = glm::vec3{0.0, 2.0, 1.0};
    auto clearColor = Color{0.3, 0.3, 0.3};
    auto w = options.traceWidth;
    auto h = options.traceHeight;
    auto aspectRatio = w / h;
    auto resultImage = rt::emptyImage(options.traceWidth,
                                      options.traceHeight,
                                      options.traceFormat);

    for (unsigned int y = 0; y < resultImage.height(); ++y) {
        for (unsigned int x = 0; x < resultImage.width(); ++x) {
            auto pixelNDCx = (x + 0.5) / w;
            auto pixelNDCy = (y + 0.5) / h;
            auto u = aspectRatio * (2 * pixelNDCx - 1);
            auto v = 2 * pixelNDCy - 1;

            auto primaryRay = RayUtils::makePrimaryRay(u, v, camera);
            auto intersection = RayUtils::sphericalIntersection(primaryRay, sphere);

            if (intersection) {
                //auto shadowRay = RayUtils::makeShadowRay(intersection->position, lightPosition);
                resultImage.fillColorAt(x, y, sphereColor);
            } else {
                resultImage.fillColorAt(x, y, clearColor);
            }
        }
    }

    return resultImage;
}

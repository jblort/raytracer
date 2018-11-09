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
    auto sphere = Sphere{glm::vec3{0.0, 0.0, 0.0}, 2.0};
    auto smallSphere = Sphere{glm::vec3{6.0, 0.0, 0.0}, 2.0};
    auto otherSphere = Sphere{glm::vec3{-6.0, 0.0, 0.0}, 2.0};
    auto camera = Camera{glm::vec3{0.0, 0.0, 10.0}, glm::vec3{0.0, 0.0, 0.0}};
    auto lightPosition = glm::vec3{0.0, 4.0, 4.0};
    auto lightColor = Color{0.8, 0.8, 0.8};
    auto light = OmniLight{lightColor, lightPosition, 30.0};
    auto clearColor = Color{0.1, 0.1, 0.1};
    auto w = options.traceWidth;
    auto h = options.traceHeight;
    auto resultImage = rt::emptyImage(options.traceWidth,
                                      options.traceHeight,
                                      options.traceFormat);

    auto traceables = {sphere, smallSphere, otherSphere};

    for (unsigned int y = 0; y < resultImage.height(); ++y) {
        for (unsigned int x = 0; x < resultImage.width(); ++x) {

            // Reverse y so we implicitly flip the resulting image
            auto primaryRay = Raytracing::makePrimaryRay(x, y, w, h, camera);

            auto closestIntersection = optional<RayIntersection>();
            auto closestIntersectionDist = std::numeric_limits<double>::max();

            for (auto traceable : traceables) {
                auto intersection = traceable.intersectionWith(primaryRay);
                if (intersection) {
                    auto dist =  rt::norm(intersection->position - primaryRay.origin);
                    if (dist < closestIntersectionDist) {
                        closestIntersectionDist = dist;
                        closestIntersection = intersection;
                    }
                }
            }

            if (closestIntersection) {
                auto color = PhongShading::simpleShading(*closestIntersection, light, camera);
                resultImage.fillColorAt(x, y, color);
            } else {
                resultImage.fillColorAt(x, y, clearColor);
            }
        }
    }

    return resultImage;
}

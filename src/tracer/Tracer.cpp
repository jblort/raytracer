#include "tracer/Tracer.h"

#include <iostream>

#include "camera/Camera.h"
#include "math/Ray.h"
#include "traceables/shapes/Sphere.h"

using namespace rt;

Image raytracer::traceDefaultImage(TracerOptions options) {
    auto image = emptyImage(options.traceWidth,
                            options.traceHeight,
                            options.traceFormat);
    std::cout << "Params: " << options.traceWidth << " " << options.traceHeight << "\n";
    std::cout << "Created image of size " << image.width() << "x" << image.height() << "\n";

    Camera camera{glm::vec3(0.0, 0.0, 5.0), glm::vec3(0.0, 0.0, -1.0)};
    Sphere sphere{glm::vec3(0.0, 0.0, 0.0), 2.0};
    Color sphereColor{0.9, 0.0, 0.0};

    glm::vec3 lightPosition{0.0, 6.0, -4.0};
    Color lightColor{0.7, 0.7, 0.7};

    for (unsigned int y = 0; y < image.height(); ++y) {
        for (unsigned int x = 0; x < image.width(); ++x) {
            // Default initialize the computed color for a given pixel
            // to the "clear" color.
            Color computedColor = Color{0.2, 0.2, 0.2, 0.2};

            // Create ray
            auto pRay = Raytracing::makePrimaryRay(x, y, image.width(), image.height(), camera);
            // Find intersection with an object in the scene
            auto intersection = sphere.intersectionWith(pRay);

            if (intersection) {
                // Compute lighting
                auto shadowRay = Raytracing::makeShadowRay(intersection->position, lightPosition);
                computedColor = 0.5 * lightColor + 0.5 * sphereColor;
            }

            // If intersection, compute lighthing contribution
            // if (intersection.distance != infinity) {
            //     for (auto& light : lights) {
            //         auto shadowRay = Raytracing::makeShadowRay();
            //         // Angles at point of intersection
            //         // Light contribution at intersection
            //         // compose light
            //     }
            // } else (
            //     // do nothing, use clear color;
            // }
            // Assign resulting color to the currently computed pixel;
            image.fillColorAt(x, y, computedColor);
        }
    }

    return image;
}

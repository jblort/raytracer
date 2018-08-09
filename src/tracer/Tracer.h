#pragma once

#include "image/Image.h"

namespace rt {

    struct TracerOptions {
        int traceWidth = 1024;
        int traceHeight = 768;
        Color clearColor = {0, 0, 0};
        PixelFormat traceFormat = PixelFormat::RGB;
    };

    namespace raytracer {
        Image traceDefaultImage(TracerOptions options = TracerOptions());

//        Image traceImageFromScene(const Scene& scene,
//                                  TracerOptions options = TracerOptions());
    }
}

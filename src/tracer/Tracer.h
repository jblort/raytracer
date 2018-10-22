#pragma once

#include "image/Image.h"
#include "tracer/TracerOptions.h"

namespace rt {

    namespace raytracer {
        Image traceDefaultImage(TracerOptions options);

//        Image traceImageFromScene(const Scene& scene,
//                                  TracerOptions options = TracerOptions());
    }
}

#pragma once

#include "image/Image.h"
#include "tracer/Tracer.h"

namespace rt {

    namespace SimpleTracer {
        Image trace(TracerOptions options = TracerOptions{});
    }

}

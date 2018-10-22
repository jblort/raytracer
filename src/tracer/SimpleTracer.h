#pragma once

#include "image/Image.h"
#include "tracer/TracerOptions.h"

namespace rt {

    namespace SimpleTracer {
        Image trace(TracerOptions options);
    }

}

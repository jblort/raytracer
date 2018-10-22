#pragma once

#include "image/Image.h"

namespace rt {

struct TracerOptions {
    int traceWidth = 1024;
    int traceHeight = 768;
    int antialiasingFactor = 1;
    Color clearColor = {0, 0, 0};
    PixelFormat traceFormat = PixelFormat::RGB;
};

}

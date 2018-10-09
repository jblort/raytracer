#include <argh.h>

#include "image/ImageIO.h"
#include "tracer/SimpleTracer.h"

int main(int argc, char** argv) {
    using namespace rt;

    auto image = SimpleTracer::trace();

    ImageIO::saveToFile(image, "default.tga");

    return 0;
}

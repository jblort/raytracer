#include <argh.h>

#include "image/ImageIO.h"
#include "tracer/Tracer.h"

int main(int argc, char** argv) {
    using namespace rt;

    auto image = raytracer::traceDefaultImage();

    ImageIO::saveToFile(image, "default.tga");

    return 0;
}

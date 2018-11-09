#include "image/ImageIO.h"
#include "logging/Logger.h"
#include "tracer/SimpleTracer.h"

#include <argh.h>

#include <iostream>

int main(int argc, char** argv) {
    using namespace rt;

    argh::parser cliParser;
    cliParser.add_params({"-w", "--width", "-h", "--height", "-a", "--aafactor"});

    cliParser.parse(argv);

    int width = 1024;
    int height = 768;

    if (cliParser({"-w", "--width"}) != cliParser({"-h", "--height"})) {
        std::cout << "You must specify both width and height for these values to be used" << "\n";
    } else {
        cliParser({"-w", "--width"}, 1024) >> width;
        cliParser({"-h", "--height"}, 768) >> height;
    }

    int aaFactor; cliParser({"-a", "--aafactor"}, 1) >> aaFactor;

    auto tracerOptions = TracerOptions{};
    tracerOptions.traceWidth = width;
    tracerOptions.traceHeight = height;
    tracerOptions.antialiasingFactor = aaFactor;

    std::cout << "Tracing image of size: " << tracerOptions.traceWidth << "x" << tracerOptions.traceHeight << "\n";
    std::cout << "Antialiasing factor is: " << tracerOptions.antialiasingFactor << "\n";
    auto image = SimpleTracer::trace(tracerOptions);

    ImageIO::saveToFile(image, "default.tga");

    return 0;
}

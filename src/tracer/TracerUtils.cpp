#include "tracer/TracerUtils.h"

using namespace rt;

std::pair<double, double> TracerUtils::deviceCoordinates(int pixelX, int pixelY, int viewportWidth, int viewportHeight) {
    double ratio = double(viewportWidth) / double(viewportHeight);
    double u = ratio * (2 * pixelX / viewportWidth - 1);
    double v = 2 * pixelY / viewportHeight - 1;

    return std::make_pair(u, v);
}

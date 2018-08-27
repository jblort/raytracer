#pragma once

#include <utility>

namespace rt {

    namespace TracerUtils {

        std::pair<double, double> deviceCoordinates(int pixelX, int pixelY, int viewportWidth, int viewportHeight);

    }
}

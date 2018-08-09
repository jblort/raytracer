#pragma once

#include <string>

#include "Image.h"

namespace rt {
namespace ImageIO {

    void saveToFile(const Image& image, const std::string& destinationPath);

}
}

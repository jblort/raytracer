#include "image/ImageIO.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "image/stb_image_write.h"

using namespace rt;

void ImageIO::saveToFile(const Image& image, const std::string& destinationPath) {

    auto pixels = image.pixels();
    auto channels = channelsForFormat(image.format());
    auto width = image.width();
    auto height = image.height();

    stbi_write_tga(destinationPath.c_str(), width, height, channels, pixels.data());
}

#include "image/Image.h"

#include <iostream>

using namespace rt;

int rt::channelsForFormat(const PixelFormat& format) {
    switch(format) {
    case PixelFormat::RGB:
        return 3;
    case PixelFormat::RGBA:
        return 4;
    case PixelFormat::Grayscale:
        return 1;
    }
}

Image::Image()
{}

Image::Image(std::vector<unsigned char> pixels, int width, int height, PixelFormat format):
_pixels{std::move(pixels)},
_width{width},
_height{height},
_format{format}
{}

void Image::fillColorAt(int x, int y, Color color) {
    switch(_format) {
    case PixelFormat::RGB:
        fillRGBColorAt(x, y, color);
        break;
    case PixelFormat::RGBA:
        fillRGBAColorAt(x, y, color);
        break;
    case PixelFormat::Grayscale:
        fillGrayscaleColorAt(x, y, color);
        break;
    }
}


void Image::fillRGBColorAt(int x, int y, Color color) {
    auto pixelStart = (x + y * _width) * 3;

    _pixels[pixelStart] = color.r() * 255;
    _pixels[pixelStart + 1] = color.g() * 255;
    _pixels[pixelStart + 2] = color.b() * 255;
}

void Image::fillRGBAColorAt(int x, int y, Color color) {
    auto pixelStart = (x + y * _width) * 4;

    _pixels[pixelStart] = color.r() * 255;
    _pixels[pixelStart + 1] = color.g() * 255;
    _pixels[pixelStart + 2] = color.b() * 255;
    _pixels[pixelStart + 3] = color.a() * 255;
}

void Image::fillGrayscaleColorAt(int x, int y, Color color) {
    auto pixelIndex = x + y * _width;
    _pixels[pixelIndex] = color.r() * 255;
}

Image rt::emptyImage(int width, int height, PixelFormat format) {
    int channelCount = channelsForFormat(format);
    auto pixels = std::vector<unsigned char>(width * height * channelCount);
    std::cout << "Creating empty image of size: " << width << " x " << height << " and channels: " << channelCount << "\n";
    Image emptyImage{pixels, width, height, format};
    return emptyImage;
}

#pragma once

#include <vector>

#include "image/Color.h"

namespace rt {

enum class PixelFormat {
    RGB,
    RGBA,
    Grayscale
};

int channelsForFormat(const PixelFormat& format);

class Image {
public:
    Image();
    Image(std::vector<unsigned char> pixels, int width, int height, PixelFormat format);

    void fillColorAt(int x, int y, Color color);

    const std::vector<unsigned char>& pixels() const { return _pixels; }
    int width() const { return _width; }
    int height() const { return _height; }
    PixelFormat format() const { return _format; }

private:
    void fillRGBColorAt(int x, int y, Color color);
    void fillRGBAColorAt(int x, int y, Color color);
    void fillGrayscaleColorAt(int x, int y, Color color);

private:
    std::vector<unsigned char> _pixels;
    int _width, _height;
    PixelFormat _format;
};

Image emptyImage(int width, int height, PixelFormat format);

}

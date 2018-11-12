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
    Image emptyImage{pixels, width, height, format};
    return emptyImage;
}

Image rt::sampledImage(const Image& srcImage, int samplingFactor) {
    auto srcPixels = srcImage.pixels();
    auto srcWidth = srcImage.width();
    auto srcHeight = srcImage.height();
    auto resultImage = emptyImage(srcImage.width() / samplingFactor,
                                  srcImage.height() / samplingFactor,
                                  srcImage.format());

    for (int x = 0; x < resultImage.width(); ++x) {
        for (int y = 0; y < resultImage.height(); ++y) {

            float sampledRed = 0.0f, sampledGreen = 0.0f, sampledBlue = 0.0f;

            for (int i = 0; i < samplingFactor; i++) {
                for (int j = 0; j < samplingFactor; j++) {
                    auto pixelIndex = ((y + i) * srcWidth + x + j) * 3;
                    sampledRed += srcPixels[pixelIndex] / 255.f;
                    sampledGreen += srcPixels[pixelIndex+1] / 255.f;
                    sampledBlue += srcPixels[pixelIndex+2] / 255.f;
                }
            }

            float count = float(samplingFactor * samplingFactor);
            sampledRed /= count;
            sampledGreen /= count;
            sampledBlue /= count;

            auto sampledColor = Color{sampledRed, sampledGreen, sampledBlue};
            resultImage.fillColorAt(x, y, sampledColor);
        }
    }

    return resultImage;
}

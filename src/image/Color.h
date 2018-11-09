#pragma once

#include <algorithm>
#include <cmath>

namespace rt {

struct Color {
private:
    float _red;
    float _green;
    float _blue;
    float _alpha;

public:
    Color(float r, float g, float b, float a);
    Color(float r, float g, float b);

    float r() const;
    float g() const;
    float b() const;
    float a() const;
};

Color operator+(const Color& lhs, const Color& rhs);
Color operator*(const Color& lhs, const Color& rhs);
Color operator-(const Color& lhs, const Color& rhs);

template<typename T>
inline Color operator*(const Color& color, const T& value) {
    return Color{float(std::min(color.r() * value, 1.0)),
                 float(std::min(color.g() * value, 1.0)),
                 float(std::min(color.b() * value, 1.0)),
                 float(std::min(color.a() * value, 1.0))};
}

template<>
inline Color operator*<float>(const Color& color, const float& value) {
    return Color{std::min(color.r() * value, 1.0f),
                 std::min(color.g() * value, 1.0f),
                 std::min(color.b() * value, 1.0f),
                 std::min(color.a() * value, 1.0f)};

}

template<typename T>
inline Color operator*(const T& value, const Color& color) {
    return color * value;
}

}

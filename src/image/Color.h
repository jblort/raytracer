#pragma once

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


template<typename T>
Color operator*(const Color& color, const T& value) {
    return Color{std::fmin(float(color.r() * value), 1.0),
                 std::fmin(float(color.g() * value), 1.0),
                 std::fmin(float(color.b() * value), 1.0),
                 std::fmin(float(color.a() * value), 1.0)};
}

template<typename T>
Color operator*(const T& value, const Color& color) {
    return color * value;
}

}

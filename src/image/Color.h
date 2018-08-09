#pragma once

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
    return Color{float(color.r()* value),
                 float(color.g() * value),
                 float(color.b() * value),
                 float(color.a() * value)};
}

template<typename T>
Color operator*(const T& value, const Color& color) {
    return color * value;
}

}

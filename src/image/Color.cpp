#include "image/Color.h"

#include <algorithm>

using namespace rt;

Color::Color(float r, float g, float b, float a):
_red{std::min(r, 1.0f)},
_green{std::min(g, 1.0f)},
_blue{std::min(b, 1.0f)},
_alpha{std::min(a, 1.0f)}
{}

Color::Color(float r, float g, float b):
Color{r, g, b, 1.0f}
{}

float Color::r() const {
    return _red;
}

float Color::g() const {
    return _green;
}

float Color::b() const {
    return _blue;
}

float Color::a() const {
    return _alpha;
}

Color rt::operator+(const Color& lhs, const Color& rhs) {
    auto r = lhs.r() + rhs.r();
    auto g = lhs.g() + rhs.g();
    auto b = lhs.b() + rhs.b();
    auto a = lhs.a() + rhs.a();

    return Color{r, g, b, a};
}

Color rt::operator*(const Color& lhs, const Color& rhs) {
    auto r = lhs.r() * rhs.r();
    auto g = lhs.g() * rhs.g();
    auto b = lhs.b() * rhs.b();
    auto a = lhs.a() * rhs.a();

    return Color{r, g, b, a};
}

Color rt::operator-(const Color& lhs, const Color& rhs) {
    auto r = lhs.r() - rhs.r();
    auto g = lhs.g() - rhs.g();
    auto b = lhs.b() - rhs.b();
    auto a = lhs.a() - rhs.a();

    return Color{r, g, b, a};
}

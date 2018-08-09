#pragma once

namespace rt {

struct Color {
    int red;
    int green;
    int blue;
    int alpha;
};

template<typename T>
Color operator*(const Color& color, const T& value) {
    return Color{color.red * value,
                 color.green * value,
                 color.blue * value,
                 color.alpha * value};
}

template<typename T>
Color operator*(const T& value, const Color& color) {
    return color * value;
}

}

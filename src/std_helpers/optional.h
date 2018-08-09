#pragma once

// OSX Clang doesn't support optional yet
#ifdef __APPLE__
    #include <experimental/optional>
#else
    #include <optional>
#endif

template<typename T>
using optional = std::experimental::optional<T>;

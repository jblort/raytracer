#pragma once

// OSX Clang doesn't support optional yet
#ifdef __APPLE__
    #include <experimental/optional>
    template<typename T>
    using optional = std::experimental::optional<T>;
#else
    #include <optional>
    template<typename T>
    using optional = std::optional<T>;
#endif



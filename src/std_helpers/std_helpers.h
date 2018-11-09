#pragma once

#include "std_helpers/optional.h"

#include <memory>

template<typename T>
using sptr = std::shared_ptr<T>;

template<typename T>
using uptr = std::unique_ptr<T>;

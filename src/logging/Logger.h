#pragma once
#include <sstream>

#include "logging/StreamableGlm.h"

namespace rt {

    /// A simple logging class that outputs logs to the standard
    /// output
    class Logger {
    public:
        /// Logger can only be default constructed, and we avoid copies for now
        Logger();
        ~Logger();
        Logger(const Logger& other) = delete;
        Logger(const Logger&& other) = delete;
        Logger& operator=(const Logger& other) = delete;

    public:
        std::ostream& critical();
        std::ostream& error();
        std::ostream& warning();
        std::ostream& info();
        std::ostream& debug();
        std::ostream& verbose();
    };
}

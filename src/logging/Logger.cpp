#include "logging/Logger.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <ostream>

using namespace rt;

namespace {
const short PrefixMaxLength = 10;

std::ostream& formattedLogStream(const std::string& prefix) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    return std::cout << std::put_time(std::localtime(&time), "%F-%T") << std::left << std::setw(PrefixMaxLength)
                     << prefix << ": ";
}
} // namespace

Logger::Logger() {}

Logger::~Logger() {
    std::cout << "\n";
}

std::ostream& Logger::critical() {
    return formattedLogStream("[Critical]");
}

std::ostream& Logger::error() {
    return formattedLogStream("[Error]");
}

std::ostream& Logger::warning() {
    return formattedLogStream("[Warning]");
}

std::ostream& Logger::info() {
    return formattedLogStream("[Info]");
}

std::ostream& Logger::debug() {
    return formattedLogStream("[Debug]");
}

std::ostream& Logger::verbose() {
    return formattedLogStream("[Verbose]");
}

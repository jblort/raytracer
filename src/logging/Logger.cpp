#include "logging/Logger.h"

#include <boost/format.hpp>

#include <chrono>
#include <iomanip>
#include <iostream>
#include <ostream>

using namespace rt;
using bft = boost::format;

namespace {
const short PrefixMaxLength = 10;

std::ostream& formattedLogStream(const std::string& prefix) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    return std::cout << std::put_time(std::localtime(&time), "%F-%T") << std::left << std::setw(PrefixMaxLength)
                     << prefix << ": ";
}

const auto sw = std::setw(8);
const auto sp = std::setprecision(6);

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

void Logger::logVector(const glm::vec3& vec, const std::string& name) {
    info() << (name.empty() ? "" : name) << (name.empty() ? "" : " -> ")
           << "[vec3]: " << "(" << vec.x << ", "
                                << vec.y << ", "
                                << vec.z << ")";
}

void Logger::logVector(const glm::vec4& vec, const std::string& name) {
    info() << (name.empty() ? "" : name) << (name.empty() ? "" : " -> ")
           << "[vec4]: "
           << "("
           << vec.x << ", "
           << vec.y << ", "
           << vec.z << ", "
           << vec.w << ")";
}

void Logger::logMatrix(const glm::mat3& mat, const std::string& name) {
    info() << (name.empty() ? "" : name) << (name.empty() ? "" : " -> ") << "[mat3]:\n";
    info() << (bft("┌ %|+5.3f| %|+5.3f| %|+5.3f| ┐") % mat[0][0] % mat[0][1] % mat[0][2]).str() << "\n";
    info() << (bft("│ %|+5.3f| %|+5.3f| %|+5.3f| │") % mat[1][0] % mat[1][1] % mat[1][2]).str() << "\n";
    info() << (bft("└ %|+5.3f| %|+5.3f| %|+5.3f| ┘") % mat[2][0] % mat[2][1] % mat[2][2]).str();
}

void Logger::logMatrix(const glm::mat4& mat, const std::string& name) {
    info() << (name.empty() ? "" : name) << (name.empty() ? "" : " -> ") << "[mat4]:\n";
    info() << (bft("┌ %|+5.3f| %|+5.3f| %|+5.3f| %|+5.3f| ┐") % mat[0][0] % mat[0][1] % mat[0][2] % mat[0][3]).str() << "\n";
    info() << (bft("│ %|+5.3f| %|+5.3f| %|+5.3f| %|+5.3f| │") % mat[1][0] % mat[1][1] % mat[1][2] % mat[1][3]).str() << "\n";
    info() << (bft("│ %|+5.3f| %|+5.3f| %|+5.3f| %|+5.3f| │") % mat[2][0] % mat[2][1] % mat[2][2] % mat[2][3]).str() << "\n";
    info() << (bft("└ %|+5.3f| %|+5.3f| %|+5.3f| %|+5.3f| ┘") % mat[3][0] % mat[3][1] % mat[3][2] % mat[3][3]).str();
}

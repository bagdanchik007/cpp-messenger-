#pragma once

#include <string_view>

namespace cppmessenger::logging {

enum class Level {
    debug,
    info,
    warning,
    error
};

void log(Level level, std::string_view message);

void debug(std::string_view message);
void info(std::string_view message);
void warning(std::string_view message);
void error(std::string_view message);

}

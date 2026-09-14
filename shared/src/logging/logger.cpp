#include <cppmessenger/logging/logger.hpp>

#include <iostream>

namespace cppmessenger::logging {

void log(Level level, std::string_view message)
{
    switch (level) {
    case Level::debug:
        std::clog << "[DEBUG] ";
        break;
    case Level::info:
        std::clog << "[INFO] ";
        break;
    case Level::warning:
        std::clog << "[WARNING] ";
        break;
    case Level::error:
        std::clog << "[ERROR] ";
        break;
    }

    std::clog << message << '\n';
}

void debug(std::string_view message)
{
    log(Level::debug, message);
}

void info(std::string_view message)
{
    log(Level::info, message);
}

void warning(std::string_view message)
{
    log(Level::warning, message);
}

void error(std::string_view message)
{
    log(Level::error, message);
}

}

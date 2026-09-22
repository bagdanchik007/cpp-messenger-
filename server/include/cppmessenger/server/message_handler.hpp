#pragma once 

#include <functional>
#include <string>

namespace cppmessenger::server {
    using MessageHandler = std::function<std::string(const std::string&)>;
} // namespace cppmessenger::server

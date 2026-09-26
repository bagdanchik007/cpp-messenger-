#pragma once

#include <functional>
#include <string>

namespace cppmessenger::client {

using MessageHandler = std::function<void(const std::string &)>;

} // namespace cppmessenger::client
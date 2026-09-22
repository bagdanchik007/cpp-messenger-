#pragma once

#include <functional>
#include <string>
#include <unordered_map>

namespace cppmessenger::server {

class MessageDispatcher {
public:
    using Handler = std::function<std::string(const std::string&)>;

    void register_handler(
        std::string message_type,
        Handler handler);

private:
    std::unordered_map<std::string, Handler> handlers_;
};

} // namespace cppmessenger::server
#pragma once

#include <string>
#include <unordered_map>

#include <cppmessenger/server/message_handler.hpp>

namespace cppmessenger::server {

class MessageDispatcher {
public:
    using Handler = MessageHandler;

    void register_handler(
        std::string message_type,
        Handler handler);

    [[nodiscard]] bool has_handler(
        const std::string& message_type) const noexcept;

private:
    std::unordered_map<std::string, Handler> handlers_;
};

} // namespace cppmessenger::server
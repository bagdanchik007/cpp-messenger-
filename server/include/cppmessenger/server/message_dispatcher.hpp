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

    [[nodiscard]] std::string dispatch(
        const std::string& message_type,
        const std::string& payload) const;

private:
    std::unordered_map<std::string, Handler> handlers_;
};

} // namespace cppmessenger::server
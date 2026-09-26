#include <cppmessenger/server/message_dispatcher.hpp>

#include <stdexcept>
#include <utility>

namespace cppmessenger::server {

void MessageDispatcher::register_handler(
    std::string message_type,
    Handler handler)
{
    if (message_type.empty()) {
        throw std::invalid_argument(
            "Message type must not be empty");
    }

    if (!handler) {
        throw std::invalid_argument(
            "Message handler must be valid");
    }

    handlers_[std::move(message_type)] = std::move(handler);
}

bool MessageDispatcher::has_handler(
    const std::string& message_type) const noexcept
{
    return handlers_.contains(message_type);
}
std::string MessageDispatcher::dispatch(
    const std::string& message_type,
    const std::string& payload) const
{
    const auto it = handlers_.find(message_type);

    if (it == handlers_.end()) {
        throw std::invalid_argument(
            "No message handler registered for message type");
    }

    return it->second(payload);
}

} // namespace cppmessenger::server
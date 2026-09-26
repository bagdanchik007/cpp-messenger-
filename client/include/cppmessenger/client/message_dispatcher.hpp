#pragma once

#include <cppmessenger/client/message_handler.hpp>
#include <string>
#include <unordered_map>

namespace cppmessenger::client {

class MessageDispatcher {
  public:
    using Handler = MessageHandler;

    void register_handler(std::string message_type, Handler handler);

    [[nodiscard]] bool has_handler(const std::string &message_type) const noexcept;

  private:
    std::unordered_map<std::string, Handler> handlers_;
};

} // namespace cppmessenger::client
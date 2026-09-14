#pragma once

#include <cstdint>

#include <cppmessenger/types/types.hpp>

namespace cppmessenger::protocol {

enum class MessageKind : std::uint8_t {
    authenticate,
    authentication_result,
    send_message,
    message_received,
    error
};

struct RequestHeader {
    MessageKind kind{};
    std::uint32_t payload_size{};
};

struct ResponseHeader {
    MessageKind kind{};
    std::uint32_t payload_size{};
};

struct SendMessageRequest {
    types::ChatId chat_id{};
    types::UserId sender_id{};
};

}

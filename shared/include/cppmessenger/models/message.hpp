#pragma once

#include <string>

#include <cppmessenger/types/types.hpp>

namespace cppmessenger::models {

enum class MessageType {
    text,
    media,
    system
};

struct Message {
    types::MessageId id{};
    types::ChatId chat_id{};
    types::UserId sender_id{};
    MessageType type = MessageType::text;
    std::string content;
    types::Timestamp created_at{};
};

}

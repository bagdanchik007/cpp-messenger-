#pragma once

#include <string>

#include <cppmessenger/types/types.hpp>

namespace cppmessenger::models {

enum class ChatType {
    direct,
    group
};

struct Chat {
    types::ChatId id{};
    ChatType type = ChatType::direct;
    std::string title;
    types::UserId owner_id{};
};

}

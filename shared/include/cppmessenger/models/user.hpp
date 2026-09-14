#pragma once

#include <string>

#include <cppmessenger/types/types.hpp>

namespace cppmessenger::models {

struct User {
    types::UserId id{};
    std::string username;
    std::string display_name;
    bool online = false;
};

}

#pragma once

#include <cstdint>
#include <string>

namespace cppmessenger::config {

struct AppConfig {
    std::string application_name = "cpp-messenger";
    std::string version = "0.1.0";
    std::uint16_t server_port = 8080;
    bool development_mode = true;
};

[[nodiscard]] AppConfig default_config();

}

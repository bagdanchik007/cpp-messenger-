#pragma once 

#include <string>

#include "cppmessenger/result/result.hpp"

namespace cppmessenger::protocol {
    [[nodiscard]] Result<std::string> decode_packet(
        const std::string& encoded);
} // namespace cppmessenger::protocol
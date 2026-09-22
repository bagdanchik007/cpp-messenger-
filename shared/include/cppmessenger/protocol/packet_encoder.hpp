#pragma once 

#include <string>

#include "cppmessenger/result/result.hpp"

namespace cppmessenger::protocol {

    [[nodiscard]] Result <std::string> encode_packet(
        const std::string& payload);
    } //namespace cppmessenger::protocol

    
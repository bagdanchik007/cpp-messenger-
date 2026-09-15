#pragma once

#include <cstdint>
#include <string>

#include <cppmessenger/result/result.hpp>

namespace cppmessenger::protocol {

struct Packet {
    std::uint32_t payload_size{};
    std::string payload;
};

[[nodiscard]] Result<Packet> frame_packet(const std::string& payload);

[[nodiscard]] Result<std::string> extract_payload(const Packet& packet);

} // namespace cppmessenger::protocol
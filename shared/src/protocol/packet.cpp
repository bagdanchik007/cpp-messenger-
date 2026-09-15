#include <cppmessenger/protocol/packet.hpp>

#include <limits>
#include <utility>

namespace cppmessenger::protocol {

Result<Packet> frame_packet(const std::string& payload)
{
    if (payload.size() > std::numeric_limits<std::uint32_t>::max()) {
        return Result<Packet>::failure(
            errors::Error{
                errors::ErrorCode::serialization_error,
                "Packet payload is too large"
            }
        );
    }

    Packet packet;
    packet.payload_size = static_cast<std::uint32_t>(payload.size());
    packet.payload = payload;

    return Result<Packet>::success(std::move(packet));
}

Result<std::string> extract_payload(const Packet& packet)
{
    if (packet.payload.size() != packet.payload_size) {
        return Result<std::string>::failure(
            errors::Error{
                errors::ErrorCode::serialization_error,
                "Packet payload size does not match header"
            }
        );
    }

    return Result<std::string>::success(packet.payload);
}

} // namespace cppmessenger::protocol
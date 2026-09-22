#include <cppmessenger/protocol/packet_encoder.hpp>

#include <cstdint>
#include <limits>
#include <utility>

namespace cppmessenger::protocol {

Result<std::string> encode_packet(const std::string& payload)
{
    if (payload.size() > std::numeric_limits<std::uint32_t>::max()) {
        return Result<std::string>::failure(
            errors::Error{
                errors::ErrorCode::serialization_error,
                "Packet payload is too large"
            }
        );
    }

    const auto size = static_cast<std::uint32_t>(payload.size());

    std::string encoded;
    encoded.resize(sizeof(size) + payload.size());

    encoded[0] = static_cast<char>((size >> 24U) & 0xFFU);
    encoded[1] = static_cast<char>((size >> 16U) & 0xFFU);
    encoded[2] = static_cast<char>((size >> 8U) & 0xFFU);
    encoded[3] = static_cast<char>(size & 0xFFU);

    encoded.replace(sizeof(size), payload.size(), payload);

    return Result<std::string>::success(std::move(encoded));
}

} // namespace cppmessenger::protocol
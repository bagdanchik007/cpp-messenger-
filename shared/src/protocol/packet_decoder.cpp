#include <cppmessenger/protocol/packet_decoder.hpp>

#include <cstdint>

namespace cppmessenger::protocol {

Result<std::string> decode_packet(const std::string& encoded)
{
    constexpr std::size_t header_size = sizeof(std::uint32_t);

    if (encoded.size() < header_size) {
        return Result<std::string>::failure(
            errors::Error{
                errors::ErrorCode::serialization_error,
                "Encoded packet is smaller than the packet header"
            }
        );
    }

    const auto size =
        (static_cast<std::uint32_t>(
             static_cast<unsigned char>(encoded[0]))
         << 24U)
        |
        (static_cast<std::uint32_t>(
             static_cast<unsigned char>(encoded[1]))
         << 16U)
        |
        (static_cast<std::uint32_t>(
             static_cast<unsigned char>(encoded[2]))
         << 8U)
        |
        static_cast<std::uint32_t>(
            static_cast<unsigned char>(encoded[3]));

    if (encoded.size() != header_size + size) {
        return Result<std::string>::failure(
            errors::Error{
                errors::ErrorCode::serialization_error,
                "Encoded packet size does not match header"
            }
        );
    }

    return Result<std::string>::success(
        encoded.substr(header_size));
}

} // namespace cppmessenger::protocol

#include <cassert>
#include <cstdint>
#include <string>

#include <cppmessenger/protocol/packet_encoder.hpp>

int main()
{
    const std::string payload = "hello";

    const auto result =
        cppmessenger::protocol::encode_packet(payload);

    assert(result.has_value());

    const std::string encoded = result.value();

    assert(encoded.size() == 9);

    assert(static_cast<std::uint8_t>(encoded[0]) == 0);
    assert(static_cast<std::uint8_t>(encoded[1]) == 0);
    assert(static_cast<std::uint8_t>(encoded[2]) == 0);
    assert(static_cast<std::uint8_t>(encoded[3]) == 5);

    assert(encoded.substr(4) == "hello");

    return 0;
}
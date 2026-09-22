#include <cassert>
#include <string>

#include <cppmessenger/protocol/packet.hpp>

int main()
{
    const std::string payload = "hello";

    const auto result =
        cppmessenger ::protocol::frame_packet(payload);

    assert(result.has_value());

    const auto& packet = result.value();

    assert(packet.payload_size == 5);
    assert(packet.payload == "hello");

    return 0;
}

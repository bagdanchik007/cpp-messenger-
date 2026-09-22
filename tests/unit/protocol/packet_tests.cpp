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
    
    const cppmessenger::protocol::Packet packet{
        5, "hello"
    };

    const auto extract_result =
        cppmessenger::protocol::extract_payload(packet);
    assert(extract_result.has_value());
    assert(extract_result.value() == "hello");  
    
    return 0;
}

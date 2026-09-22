#include <cassert>
#include <string>

#include <cppmessenger/protocol/packet.hpp>
#include <cppmessenger/protocol/packet_decoder.hpp>
#include <cppmessenger/protocol/packet_encoder.hpp>

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
    const std::string original_payload =
        "Hello from cpp-messenger";
    const auto encode_result =
        cppmessenger::protocol::encode_packet(original_payload);
    assert(encode_result.has_value());

    const auto decoded_result =
        cppmessenger::protocol::decode_packet(
            encode_result.value());
    assert(decoded_result.has_value());
    assert(decoded_result.value() == original_payload);
    return 0;
}

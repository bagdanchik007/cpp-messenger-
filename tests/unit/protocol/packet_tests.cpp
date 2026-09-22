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

    const cppmessenger::protocol::Packet invalid_packet{
        10, "hello"
    };
    const auto invalid_extract_result =
        cppmessenger::protocol::extract_payload(invalid_packet);
    
    assert(!invalid_extract_result.has_value());
    const std::string invalid_encodeed_packet{
        '\0',
        '\0',
        '\0',
        '\x06',
        'h',
        'e',
        'l',
        'l',
        'o'
    };  

    const auto invalid_decode_result =
        cppmessenger::protocol::decode_packet(
            invalid_encodeed_packet);
    assert(!invalid_decode_result.has_value());
    
    return 0;
}

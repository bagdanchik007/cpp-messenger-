#include <cassert>
#include <cstdint>
#include <string>

#include <cppmessenger/protocol/packet_decoder.hpp>

int main()
{
    using cppmessenger::errors::ErrorCode;

    const std::string encoded{
        '\0',
        '\0',
        '\0',
        '\x05',
        'h',
        'e',
        'l',
        'l',
        'o'
    };

    const auto result =
        cppmessenger::protocol::decode_packet(encoded);

    assert(result.has_value());
    assert(result.value() == "hello");

    const std::string incomplete_header{
        '\0',
        '\0',
        '\0'
    };

    const auto incomplete_result =
        cppmessenger::protocol::decode_packet(incomplete_header);

    assert(!incomplete_result.has_value());
    assert(
        incomplete_result.error().code()
        == ErrorCode::serialization_error
    );

    const std::string mismatched_packet{
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

    const auto mismatched_result =
        cppmessenger::protocol::decode_packet(mismatched_packet);

    assert(!mismatched_result.has_value());
    assert(
        mismatched_result.error().code()
        == ErrorCode::serialization_error
    );

    const std::string empty_payload{
        '\0',
        '\0',
        '\0',
        '\0'
    };

    const auto empty_result =
        cppmessenger::protocol::decode_packet(empty_payload);

    assert(empty_result.has_value());
    assert(empty_result.value().empty());

    return 0;
}
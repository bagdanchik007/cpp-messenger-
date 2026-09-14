#pragma once

#include <chrono>
#include <cstdint>

namespace cppmessenger::types {

using UserId = std::uint64_t;
using ChatId = std::uint64_t;
using MessageId = std::uint64_t;

using Timestamp = std::chrono::system_clock::time_point;

}

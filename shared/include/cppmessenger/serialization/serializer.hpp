#pragma once

#include <string>
#include <string_view>

#include <cppmessenger/result/result.hpp>

namespace cppmessenger::serialization {

[[nodiscard]] Result<std::string> serialize(std::string_view value);

[[nodiscard]] Result<std::string> deserialize(std::string_view value);

}

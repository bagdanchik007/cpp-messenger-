#include <cppmessenger/serialization/serializer.hpp>

namespace cppmessenger::serialization {

Result<std::string> serialize(std::string_view value)
{
    return Result<std::string>::success(std::string(value));
}

Result<std::string> deserialize(std::string_view value)
{
    return Result<std::string>::success(std::string(value));
}

}

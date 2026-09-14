#pragma once

#include <string>
#include <string_view>

namespace cppmessenger::errors {

enum class ErrorCode {
    unknown,
    invalid_argument,
    not_found,
    unauthorized,
    forbidden,
    network_error,
    serialization_error,
    internal_error
};

class Error {
public:
    Error(ErrorCode code, std::string message)
        : code_(code), message_(std::move(message)) {}

    [[nodiscard]] ErrorCode code() const noexcept
    {
        return code_;
    }

    [[nodiscard]] std::string_view message() const noexcept
    {
        return message_;
    }

private:
    ErrorCode code_;
    std::string message_;
};

}

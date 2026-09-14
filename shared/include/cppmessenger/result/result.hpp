#pragma once

#include <stdexcept>
#include <utility>
#include <variant>

#include <cppmessenger/errors/error.hpp>

namespace cppmessenger {

template <typename T>
class Result {
public:
    static Result success(T value)
    {
        return Result(std::move(value));
    }

    static Result failure(errors::Error error)
    {
        return Result(std::move(error));
    }

    [[nodiscard]] bool has_value() const noexcept
    {
        return std::holds_alternative<T>(storage_);
    }

    [[nodiscard]] explicit operator bool() const noexcept
    {
        return has_value();
    }

    [[nodiscard]] T& value()
    {
        if (!has_value()) {
            throw std::logic_error("Result does not contain a value");
        }
        return std::get<T>(storage_);
    }

    [[nodiscard]] const T& value() const
    {
        if (!has_value()) {
            throw std::logic_error("Result does not contain a value");
        }
        return std::get<T>(storage_);
    }

    [[nodiscard]] const errors::Error& error() const
    {
        if (has_value()) {
            throw std::logic_error("Result contains a value");
        }
        return std::get<errors::Error>(storage_);
    }

private:
    explicit Result(T value)
        : storage_(std::move(value)) {}

    explicit Result(errors::Error error)
        : storage_(std::move(error)) {}

    std::variant<T, errors::Error> storage_;
};

}

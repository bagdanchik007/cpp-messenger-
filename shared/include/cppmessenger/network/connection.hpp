#pragma once

#include <cstdint>
#include <string>

#include <cppmessenger/network/connection_state.hpp>

namespace cppmessenger::network {

struct Endpoint {
    std::string host;
    std::uint16_t port{};
};

class Connection {
public:
    virtual ~Connection() = default;

    virtual bool connect(const Endpoint& endpoint) = 0;
    virtual void disconnect() noexcept = 0;

    [[nodiscard]] virtual bool is_connected() const noexcept = 0;
    [[nodiscard]] virtual ConnectionState state() const noexcept = 0;
};

} // namespace cppmessenger::network
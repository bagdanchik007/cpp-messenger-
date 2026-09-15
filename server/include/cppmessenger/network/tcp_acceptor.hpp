#pragma once

#include <cstdint>
#include <functional>
#include <memory>

namespace cppmessenger::network {

class TcpAcceptor {
public:
    using AcceptHandler = std::function<void()>;

    TcpAcceptor(std::uint16_t port);
    ~TcpAcceptor();

    TcpAcceptor(const TcpAcceptor&) = delete;
    TcpAcceptor& operator=(const TcpAcceptor&) = delete;

    TcpAcceptor(TcpAcceptor&&) noexcept;
    TcpAcceptor& operator=(TcpAcceptor&&) noexcept;

    void start();
    void stop();

    [[nodiscard]] bool is_running() const noexcept;

private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace cppmessenger::network
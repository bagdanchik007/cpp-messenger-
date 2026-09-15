#pragma once

#include <memory>

#include <cppmessenger/network/connection.hpp>

namespace cppmessenger::network {

class TcpClient final : public Connection {
public:
    TcpClient();
    ~TcpClient() override;

    TcpClient(const TcpClient&) = delete;
    TcpClient& operator=(const TcpClient&) = delete;

    TcpClient(TcpClient&&) noexcept;
    TcpClient& operator=(TcpClient&&) noexcept;

    bool connect(const Endpoint& endpoint) override;
    void disconnect() noexcept override;

    [[nodiscard]] bool is_connected() const noexcept override;
    [[nodiscard]] ConnectionState state() const noexcept override;
    [[nodiscard]] const Endpoint& endpoint() const noexcept;

private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace cppmessenger::network
#pragma once

#include <cstdint>
#include <memory>

namespace cppmessenger::network {

class TcpServer {
    public:
        TcpServer(std::uint16_t port);
        ~TcpServer();

        TcpServer(const TcpServer &) = delete;
        TcpServer &operator=(const TcpServer &) = delete;

        TcpServer(TcpServer &&) noexcept;
        TcpServer &operator=(TcpServer &&) noexcept;

        void start();
        void stop() noexcept;

        [[nodiscard]] bool is_running() const noexcept;

    private:
        class Impl;
        std::unique_ptr<Impl> impl_;
};
} // namespace cppmessenger::network

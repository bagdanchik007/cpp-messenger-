#include <cppmessenger/network/tcp_server.hpp>

#include <stdexcept>
#include <utility>

namespace cppmessenger::network {

class TcpServer::Impl {
public:
    explicit Impl(std::uint16_t port)
        : port_(port)
    {
    }

    void start()
    {
        if (running_) {
            return;
        }

        if (port_ == 0) {
            throw std::invalid_argument("TCP server port must not be zero");
        }

        running_ = true;
    }

    void stop() noexcept
    {
        running_ = false;
    }

    [[nodiscard]] bool is_running() const noexcept
    {
        return running_;
    }

private:
    std::uint16_t port_;
    bool running_ = false;
};

TcpServer::TcpServer(std::uint16_t port)
    : impl_(std::make_unique<Impl>(port))
{
}

TcpServer::~TcpServer() = default;

TcpServer::TcpServer(TcpServer&&) noexcept = default;

TcpServer& TcpServer::operator=(TcpServer&&) noexcept = default;

void TcpServer::start()
{
    impl_->start();
}

void TcpServer::stop()
{
    impl_->stop();
}

bool TcpServer::is_running() const noexcept
{
    return impl_->is_running();
}

} // namespace cppmessenger::network
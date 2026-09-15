#include <cppmessenger/network/tcp_client.hpp>

#include <memory>
#include <utility>

namespace cppmessenger::network {

class TcpClient::Impl {
public:
    bool connect(const Endpoint& endpoint)
    {
        if (state_ != ConnectionState::disconnected) {
            return false;
        }

        state_ = ConnectionState::connecting;

        if (endpoint.host.empty() || endpoint.port == 0) {
            state_ = ConnectionState::disconnected;
            endpoint_ = {};
            return false;
        }

        endpoint_ = endpoint;
        state_ = ConnectionState::connected;

        return true;
    }

    void disconnect() noexcept
    {
        if (state_ == ConnectionState::disconnected) {
            return;
        }

        state_ = ConnectionState::disconnecting;
        state_ = ConnectionState::disconnected;
    }

    [[nodiscard]] bool is_connected() const noexcept
    {
        return state_ == ConnectionState::connected;
    }

    [[nodiscard]] ConnectionState state() const noexcept
    {
        return state_;
    }

    [[nodiscard]] const Endpoint& endpoint() const noexcept
    {
        return endpoint_;
    }

private:
    Endpoint endpoint_;
    ConnectionState state_ = ConnectionState::disconnected;
};

TcpClient::TcpClient()
    : impl_(std::make_unique<Impl>())
{
}

TcpClient::~TcpClient() = default;

TcpClient::TcpClient(TcpClient&&) noexcept = default;

TcpClient& TcpClient::operator=(TcpClient&&) noexcept = default;

bool TcpClient::connect(const Endpoint& endpoint)
{
    return impl_->connect(endpoint);
}

void TcpClient::disconnect() noexcept
{
    impl_->disconnect();
}

bool TcpClient::is_connected() const noexcept
{
    return impl_->is_connected();
}

ConnectionState TcpClient::state() const noexcept
{
    return impl_->state();
}

const Endpoint& TcpClient::endpoint() const noexcept
{
    return impl_->endpoint();
}

} // namespace cppmessenger::network
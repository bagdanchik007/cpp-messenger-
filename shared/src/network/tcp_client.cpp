#include <cppmessenger/network/tcp_client.hpp>

#include <memory>

namespace cppmessenger::network {

class TcpClient::Impl {
public:
    bool connect(const Endpoint& endpoint)
    {
        if (endpoint.host.empty() || endpoint.port == 0) {
            return false;
        }

        connected_ = true;
        return true;
    }

    void disconnect() noexcept
    {
        connected_ = false;
    }

    [[nodiscard]] bool is_connected() const noexcept
    {
        return connected_;
    }

private:
    bool connected_ = false;
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

} // namespace cppmessenger::network
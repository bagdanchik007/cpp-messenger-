#include <cppmessenger/network/tcp_acceptor.hpp>
#include <memory>
#include <stdexcept>
#include <utility>

namespace cppmessenger::network {

class TcpAcceptor::Impl {
  public:
    explicit Impl(std::uint16_t port) : port_(port) {}

    void start() {
        if (running_) {
            return;
        }

        if (port_ == 0) {
            throw std::invalid_argument("TCP acceptor port must not be zero");
        }

        running_ = true;
    }

    void stop() noexcept { running_ = false; }

    [[nodiscard]] bool is_running() const noexcept { return running_; }

  private:
    std::uint16_t port_;
    bool running_ = false;
};

TcpAcceptor::TcpAcceptor(std::uint16_t port) : impl_(std::make_unique<Impl>(port)) {}

TcpAcceptor::~TcpAcceptor() = default;

TcpAcceptor::TcpAcceptor(TcpAcceptor &&) noexcept = default;

TcpAcceptor &TcpAcceptor::operator=(TcpAcceptor &&) noexcept = default;

void TcpAcceptor::start() { impl_->start(); }

void TcpAcceptor::stop() { impl_->stop(); }

bool TcpAcceptor::is_running() const noexcept { return impl_->is_running(); }

} // namespace cppmessenger::network
#include <cppmessenger/network/connection.hpp>

namespace cppmessenger::network {

class StubConnection final : public Connection {
public:
    bool connect(const Endpoint&) override
    {
        connected_ = true;
        return true;
    }

    void disconnect() noexcept override
    {
        connected_ = false;
    }

    [[nodiscard]] bool is_connected() const noexcept override
    {
        return connected_;
    }

private:
    bool connected_ = false;
};

}

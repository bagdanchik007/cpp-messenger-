#include  <cassert>

#include <cppmessenger/network/tcp_client.hpp>

int main()
{
    using cppmessenger::network::Endpoint;
    using cppmessenger::network::TcpClient;

    TcpClient client;

    assert(!client.is_connected());

    const Endpoint endpoint{"127.0.0.1", 8080};
    
    const bool connected = client.connect(endpoint);

    assert(connected);
    assert(client.is_connected());
    assert(client.endpoint().host == "127.0.0.1");
    assert(client.endpoint().port == 8080);

    client.disconnect();

    assert(!client.is_connected());

    const Endpoint invalid_endpoint{"invalid_host", 8080};
    assert(!client.connect(invalid_endpoint));
    assert(!client.is_connected());
    
    return 0;
}

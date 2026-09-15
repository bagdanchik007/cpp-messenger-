#include <cassert>

#include <cppmessenger/network/tcp_server.hpp>

int main()
{
    cppmessenger::network::TcpServer server(8080);

    assert(!server.is_running());

    server.start();

    assert(server.is_running());

    server.stop();

    assert(!server.is_running());

    return 0;
}
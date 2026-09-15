#pragma once

namespace cppmessenger::network {

enum class ConnectionState {
    disconnected,
    connecting,
    connected,
    disconnecting
};

} // namespace cppmessenger::network

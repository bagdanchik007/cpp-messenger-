add_library(cppmessenger_shared
    src/shared.cpp
    src/logging/logger.cpp
    src/config/config.cpp
    src/serialization/serializer.cpp
    src/network/connection.cpp
    src/network/tcp_server.cpp
    src/network/tcp_client.cpp
    src/protocol/packet.cpp
    src/protocol/packet_encoder.cpp
    shared/src/protocol/packet_decoder.cpp
)

target_include_directories(cppmessenger_shared
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(cppmessenger_shared
    PUBLIC
        cxx_std_20
)

cppmessenger_enable_warnings(cppmessenger_shared)

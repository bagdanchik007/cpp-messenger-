add_executable(cppmessenger_server
    src/main.cpp
    src/network/tcp_acceptor.cpp
    src/message_dispatcher.cpp
)

target_include_directories(cppmessenger_server
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(cppmessenger_server
    PRIVATE
        cppmessenger_shared
)

target_compile_features(cppmessenger_server
    PRIVATE
        cxx_std_20
)

cppmessenger_enable_warnings(cppmessenger_server)
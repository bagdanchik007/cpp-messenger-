add_executable(cppmessenger_shared_tests
    unit/shared/shared_tests.cpp
)

target_link_libraries(cppmessenger_shared_tests
    PRIVATE
        cppmessenger_shared
)

target_compile_features(cppmessenger_shared_tests
    PRIVATE
        cxx_std_20
)

cppmessenger_enable_warnings(cppmessenger_shared_tests)

add_test(
    NAME cppmessenger_shared_tests
    COMMAND cppmessenger_shared_tests
)


add_executable(cppmessenger_tcp_server_tests
    unit/network/tcp_server_tests.cpp
)

target_link_libraries(cppmessenger_tcp_server_tests
    PRIVATE
        cppmessenger_shared
)

target_compile_features(cppmessenger_tcp_server_tests
    PRIVATE
        cxx_std_20
)

cppmessenger_enable_warnings(cppmessenger_tcp_server_tests)

add_test(
    NAME cppmessenger_tcp_server_tests
    COMMAND cppmessenger_tcp_server_tests
)


add_executable(cppmessenger_tcp_client_tests
    unit/network/tcp_client_tests.cpp
)

target_link_libraries(cppmessenger_tcp_client_tests
    PRIVATE
        cppmessenger_shared
)

target_compile_features(cppmessenger_tcp_client_tests
    PRIVATE
        cxx_std_20
)

cppmessenger_enable_warnings(cppmessenger_tcp_client_tests)

add_test(
    NAME cppmessenger_tcp_client_tests
    COMMAND cppmessenger_tcp_client_tests
)
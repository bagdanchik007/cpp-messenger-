add_executable(cppmessenger_client
    src/main.cpp
)

target_link_libraries(cppmessenger_client
    PRIVATE
        cppmessenger_shared
)

target_compile_features(cppmessenger_client
    PRIVATE
        cxx_std_20
)

cppmessenger_enable_warnings(cppmessenger_client)

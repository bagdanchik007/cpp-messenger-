add_executable(cppmessenger_server
    src/main.cpp
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

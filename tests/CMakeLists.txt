add_executable(cppmessenger_tests
    unit/shared/shared_tests.cpp
)

target_link_libraries(cppmessenger_tests
    PRIVATE
        cppmessenger_shared
)

target_compile_features(cppmessenger_tests
    PRIVATE
        cxx_std_20
)

enable_testing()

add_test(
    NAME cppmessenger_tests
    COMMAND cppmessenger_tests
)

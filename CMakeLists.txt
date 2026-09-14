cmake_minimum_required(VERSION 3.25)

project(CppMessenger
    VERSION 0.1.0
    DESCRIPTION "Modern C++ Messenger"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

add_subdirectory(shared)
add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(tests)

add_library(cppmessenger_shared
    src/shared.cpp
)

target_include_directories(cppmessenger_shared
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(cppmessenger_shared
    PUBLIC
        cxx_std_20
)

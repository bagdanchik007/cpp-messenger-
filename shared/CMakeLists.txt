add_library(cppmessenger_shared
    src/shared.cpp
    src/logging/logger.cpp
    src/config/config.cpp
    src/serialization/serializer.cpp
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

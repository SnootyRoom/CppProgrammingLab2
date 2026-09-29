cmake_minimum_required(VERSION 3.20)
project(CppProgrammingLab2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD  20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com
)

add_executable(CppProgrammingLab2 src/ip_filter.cpp src/ip_utils.cpp)

add_executable(ip_tests tests/ip_tests.cpp src/ip_utils.cpp)
target_link_libraries(ip_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(ip_tests)

option(ENABLE_ASAN "Enable Address Sanitizer" OFF)

if(ENABLE_ASAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
        message(STATUS "AddressSanitizer and UndefinedBehaviorSanitizer are enabled")
    endif()
endif()
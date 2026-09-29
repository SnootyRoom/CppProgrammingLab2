cmake_minimum_required(VERSION 3.20)
project(CppProgrammingLab2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD  20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(CppProgrammingLab2 src/ip_filter.cpp src/ip_utils.cpp)

add_executable(ip_tests tests/ip_tests.cpp src/ip_utils.cpp)
target_link_libraries(ip_tests PRIVATE GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ip_tests)

option(ENABLE_ASAN "Enable Address Sanitizer" OFF)

if(ENABLE_ASAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")

        target_compile_options(CppProgrammingLab2 PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(CppProgrammingLab2 PRIVATE -fsanitize=address,undefined)

        target_compile_options(ip_tests PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
        target_link_options(ip_tests PRIVATE -fsanitize=address,undefined)
    endif()
endif()
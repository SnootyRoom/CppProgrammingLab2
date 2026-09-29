cmake_minimum_required(VERSION 3.20)
project(CppProgrammingLab2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD  20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(ip_filter ip_filter.cpp)



option(ENABLE_ASAN "Enable Address Sanitizer" OFF)

if(ENABLE_ASAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
        message(STATUS "AddressSanitizer and UndefinedBehaviorSanitizer are enabled")
    endif()
endif()
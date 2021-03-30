cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(langdetectpp
        VERSION 0.0.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

option(LANGDETECTPP_BUILD_TESTS "Build tests" OFF)
option(LANGDETECTPP_BUILD_EXAMPLE "Build tests" OFF)

add_subdirectory(langdetectpp)

if(LANGDETECTPP_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(LANGDETECTPP_BUILD_EXAMPLE)
    add_subdirectory(example)
endif()

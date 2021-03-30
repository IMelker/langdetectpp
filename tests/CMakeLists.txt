cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(tests VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} functional_tests.cpp)

include_directories(../langdetectpp/include)
target_link_libraries(${PROJECT_NAME} PRIVATE
        langdetectpp stdc++fs
)

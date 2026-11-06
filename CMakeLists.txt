cmake_minimum_required(VERSION 3.16)
project(dashboard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dash
    src/main.cpp
    src/memory.cpp
    src/memory.hpp
)

target_compile_options(dash PRIVATE -Wall -Wextra)

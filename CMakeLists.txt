cmake_minimum_required(VERSION 3.16)
project(dashboard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v7.0.3)
FetchContent_MakeAvailable(ftxui)

add_executable(dash
    src/main.cpp
    src/memory.cpp
    src/memory.hpp
    src/cpu.cpp
    src/cpu.hpp
)

target_link_libraries(dash PRIVATE ftxui::screen ftxui::dom ftxui::component)
target_compile_options(dash PRIVATE -Wall -Wextra)
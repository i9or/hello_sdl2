cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

project(hello_sdl2)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2main SDL2::SDL2)

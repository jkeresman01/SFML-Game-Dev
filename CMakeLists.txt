cmake_minimum_required(VERSION 3.10)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(src/headers)

set(SOURCE_FILES
    src/Main.cpp
    # src/Snake.cpp
    # src/ResourceManager.cpp
)

add_executable(snake ${SOURCE_FILES})

target_link_libraries(snake sfml-graphics sfml-window sfml-system sfml-audio)

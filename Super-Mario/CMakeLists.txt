cmake_minimum_required(VERSION 3.10)
project(SuperMario)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(src/headers)

set(SOURCE_FILES
    src/Main.cpp
    src/Mario.cpp
    src/Goomba.cpp
    src/Animation.cpp
    src/ResourceManager.cpp
)

add_executable(super-mario ${SOURCE_FILES})

target_link_libraries(super-mario sfml-graphics sfml-window sfml-system sfml-audio)

add_custom_command(TARGET super-mario POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:super-mario>/resources
)

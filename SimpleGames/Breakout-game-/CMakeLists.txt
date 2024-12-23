cmake_minimum_required(VERSION 3.10)
project(ConwaysGameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(src/headers)

set(SOURCE_FILES
    src/Main.cpp
    src/Ball.cpp
    src/Background.cpp
    src/ResourceManager.cpp
    src/Brick.cpp
    src/BreakoutGame.cpp
    src/Paddle.cpp
)

add_executable(breakout-game ${SOURCE_FILES})

target_link_libraries(breakout-game sfml-graphics sfml-window sfml-system sfml-audio)

add_custom_command(TARGET breakout-game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:breakout-game>/resources
)

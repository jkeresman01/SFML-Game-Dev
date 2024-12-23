cmake_minimum_required(VERSION 3.10)
project(BreakoutGameTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

include_directories(../src/headers)

set(SOURCE_FILES
    ../src/Ball.cpp
    ../src/Brick.cpp
    ../src/Paddle.cpp
    ../src/ResourceManager.cpp
)

set(TEST_FILES
    PaddleTest.cpp
)

add_executable(run-tests ${SOURCE_FILES} ${TEST_FILES})

target_link_libraries(run-tests ${GTEST_LIBRARIES} pthread sfml-graphics sfml-window sfml-system sfml-audio)

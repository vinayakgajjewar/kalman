cmake_minimum_required(VERSION 3.27)
project(kalman)
set(CMAKE_CXX_STANDARD 20)
add_executable(test_kalman
        tests/test_kalman.cpp
        src/kalman.cpp
)
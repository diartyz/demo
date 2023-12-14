cmake_minimum_required(VERSION 3.16)

project(demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

SET(SRC_LIST demo.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

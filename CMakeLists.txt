cmake_minimum_required(VERSION 3.16)

project(demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# SET(SRC_LIST demo.cpp database.cpp employee.cpp)
SET(SRC_LIST main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

# enable pthread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads)

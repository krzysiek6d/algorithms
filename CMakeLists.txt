project(algorithms)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")# -Wall -Werror")

find_package(Threads)

add_subdirectory(3rdparty)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)

enable_testing()
add_subdirectory(test EXCLUDE_FROM_ALL)

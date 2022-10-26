cmake_minimum_required (VERSION 3.16.2)
SET(CMAKE_CXX_STANDARD 17)
project (Conways CXX)

include_directories(includes)
file(GLOB SOURCES "src/*.cpp")
add_executable(run ${SOURCES})
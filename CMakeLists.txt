cmake_minimum_required(VERSION 3.27)
project(Desktop C)

set(CMAKE_C_STANDARD 11)

# Add all source files in the current directory to the executable
file(GLOB SOURCES "*.c" "*.h")

add_executable(Desktop ${SOURCES})
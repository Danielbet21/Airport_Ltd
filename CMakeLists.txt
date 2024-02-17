cmake_minimum_required(VERSION 3.27)
project(Desktop C)

set(CMAKE_C_STANDARD 11)

add_executable(Desktop main.c
        flight.c
        flight.h
        plane.h
        plane.c
        airport.c
        airport.h
        generalStrings.h
        generalStrings.c
        date.c
        date.h
        airline.c
        airline.h
        exe.h
        exe.c)

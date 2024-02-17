cmake_minimum_required(VERSION 3.27)
project(Desktop C)

set(CMAKE_C_STANDARD 11)

add_executable(Desktop main.c
        flight.c
        flight.h
        plane.h
        plane.c
        date.c
        date.h
        generalStrings.c
        generalStrings.h
        airport.c
        airport.h
        airline.c
        airline.h)

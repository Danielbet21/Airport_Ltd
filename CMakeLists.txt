cmake_minimum_required(VERSION 3.27)
project(Desktop C)

set(CMAKE_C_STANDARD 11)

add_executable(Desktop main.c
        Flight.c
        Flight.h
        Plane.h
        Plane.c
        date.c
        date.h
        generalStrings.c
        generalStrings.h
        airport.c
        airport.h
        Airline.c
        Airline.h
        exe.h
        exe.c
        Airportmanager.c
        Airportmanager.h)


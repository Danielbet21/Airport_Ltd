#ifndef FLIGHT_H
#define FLIGHT_H

#include "plane.h"
#include "date.h"

typedef struct {
    char *airport_c_sour;
    char *airport_c_Tar;
    Plane plane;
    Date date;
} Flight;

Flight initFlight();

int isFlightFromSourceAirport(Flight *flight, const char* airport_code);

int isFlightToDestAirport(const Flight *flight, const char* airport_code_des);

int isPlanTypeInFlight(Flight *flight, Plane *plane);

//void printFlight(PlaneType type,Airline airline,int length);

#endif //FLIGHT_H

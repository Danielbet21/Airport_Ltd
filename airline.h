#ifndef __AIRLINE__
#define __AIRLINE__

#include "flight.h"
#include "plane.h"
#include "generalStrings.h"
// airline struct
typedef struct {
    char *companyName;
    int numOfFlights;
    Flight **flightArr;
    int numOfAirPlanes;
    Plane *airPlanesArr;
} Airline;


// functions
int initAirline(Airline *pAirline);
void printAirline(const Airline *pAirline);
void freeAirline(Airline *pAirline);
int addFlight(Airline *pAirline, Flight *pFlight);
int addPlane(Airline *pAirline, Plane *pPlane);
void doPrintFlightsWithPlaneType(const Airline *pAirline);









#endif

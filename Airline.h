#ifndef __AIRLINE__
#define __AIRLINE__

#include "Flight.h"
#include "Plane.h"
#include "generalStrings.h"
// airline struct
typedef struct {
    char *name;
    int numOfFlights;
    Flight **flightArr;
    int planeCount;
    Plane *planeArr;
} Airline;

// functions
int initAirline(Airline *pAirline);
void printAirline(const Airline *pAirline);
void freeCompany(Airline *pAirline);
void printFlightsArr(const Airline *pAirline);
int addFlight(Airline *pAirline, Flight *pFlight);
int addPlane(Airline *pAirline);
void doPrintFlightsWithPlaneType(const Airline *pAirline);









#endif

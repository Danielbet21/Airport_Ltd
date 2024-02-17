#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include "Plane.h"
#include "date.h"
#include "airportManager.h"
#include "generalStrings.h"

typedef struct {
    char *airport_c_sour;
    char *airport_c_Tar;
    Plane *plane;
    Date date;
} Flight;


int initFlight(Flight *pFlight, const AirportManager *pManager,Plane *pPlane);
int isFlightFromSourceAirport(const Flight *flight, const char* airport_code);
int isFlightToDestAirport(const Flight *flight, const char* airport_code_des);
int isPlaneTypeInFlight(const Flight *flight, PlaneType planeType);
void freeFlight(Flight *pFlight);
void printFlight(const Flight *pFlight);
char *chooseAirport(Flight *pFlight, const AirportManager *pManager,  int isSource);


#endif
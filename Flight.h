#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include "Plane.h"
#include "Date.h"
#include "AirportManager.h"
#include "generalStrings.h"
#include "Airport.h"

#define CODE_LENGTH 3

typedef struct {
    char airport_c_sour[CODE_LENGTH +1];
    char airport_c_Tar[CODE_LENGTH +1];
    Plane *plane;
    Date date;
} Flight;


int initFlight(Flight *pFlight,Plane *pPlane, const AirportManager *pManager);
int isFlightFromSourceAirport(const Flight *flight, const char* airport_code);
int isFlightToDestAirport(const Flight *flight, const char* airport_code_des);
int isPlaneTypeInFlight(const Flight *flight, PlaneType planeType);
void freeFlight(Flight *pFlight);
void printFlight(const Flight *pFlight);
void chooseAirport(Flight *pFlight, const AirportManager *pManager);


#endif
#ifndef __MANAGER__
#define __MANAGER__
#include "Airport.h"

typedef struct {
    int airportLength;
    Airport **airportList;

} AirportManager;


int initManager(AirportManager *manager);

int addAirport(AirportManager *manager);

void printAirports(const AirportManager *manager);

Airport *findAirportByCode(AirportManager *manager, char *code);

void freeManager(AirportManager *manager);

int codeExist(const AirportManager *pManager, char *airportCode);



#endif
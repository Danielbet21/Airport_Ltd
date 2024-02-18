#include "airport.h"

typedef struct {
    int airportLength;
    Airport **airportList;

} AirportManager;


int initManager(AirportManager *manager);

int addAirport(AirportManager *manager);

void printAirports(AirportManager *manager);

Airport *findAirportByCode(AirportManager *manager, char *code);

void freeManager(AirportManager *manager);

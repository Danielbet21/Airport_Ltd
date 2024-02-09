#include "airport.h"

typedef struct {
    int airportLength;
    Airport **airportList;

} AirportManager;


AirportManager initAirportManager();

void addAirport(AirportManager *manager);

void printAllAirports(AirportManager *manager);

Airport *findAirportByCode(AirportManager *manager, char *code);
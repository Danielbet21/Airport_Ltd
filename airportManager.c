#include "stdio.h"
#include "string.h"
#include "airportManager.h"
#include "airport.h"
#include "stdlib.h"

int initManager(AirportManager *manager) {
    manager->airportLength = 0;
    manager->airportList = NULL;
    return 1;
}

int addAirport(AirportManager *manager) {
    Airport *tempAirport = (Airport *) malloc(sizeof(Airport));
    if (!tempAirport) {
        free(tempAirport);
        return 0;
    }
    initAirport(tempAirport);
    manager->airportList = (Airport **) realloc(manager->airportList,
                                                (sizeof(Airport *)) * (manager->airportLength + 1));

    if (manager->airportList) {
        freeAirport(tempAirport);
        free(manager->airportList);
        return 0;
    }
    manager->airportList[manager->airportLength] = tempAirport;
    manager->airportLength++;
    return 1;
}


Airport *findAirportByCode(AirportManager *manager, char *code) {
    for (int i = 0; i < manager->airportLength; ++i) {
        if (strcmp(manager->airportList[i]->IATA, code) == 0) {
            return manager->airportList[i];
        }
    }
    return NULL;
}

void printAirports(AirportManager *manager) {
    printf("there are %d airports", manager->airportLength);
    for (int i = 0; i < manager->airportLength; ++i) {
        printf("Airport name:%s                Country: %s                   Code:%s\n",
               manager->airportList[i]->airport_name, manager->airportList[i]->country, manager->airportList[i]->IATA);
    }

}

int codeExist(const AirportManager pManager, char *airportCode) {
    for (int i = 0; i < pManager.airportLength; ++i) {
        if (pManager.airportList[i]->code == airportCode) {
            return 1;
        }
    }
    return 0;
}

void freeManager(AirportManager *manager) {
    for (int i = 0; i < manager->airportLength; ++i) {
        freeAirport(manager->airportList[i]);
    }
    free(manager->airportList);
}
#include "stdio.h"
#include "string.h"
#include "AirportManager.h"
#include "Airport.h"
#include "stdlib.h"

int initManager(AirportManager *manager) {
    manager->airportLength = 0;
    manager->airportList = NULL;
    return 1;
}

int addAirport(AirportManager *manager) {
    Airport *tempAirport = (Airport *) malloc(sizeof(Airport));
    if (!tempAirport) {
        return 0;
    }
    initAirport(tempAirport);
    manager->airportList = (Airport **) realloc(manager->airportList,
                                                (sizeof(Airport *)) * (manager->airportLength + 1));
    if (!(manager->airportList)) {
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
        if (strcmp(manager->airportList[i]->code, code) == 0) {
            return manager->airportList[i];
        }
    }
    return NULL;
}

void printAirports(const AirportManager *manager) {
    printf("there are %d airports\n", manager->airportLength);
    for (int i = 0; i < manager->airportLength; ++i) {
        printf("Airport name:%-20s Country: %-15s Code:%-5s\n",
               manager->airportList[i]->name, manager->airportList[i]->country, manager->airportList[i]->code);
        printf("\n");
    }

}

int codeExist(const AirportManager *pManager, char *airportCode) {
    for (int i = 0; i < pManager->airportLength; ++i) {
        if (pManager->airportList[i]->code == airportCode) {
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
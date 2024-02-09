#include "stdio.h"
#include "string.h"
#include "airportManager.h"

AirportManager initAirportManager() {
    AirportManager manager;
    manager.airportLength = 0;
    return manager;
}

void addAirport(AirportManager *manager) {
    Airport *temp = manager->airportList[manager->airportLength];
    initAirport(temp);
    manager->airportLength++;
}


Airport* findAirportByCode(AirportManager *manager,char* code) {
    for (int i = 0; i < manager->airportLength; ++i) {
        if(strcmp(manager->airportList[i]->IATA ,code) == 0){
            return manager->airportList[i];
        }
    }
    return NULL;
}

void printAllAirports(AirportManager *manager){
    printf("there are %d airports",manager->airportLength);
    for (int i = 0; i < manager->airportLength; ++i) {
        printf("Airport name:%s                Country: %s                   Code:%s\n",
        manager->airportList[i]->airport_name,manager->airportList[i]->country,manager->airportList[i]->IATA);
    }

}
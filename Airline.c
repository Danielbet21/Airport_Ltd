#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Airline.h"

int initAirline(Airline *pAirline) {
    pAirline->name = getStrExactLength("Enter Airline name");
//  check if name is valid
    if (pAirline->name == NULL || !strlen(pAirline->name)) {
        free(pAirline->name);
        return 0;
    }
    pAirline->numOfFlights = 0;
    pAirline->flightArr = NULL;
    pAirline->planeCount = 0;
    pAirline->planeArr = NULL;
    return 1;
}

void printAirline(const Airline *pAirline) {
    printf("Airline %s\n\n",pAirline->name);
    printf(" -------- Has %d planes\n",pAirline->planeCount);
    printPlanesArr(pAirline->planeArr, pAirline->planeCount);
    printf("\n\n");
    printf(" -------- Has %d flights\n", pAirline->numOfFlights);
    printFlightsArr(pAirline);
}

void printFlightsArr(const Airline *pAirline) {
    for (int i = 0; i < pAirline->numOfFlights; i++) {
        printFlight(pAirline->flightArr[i]);
    }
}

void freeCompany(Airline *pAirline) {
    free(pAirline->name);
//  free flights
    for (int i = 0; i < pAirline->numOfFlights ; ++i) {
        freeFlight(pAirline->flightArr[i]);
    }
    free(pAirline->flightArr);
//  free planes
    free(pAirline->planeArr);
}

int addFlight(Airline *pAirline, AirportManager * pAirportManager){
    if (pAirportManager->airportLength < 2) {
        printf("There are not enough airport to set a flight\n");
        return 0;
    }
    if (pAirline->planeCount < 1) {
        printf("There is no plane in company\n");
        return 0;
    }
    //  get plane form user
    Plane *plane = getPlaneFromArr(pAirline->planeArr, pAirline->planeCount);
    if (!plane) {
        return 0;
    }
    // Create flight dynamically
    Flight *pFlight = (Flight *)malloc(sizeof(Flight));
    if (!pFlight) {
        free(pFlight);
        return 0;
    }
    initFlight(pFlight,plane,pAirportManager);

    pAirline->flightArr = (Flight**) realloc(pAirline->flightArr, (pAirline->numOfFlights + 1) * (sizeof(Flight*)));
//  if allocate failed
    if (!pAirline->flightArr) {
        freeFlight(pFlight);
        free(pFlight);
        return 0;
    }
    pAirline->flightArr[pAirline->numOfFlights] = pFlight;
    pAirline->numOfFlights++;
    return 1;
}

int addPlane(Airline *pAirline) {
    // init the new plane
    Plane plane;
    initPlane(&plane, pAirline->planeArr, pAirline->planeCount);

    // try to add the new plane to airline
    pAirline->planeArr = (Plane*) realloc(pAirline->planeArr, (pAirline->planeCount + 1) * (sizeof(Plane)));
//  if allocate failed
    if (!pAirline->planeArr) {
        return 0;
    }
    pAirline->planeArr[pAirline->planeCount] = plane;
    pAirline->planeCount++;
    return 1;
}

void doPrintFlightsWithPlaneType(const Airline *pAirline){
    int userSelect = getTypeFromUser();
    printf("Flights with plane type %s:\n",PlaneTypesTitle[userSelect]);
    int check = 0;
    for (int i = 0; i < pAirline->numOfFlights; ++i) {

        if (isPlaneTypeInFlight(pAirline->flightArr[i], userSelect)) {
            printPlane(pAirline->flightArr[i]->plane);
            check =1;
        }
    }
    if (!check) {
        printf("Sorry - could not find a flight with plane type %s:\n",PlaneTypesTitle[userSelect]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airline.h"

int initAirline(Airline *pAirline) {
    pAirline->companyName = getStrExactLength("Enter Airline name");
//  check if name is valid
    if (pAirline->companyName == NULL || !strlen(pAirline->companyName)) {
        free(pAirline->companyName);
        return 0;
    }
    pAirline->numOfFlights = 0;
    pAirline->flightArr = NULL;
    pAirline->numOfAirPlanes = 0;
    pAirline->airPlanesArr = NULL;
    return 1;
}

void printAirline(const Airline *pAirline) {
    printf("Airline %s\n\n",pAirline->companyName);
    printf(" -------- Has %d planes\n",pAirline->numOfAirPlanes);
//  print all airplanes
    for (int i = 0; i < pAirline->numOfAirPlanes; i++) {
        printPlane(&pAirline->airPlanesArr[i]);
    }
    printf("\n\n");
    printf(" -------- Has %d flights\n", pAirline->numOfFlights);
//  print all flights
    for (int i = 0; i < pAirline->numOfFlights; i++) {
        printFlight(pAirline->flightArr[i]);
    }
}

void freeAirline(Airline *pAirline) {
    free(pAirline->companyName);
//  free flights
    for (int i = 0; i < pAirline->numOfFlights ; ++i) {
        freeFlight(pAirline->flightArr[i]);
    }
    free(pAirline->flightArr);
//  free planes
    free(pAirline->airPlanesArr);
}

int addFlight(Airline *pAirline, Flight *pFlight) {
//  check if flight is not null
    if (pFlight == NULL) {
        return 0;
    }
    pAirline->flightArr = (Flight**) realloc(pAirline->flightArr, (pAirline->numOfFlights + 1) * (sizeof(Flight*)));
//  if allocate failed
    if (!pAirline->flightArr) {
        freeFlight(pFlight);
        return 0;
    }
    pAirline->flightArr[pAirline->numOfFlights] = pFlight;
    pAirline->numOfFlights++;
    return 1;
}

int addPlane(Airline *pAirline) {
    // init the new plane
    Plane plane;
    initPlane(&plane, pAirline->airPlanesArr, pAirline->numOfAirPlanes);

    // try to add the new plane to airline
    pAirline->airPlanesArr = (Plane*) realloc(pAirline->airPlanesArr, (pAirline->numOfAirPlanes+1) *(sizeof(Plane)));
//  if allocate failed
    if (!pAirline->airPlanesArr) {
        return 0;
    }
    pAirline->airPlanesArr[pAirline->numOfAirPlanes] = plane;
    pAirline->numOfAirPlanes++;
    return 1;
}

void doPrintFlightsWithPlaneType(const Airline *pAirline){
    int userSelect = getTypeFromUser();
    printf("Flights with plane type %s:\n",PlaneTypesTitle[userSelect]);
    int check = 0;
    for (int i = 0; i < pAirline->numOfFlights; ++i) {
        if (pAirline->flightArr[i]->plane.type == userSelect) {
            printPlane(&pAirline->flightArr[i]->plane);
            check =1;
        }
    }
    if (!check) {
        printf("Sorry - could not find a flight with plane type %s:\n",PlaneTypesTitle[userSelect]);
    }
}
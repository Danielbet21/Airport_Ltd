#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Flight.h"

int initFlight(Flight *pFlight, Plane *pPlane, const AirportManager *pManager) {
    // if plane is NULL will return 0
    if(pManager->airportLength < 2 || !pPlane) {
        return 0;
    }
    // set the airport codes (for source and destination)
    chooseAirport(pFlight, pManager);
    // set date and insert plane
    Date d;
    getCorrectDate(&d);
    pFlight->date = d;
    pFlight->plane = pPlane;
    return 1;
}

void chooseAirport(Flight *pFlight, const AirportManager *pManager) {
    char *prompt =  "origin";
    int bufferSize = 250;
    char buffer[250];
    printAirports(pManager);
    for (int i = 0; i < 2; ++i) {
        if (i == 1) {
            prompt = "destination";
        }
        int validCode = 0;
        do {
            printf("Enter code of %s airport:", prompt);
            myGets(buffer, bufferSize);
            validCode = codeExist(pManager, buffer);
            if (!validCode) {
                printf("No airport with this code - try again\n");
            } else if (i == 1 && isFlightFromSourceAirport(pFlight, buffer)) {
                printf("Same origin and destination airport\n");
                validCode = 0;
            }
        } while (!validCode);
        if (i == 0) {
            strcpy(pFlight->airport_c_sour, buffer);
        } else {
            strcpy(pFlight->airport_c_Tar, buffer);
        }
    }
}

int isFlightFromSourceAirport(const Flight *flight, const char *airport_code_src) {
    if (strcmp(flight->airport_c_sour, airport_code_src) == 0) {
        return 1;
    }
    return 0;
}

int isFlightToDestAirport(const Flight *flight, const char *airport_code_des) {
    if (strcmp(flight->airport_c_Tar, airport_code_des) == 0) {
        return 1;
    }
    return 0;
}

int isPlaneTypeInFlight(const Flight *flight, PlaneType planeType) {
    return (flight->plane->type == planeType);
}

void freeFlight(Flight *pFlight) {
//    TODO fix this part
//    free(pFlight->airport_c_sour);
//    free(pFlight->airport_c_Tar);
}

void printFlight(const Flight *pFlight) {
    printf("Flight From %s to %s  ", pFlight->airport_c_sour, pFlight->airport_c_Tar);
    printDate(&pFlight->date);
    printf(" ");
    printPlane(pFlight->plane);
}


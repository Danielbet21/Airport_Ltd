#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Flight.h"

char *chooseAirport(Flight *pFlight, const AirportManager *pManager, int isSource){
    // set the output message
    char *outPutMessage = "origin";
    int validCode = 0;
    char *airportCode;
    if (!isSource) {
        outPutMessage = "destination";
    }
    // print all the airport from the airport manager
    printAllAirports(pManager);
//  get airport code from user until successfully
    do {
        printf("Enter code of %s airport:",outPutMessage);
        airportCode = getStrExactLength(NULL);
        validCode = codeExist(pManager, airportCode);
        if (validCode &&!isSource && isFlightFromSourceAirport(pFlight, airportCode))  {
//          check the destination code is not source code
            printf("Same origin and destination airport\n");
            validCode = 0;
        }
    } while (!validCode);
    return airportCode;
}

int initFlight(Flight *pFlight,Plane *pPlane,const AirportManager *pManager){
    // if plane is NULL will free the flight and return 0
    if(pManager->airportLength < 2 || !pPlane) {
        freeFlight(pFlight);
        return 0;
    }
    // set the airport codes (for source and destination)
    pFlight->airport_c_sour = chooseAirport(pFlight,pManager, 1);
    pFlight->airport_c_Tar = chooseAirport(pFlight, pManager, 0);
    // set date and insert plane
    Date d;
    getCorrectDate(&d);
    pFlight->date = d;
    pFlight->plane = pPlane;
    return 1;
}

int isFlightFromSourceAirport(const Flight *flight, const char* airport_code_src){
    if (strcmp(flight->airport_c_sour, airport_code_src) == 0) {
        return 1;
    }
    return 0;
}
int isFlightToDestAirport(const Flight *flight, const char* airport_code_des){
    if (strcmp(flight->airport_c_Tar, airport_code_des) == 0) {
        return 1;
    }
    return 0;
}

int isPlaneTypeInFlight(const Flight *flight, PlaneType planeType){
    return (flight->plane->type == planeType);
}

void freeFlight(Flight *pFlight) {
    free(pFlight->airport_c_sour);
    free(pFlight->airport_c_Tar);
}
void printFlight(const Flight *pFlight){
    printf("Flight From %s to %s  ",pFlight->airport_c_sour, pFlight->airport_c_Tar);
    printDate(&pFlight->date);
    printf(" ");
    printPlane(pFlight->plane);
}

#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airline.h"
//#include "AirportManager.h"

int main() {
    AirportManager manager;
    int ok = 1;
    //This function get a pointer to the struct AirportManager
    //The function set the array to NULL and count to 0 (always return 1)
    if (!initManager(&manager)) {
        printf("Error\n");
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        //This function get the address of the struct
        //The function add an airport to the array
        if (!addAirport(&manager)) {
            printf("Error\n");
            freeManager(&manager);
            ok = 0;
            break;
        }
        for (int j = 0; j < 1; ++j) {
            printf("%s\n", manager.airportList[i]->name);
            printf("%s\n", manager.airportList[i]->country);
            printf("%s\n", manager.airportList[i]->code);
        }
        printf("end of info manager printing - main\n");
    }
    if (ok) {
        printAirports(&manager);
        freeManager(&manager);
    }
}
/*
ABC
logen
USA
ABC
DEF
ben gurion
Israel
RRR
the best one
Greece
ZZZ
sleeping
Italy*/
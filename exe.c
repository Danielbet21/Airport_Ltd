#include <stdio.h>
#include "exe.h"
#include "Airline.h"

void manualTest() {
    int userSelect = -1;
//  setup Airport Manager
    AirportManager airportManager;
    initManager(&airportManager);

//  setup Airline
    Airline airline;
    initAirline(&airline);

    do {
        printMenu();
        scanf("%d", &userSelect);
        switch (userSelect) {
            case 0:
                // Add Airport
                addAirport(&airportManager);
                break;
            case 1:
                // Add Plane
                addPlane(&airline);
                break;
            case 2:
                // Add Flight
                if (!addFlight(&airline, &airportManager)) {
                    printf("Error adding flight\n");
                }
                break;
            case 3:
                // Print Airline
                printCompany(&airline);
                break;
            case 4:
                // Print all Airports
                printAirports(&airportManager);
                break;
            case 5:
                // Print all flights with plane type
                doPrintFlightsWithPlaneType(&airline);
                break;
            case -1:
                // Exit and skip default message
                break;
            default:
                printf("Wrong option\n");
        }
    } while (userSelect != -1);



    freeCompany(&airline);
    freeManager(&airportManager);
}

void printMenu() {
    char *menuStrings[] = {"Add Airport", "Add Plane","Add Flight","Print Airline","Print all Airports","Print all flights with plane type"};    int menuSize = sizeof(menuStrings) / sizeof(menuStrings[0]); // Calculate the number of elements
    printf("Please choose one of the following options\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d - %s\n", i, menuStrings[i]);

    }
    printf("-1 - Quit\n");
}


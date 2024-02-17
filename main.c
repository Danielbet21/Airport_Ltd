#include <stdio.h>
#include "airport.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main() {
    int opt;
    printf("Please choose one of the following options\n");
    printf("1 - Date\n");
    printf("2 - Plane\n");
    printf("3 - Airport Code\n");
    printf("4 - Airport Name\n");
    printf("5 - Airport\n");
    scanf("%d", &opt);
    getchar();
    Airport port1;
    switch (opt) {
        case 3:
            getAirportCode(port1.code);
            printf("%s\n", port1.code);
            break;

        case 4:
            getAirportName(&port1);
            printf("%s\n", port1.name);
            free(port1.name);
            break;

        case 5:
            getAirportCode(port1.code);
            initAirportNoCode(&port1);
            printAirport(&port1);
            freeAirport(&port1);
            break;

    }

}

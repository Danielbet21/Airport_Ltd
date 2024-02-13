#include "stdio.h"
#include "flight.h"
#include "date.h"
//#include "airline.h"

char* validateCodeInput(AirportManager manager){
    char* input ="";
    scanf("%s", input);
    validateIATA(input);
    int flag = 0;
    int j =0;
    while(j < manager.airportLength) {
        if (manager.airportList[j]->IATA != input) {
            printf("Enter code from the list\n");
            scanf("%s", input);
            j =0;
        }
    }
    return input;
}

char *chooseAirport(AirportManager manager){
    printAllAirports(&manager);
    return validateCodeInput(manager);
}


int initFlight(Flight *flight, AirportManager manager){
   // flight->plane = choosePlane();
    printf("Enter code of origin airport:      \n");
    flight->airport_c_Tar = chooseAirport(manager);
    printf("Enter code of destination airport:         \n");
    flight->airport_c_sour = chooseAirport(manager);
    Date d;
    flight->date = initDate(d);

    return 1;
}

int isFlightFromSourceAirport(Flight *flight, const char* airport_code_src){
    if(flight->airport_c_sour == airport_code_src){
        return 1;
    }else{
        return 0;
    }
}
int isFlightToDestAirport(const Flight *flight, const char* airport_code_des){
    if(flight->airport_c_Tar == airport_code_des){
        return 1;
    }else{
        return 0;
    }
}

int isPlanTypeInFlight(Flight *flight,Plane *plane){
    if(flight->plane.type == plane->type){
        return 1;
    }else{
        return 0;
    }
}

/*Flights with plane type Commercial:
Flight From AAA To AAB  Date: 21/10/2025        Plane: serial number:123, type Commercial*/
void printFlight(PlaneType type,Airline airline,int length){
    printf("Flights with plane type %s:\n",type);
    for (int i = 0; i < length; ++i) {
        printf("Flight From %s To %s  Date: %s        Plane: serial number:123, type Commercial"
        ,airline->flight[i]->airport_c_sour,
        airline->flight[i]->airport_c_des,
        airline->flight[i]->date,
        printDate(flight[i]->date));
    }
}

#include "stdio.h"
#include "flight.h"


Flight initFlight(){
    Flight flight;
//    flight.plane = choosePlane();//airportManager
//    flight.airport_c_Tar = chooseCode();
//    flight.airport_c_sour = chooseCode();//airportManager
    Date d;
//    flight.date = initDate(d);

    return flight;
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
//void printFlight(PlaneType type,Airline airline,int length){
//    printf("Flights with plane type Commercial:\n");
//    for (int i = 0; i < length; ++i) {
//        printf("Flight From %s To %s  Date: %s        Plane: serial number:123, type Commercial"
//        ,airline->flight[i]->airport_c_sour,
//        airline->flight[i]->airport_c_des,
//        airline->flight[i]->date,
//        printDate(flight[i]->date));
//    }
//}

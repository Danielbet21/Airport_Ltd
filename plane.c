//#include <stdio.h>
//#include "plane.h"
//
//#define MIN_SERIAL_NUM 1
//#define MAX_SERIAL_NUM 9999
//
//
//int initPlane(Plane *pPlane, int serialNum, PlaneType type) {
//    if (serialNum < MIN_SERIAL_NUM || serialNum > MAX_SERIAL_NUM) {
//        return 0;
//    }
//    pPlane->serialNum = serialNum;
//    pPlane->type = type;
//    return 1;
//};
//
//PlaneType getTypeFromUser(){
//    int userSelect = -1;
//    do {
//        printf("Please enter one of the following types\n");
//        for (int i = 0; i < NofPlaneTypes; i++) {
//            printf("%d for %s\n", i, PlaneTypesTitle[i]);
//        }
//        scanf("%d", &userSelect);
//    } while (userSelect < 0 || userSelect >= NofPlaneTypes);
//};
//
//void printPlane(const Plane *pPlane){
//    printf("NEED TO CHANGE PLANE PRINT! IN plane.c file\n");
//    printf("Plane Type: %s, serial number: %d\n", PlaneTypesTitle[pPlane->type], pPlane->serialNum);
//};

#include <stdio.h>
#include "Plane.h"

#define MIN_SERIAL_NUM 1
#define MAX_SERIAL_NUM 9999


void initPlane(Plane* pPlane, Plane* planeArr, int planeCount) {
    int serialNumber;
//  get the serial number from the user and check if unique and valid
    do {
        serialNumber = getSerialNumberFromUser();
    } while (!checkSerialNumber(serialNumber,planeArr,planeCount));
    pPlane->serialNum = serialNumber;
    pPlane->type = getTypeFromUser();
}

int checkSerialNumber(int serialNumber, Plane* planeArr, int planeCount){
//    check if serial number is valid
    if (serialNumber < MIN_SERIAL_NUM || serialNumber > MAX_SERIAL_NUM) {
        return 0;
    }
//  check if the serial number is unique
    for (int i = 0; i < planeCount; i++) {
        if (planeArr[i].serialNum == serialNumber) {
            return 0;
        }
    }
    return 1;
}

int getSerialNumberFromUser() {
    printf("Enter plane serial number - between %d to %d\n",MIN_SERIAL_NUM, MAX_SERIAL_NUM);
    int serialNumber;
    scanf("%d",&serialNumber);
    return serialNumber;
}

PlaneType getTypeFromUser(){
    int userSelect = -1;
    do {
        printf("Please enter one of the following types\n");
        for (int i = 0; i < NofPlaneTypes; i++) {
            printf("%d for %s\n", i, PlaneTypesTitle[i]);
        }
        scanf("%d", &userSelect);
    } while (userSelect < 0 || userSelect >= NofPlaneTypes);
};

void printPlane(const Plane *pPlane){
    printf("Plane: serial number:%d, type %s\n", pPlane->serialNum, PlaneTypesTitle[pPlane->type]);
};


void printPlanesArr(const Plane *planeArr, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printPlane(planeArr + i);
    }
}

Plane* getPlaneFromArr(Plane *planeArr, int arraySize) {
    printf("Choose a plane from list, type its serial Number\n");
    printPlanesArr(planeArr, arraySize);
    Plane *pPlane = NULL;
    int userSerialNum = 0;
    while (!pPlane) {
        scanf("%d",&userSerialNum);
        if (userSerialNum < MIN_SERIAL_NUM || userSerialNum > MAX_SERIAL_NUM) {
            printf("No plane with that serial number! Try again!\n");
        }
        else {
            pPlane = getPlaneWithSerialNumber(planeArr,arraySize,userSerialNum);
            if (!pPlane) {
                printf("No plane with that serial number! Try again!\n");
        }
    }}
}

Plane* getPlaneWithSerialNumber(Plane *planeArr, int arraySize, int serialNumber) {
    for (int i = 0; i < arraySize; ++i) {
        if (planeArr[i].serialNum == serialNumber) {
            return &planeArr[i];
        }
    }
    return NULL;
}

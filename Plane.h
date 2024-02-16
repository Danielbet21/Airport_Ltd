#ifndef __PLANE__
#define __PLANE__

typedef enum {Commercial, Cargo, Military, NofPlaneTypes} PlaneType;
static const char *PlaneTypesTitle[NofPlaneTypes] = {"Commercial", "Cargo","Military"};

// plane struct
typedef struct {
    PlaneType type;
    int serialNum;
} Plane;


// functions
void initPlane(Plane* pPlane, Plane* planeArr, int planeCount);
PlaneType getTypeFromUser();
void printPlane(const Plane *pPlane);
int getSerialNumberFromUser();
int checkSerialNumber(int SerialNumber, Plane* planeArr, int planeCount);
void printPlanesArr(const Plane *planeArr, int arraySize);
Plane* getPlaneFromArr(Plane *planeArr, int arraySize);
Plane* getPlaneWithSerialNumber(Plane *planeArr, int arraySize, int serialNumber);

#endif
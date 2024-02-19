#ifndef __AIRPORT__
#define __AIRPORT__

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "Airport.h"
#include "generalStrings.h"
#define len 4

typedef struct {
    char *name;
    char *country;
    char code[len]; // 3 letters + '\0'
} Airport;

void getAirportName(Airport *port1);

char *delete_white(char *str);

void getAirportCode(char *code);

void getAirportCountry(Airport *pAirport);

void initAirportNoCode(Airport *pAirport);

void printAirport(Airport *pAirport);

void freeAirport(Airport *pAirport);

void initAirport(Airport *pAirport);

int isSameAirport(Airport *airport1, Airport *airport2);

char converter(char *name, int j);

int isAirportCode(Airport *airport, const char *code);

char *validateName(char *name);

void oneWordName(char* name, char* new_name);
void evenName(char* name, char* new_name);
void oddName(char* name, char* new_name);


char *dynamicAlloc(int num_of_words);

char *insertBlank(char *name, int num_of_words);

#endif
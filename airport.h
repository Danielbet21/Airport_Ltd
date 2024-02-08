#ifndef __AIRPORT__
#define __AIRPORT__

#define len 4

typedef struct {
    char *airport_name;
    char *country;
    char IATA[len]; // 3 letters + '\0'
} Airport;


void initAirport(Airport *pAirport);

int validateIATA(char *code);

int isSameAirport(Airport *airport1, Airport *airport2);

int isAirportCode(Airport *airport, char *IATA);

char *validateName(char *name);

char *dynamicAlloc(int num_of_words);

char *insertBlank(char *name, int num_of_words);

#endif
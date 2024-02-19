#include "Airport.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "generalStrings.h"

void initAirport(Airport *pAirport) {
    getAirportCode(pAirport->code);
    getAirportName(pAirport);
    getAirportCountry(pAirport);
}

int isSameAirport(Airport *airport1, Airport *airport2) {
    if (airport1->code == airport2->code) {
        return 1;
    } else {
        return 0;
    }
}

int isAirportCode(Airport *airport, const char *IATA) {
    if (airport->code == IATA) {
        return 1;
    } else {
        return 0;
    }
}

void validateIATA(char *code) {
    do {
        char *temp = getStrExactLength("Enter airport code  - 3 UPPER CASE letters");
//        printf("Enter airport code  - 3 UPPER CASE letters\n");
//        scanf("%s", temp);
        if (strlen(temp) != 3) {
            printf("code should be 3 letters\n");
            continue;
        }
        int isValid = 1;
        for (int i = 0; i < 3; ++i) {
            if ((temp[i]) < 'A' || temp[i] > 'Z') {
                printf("Need to be upper case letter\n");
                isValid = 0;
                break;
            }
        }
        if (isValid) {
            strcpy(code, temp);
            free(temp);
            break;// Exit loop if the code is valid
        }
        if (!isValid) {
            free(temp);
            continue;
        }
    } while (1);
}

char *dynamicAlloc(int num_of_words) {
    char *new_name = malloc(num_of_words);
    if (new_name == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return new_name;
}

char converter(char *name, int j) {
    if ((j - 1 == -1 || name[j - 1] == ' ') && name[j] < 'z' && name[j] > 'a') {
        name[j] = (char) (name[j] - 32);
    }
    return name[j];
}

char *insertBlank(char *name, int num_of_words) {
    //allocate new mem for the modification:
    char *new_name;
    if (num_of_words == 0 || num_of_words % 2 != 0) {
        new_name = dynamicAlloc(num_of_words * 2);
        memset(new_name, '\0', num_of_words * 2 + 1);
    } else if (num_of_words % 2 == 0) {
        new_name = dynamicAlloc(num_of_words * 2 + 1);
    }

    if (num_of_words == 1) {
        // if 0 (one word)-> all uppercase and put '_' between each letter
        //converting to upper case all letters in one word case
        for (int j = 0; j < strlen(name); ++j) {
            if (name[j] <= 'z' && name[j] >= 'a' || name[j] <= 'Z' && name[j] >= 'A') {
                name[j] = (char) (name[j] - 32);
            }
        }
        int i = 0;
        for (int j = 0; j < strlen(name); j++) {
            if (j < strlen(name) - 1) { // Check if not the last letter
                new_name[i++] = name[j];
                new_name[i++] = '_';
            } else {
                new_name[i++] = name[j];
            }
        }
        new_name[i] = '\0';

        // if num of words in odd-> '_' , if even-> '__' between each letter
    } else if (num_of_words % 2 != 0) {
        int i = 0;
        //converting only the first letter in the word
        for (int j = 0; j < strlen(name); ++j) {
            if (name[j] <= 'z' && name[j] >= 'a' || name[j] <= 'Z' && name[j] >= 'A') {
                if (j - 1 == -1 || name[j - 1] == ' ') {
                    new_name[j] = converter(name, j);
                }
                new_name[j] = name[j];
            } else {
                new_name[j] = name[j];
            }
            i++;
        }
        new_name[i] = '\0';
    } else if (num_of_words % 2 == 0) {
        int i = 0;
        for (int j = 0; j < strlen(name); ++j) {
            if (name[j] <= 'z' && name[j] >= 'a' || name[j] <= 'Z' && name[j] >= 'A') {
                if (j - 1 == -1 || name[j - 1] == ' ') {
                    new_name[i] = converter(name, j);
                }
                new_name[i] = name[j];
            } else if (name[j] == ' ') {
                new_name[i] = ' ';
                new_name[++i] = ' ';
            }
            i++;
        }
        new_name[i] = '\0';
    }
    return new_name;
}

char *delete_white(char *str) {
    int counter_white = 0;
    int counter_letter = 0;
    char *res = NULL;
    res = realloc(res, 1);

    int j = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if ((str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')) {
            counter_letter++;
            counter_white++;
            res = realloc(res, strlen(res) + 1);
            res[j] = str[i];
            j++;
            counter_white = 0;
        } else if (isspace(str[i]) && counter_white == 0 && counter_letter != 0) {
            res[j] = str[i];
            j++;
            counter_white++;
        }
    }
    res[j] = '\0';
    return res;
}

char *validateName(char *name) {
    //cleaning white space begin and end
    char *new_name = delete_white(name);

    //checking how many words in the name:
    int num_of_words = 1;
    char *demo_name = malloc(strlen(new_name));
    strcpy(demo_name, new_name);
    while (*(new_name) != '\0') {
        if (*(new_name) == ' ') {
            num_of_words += 1;
        }
        new_name++;
    }
    char *res = insertBlank(demo_name, num_of_words);
    return res;
}

void getAirportName(Airport *pAirport) {
    char *name = getStrExactLength("Enter airport name");
    name = validateName(name);
    pAirport->name = name;
}

void getAirportCode(char *code) {
    validateIATA(code);
}

void getAirportCountry(Airport *pAirport) {
    char temp1[100];
    printf("Add airport's country:\n");
    scanf("%99s", temp1);
    pAirport->country = (char *) malloc(strlen(temp1) + 1);

    if (!pAirport->country) {
        return;
    }

    strcpy(pAirport->country, temp1);
}

void initAirportNoCode(Airport *pAirport) {
    getAirportName(pAirport);
//    pAirport->country = getStrExactLength("Enter airport country");

}

void printAirport(Airport *pAirport) {
    printf("Airport name:%s                  Country: %s                     Code:%s\n", pAirport->name,
           pAirport->country, pAirport->code);
}

void freeAirport(Airport *pAirport) {
    free(pAirport->country);
}
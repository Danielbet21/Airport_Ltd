#include "airport.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//---------------------------------------- add printing------------------------------------

void initAirport(Airport *pAirport) {
    printf("Enter airport name\n");
    char *name = NULL;
    scanf("%s", name); // validation
    name = validateName(name);
    pAirport->airport_name = name;

    printf("Enter airport country\n");
    scanf("%s", pAirport->country);

    char *res = validateIATA();
    for (int i = 0; i < 3; ++i) {
        pAirport->IATA[i] = res[i];
    }
}

int isSameAirport(Airport *airport1, Airport *airport2) {
    if (airport1->IATA == airport2->IATA) {
        return 1;
    } else {
        return 0;
    }
}

int isAirportCode(Airport *airport, const char *IATA) {
    if (airport->IATA == IATA) {
        return 1;
    } else {
        return 0;
    }
}

char *validateIATA() {
    char *code;
    do {
        printf("Enter airport code  - 3 UPPER CASE letters\n");
        scanf("%s", code);
        if (strlen(code) != 3) {
            printf("code should be 3 letters\n");
            continue;
        }
        int isValid = 1;
        for (int i = 0; i < 3; ++i) {
            if ((code[i]) < 'A' || code[i] > 'Z') {
                printf("%c", code[i]);
                printf("All characters should be upper case letters\n");
                isValid = 0;
                break;
            }
        }
        if (!isValid) {
            continue;
        }
        break; // Exit loop if the code is valid
    } while (1);
    return code;
}

char *dynamicAlloc(int num_of_words) {
    char *new_name = malloc(num_of_words);
    if (new_name == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    return new_name;
}

char converter(char *name, char *new_name, int j) {
    if (j - 1 == -1 || name[j - 1] == ' ') {
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

    if (num_of_words == 0) {
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
                    new_name[j] = converter(name, new_name, j);
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
                    new_name[i] = converter(name, new_name, j);
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

char *validateName(char *name) {
    //cleaning white space begin and end
    int num_of_white = 0;
    if (*(name) == ' ') {
        num_of_white += 1;
    }
    if (*(name + strlen(name)) == ' ') {
        num_of_white += 1;
    }

    char *new_name = malloc(strlen(name) - num_of_white);
    if (new_name == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    //passing the data to the new name:
    for (int i = 1; i < strlen(new_name); ++i) {
        new_name[i - 1] = name[i];
    }
    //checking how many words in the name:
    int num_of_words = 1;
    while (*(new_name) != '\0') {
        if (*(new_name) == ' ') {
            num_of_white += 1;
        }
        new_name++;
    }
    return insertBlank(new_name, num_of_words);
}
#include <stdio.h>
#include "airport.h"
#include "stdlib.h"

int main() {
//    char* str =insertBlank("one",1);
//    printf("%s",str);
//    return 0;
//}
    char name[] = "one two three";
    int num_of_words = 2; // Use 0 for all uppercase and underscores

    char *modified_name = insertBlank(name, num_of_words);

    printf("Modified string: %s\n", modified_name);
    free(modified_name);
    return 0;
}

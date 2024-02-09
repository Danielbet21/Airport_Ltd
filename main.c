#include <stdio.h>

int main() {
    int choice;
    do {
        printf("Please choose one of the following options"
               "\n0 - Add Airport"
               "\n1 - Add Plane"
               "\n2 - Add Flight"
               "\n3 - Print Airline"
               "\n4 - Print all Airports"
               "\n5 - Print all flights with plane type"
               "\n-1 - Quit\n");
        scanf("%d",&choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case -1:
                return 0;
        }
    }while(choice);

    return 0;
}

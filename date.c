#include <stdio.h>
#include <string.h>
#include "date.h"

#define DATE_DELIMITER '/'
#define VALID_YEAR_START 2023

int initDate(Date *pDate, int day, int month, int year) {
    // check if date is valid
    if (!isDateValid(day,month,year)) {
        return 0;
    }
    pDate->day = day;
    pDate->month = month;
    pDate->year = year;
};


int isDateValid(int day, int month, int year) {
//  check year validation
    if (year < VALID_YEAR_START) {
        return 0;
    }
//  check month validation
    if(month < 1 || month > 12) {
        return 0;
    }
//   check if day is in month days range
    else if (!isDayValid(day,month)) {
        return 0;
    };
    return 1;
}

int isDayValid(int day,int month) {
    // Array to store the maximum number of days in each month (NOT CONSIDER LEAP YEAR AS WE WERE TOLD IN CLASS)
    int maxDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > maxDaysInMonth[month -1]) {
        return 0;
    }
    return 1;
}

void printDate(const Date *pDate) {
    printf("%d%c%d%c%d",pDate->day,DATE_DELIMITER, pDate->month,DATE_DELIMITER, pDate->year);
};



int initDateFromString(Date *pDate, char *dateStr) {
//  Need to get a string with this format: dd##mm##yyyy
    int dateStrLen = (int) strlen(dateStr);
//  create dateArr to store [day,month,year]
    int dateArr[3] = {0,0,0};
    if (dateStrLen != 12) {
//      Format contain 12 chars, so if dateStrLen != 12 it is not in the format
        return 0;
    }
    int counter = 0;
//  fill the DateArr with int as [day,month,year]
    for (int i = 0; i < dateStrLen; i++) {
        char tempChar = dateStr[i];
        if (tempChar != '#') {
            // check if char is a real number (int)
            if (tempChar - '0' >= 0 && tempChar - '0' <= 9) {
                dateArr[counter] = (dateArr[counter] * 10) + tempChar - '0';
            } else {
//              mean that tempChar needs to be number but it isn't
                return 0;
            }
        } else {
            // will try to get to wrong array index
            if (counter > 3) {
                return 0;
            }
            counter++;
            i++;
        }
    }
    return (initDate(pDate, dateArr[0], dateArr[1], dateArr[2]));
}
#ifndef __MYDATE__
#define __MYDATE__


// date struct
typedef struct {
    int day;
    int month;
    int year;
} Date;

// functions
int initDate(Date *pDate, int day, int month, int year);
int initDateFromString(Date *pDate, char *dateStr);
int isDateValid(int day, int month, int year);
int isDayValid(int day,int month);
void printDate(const Date *pDate);
int getCorrectDate(Date *pDate);

#endif
//Next date problem header file
#ifndef NEXTDATE_H
#define NEXTDATE_H


//content of the header file
bool leapYear(int year);
void day31(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear);
void day30(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear);
void dayDec(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear);
void dayFeb(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear);
#endif

/*
Homework #1 Part 1 NextDate
Name: Shu-Hao Chang (Ken Chang)
Student ID: 0456151
Date: Oct 20, 2015

Motivation:
- Learn the first step to write testing code coding by using XUnit (googe testing framework)
- Practice boundary value, equivalence class, , edge testing, and decision table based)
- Practice TDD (test-driven development) by google test
- Practice Xunit in a practical project
Goal:
- Implement the Triangle, NextDate, Commission problems by TDD
- Using XUnit for writing testing code
- In this time, we use google testing framework
- Analyze boundary value, equivalence class, edge values, and decision table based
- writing test code using these analyses
*/

#include<iostream>
using namespace std;



//determine a leap year
bool leapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}
void day31(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear) {
	if (day < 31) {
		nextDay = day++;
	}
	else {
		nextDay = 1;
		nextMonth = month++;
	}
	nextYear = year;
}
void day30(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear) {
	if (day < 31) {
		nextDay = day++;
	}
	else {
		nextDay = 1;
		nextMonth = month++;
	}
	nextYear = year;
}
void dayDec(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear) {
	if (day < 31) {
		nextDay = day++;
		nextYear = year;
	}
	else {
		nextDay = 1;
		nextMonth = 1;
		nextYear = year++;
	}
}
void dayFeb(int day, int month, int year, int &nextDay, int &nextMonth, int &nextYear, bool isDate) {
	if (day < 28) {
		nextDay = day++;
	}
	else if (day == 28) {
		if (leapYear(year)) {
			nextDay = 29;
		}
		else {
			nextDay = 1;
			nextMonth = 3;
		}
	}
	else if (day == 29) {
		if (leapYear(year)) {
			nextDay = 1;
			nextMonth = 3;
		}
		else {
			cout << "Cannot have Feb. " << day << endl;
			isDate = false;
		}
	}
}
int main() {
	int day, month, year;
	int nextDay, nextMonth, nextYear; //the date, one day after the entered date
	bool isDate = true; //does this date exist?
	cout << "Please enter the date, month, and year (MM DD YY): ";
	cin >> day >> month >> year;

	//Four cases: day with 31 days, day with 30 days, Decemeber, and Feburary.
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
		day31(day, month, year, nextDay, nextMonth, nextYear);
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11) {
		day30(day, month, year, nextDay, nextMonth, nextYear);
	}
	else if(month == 12) {
		dayDec(day, month, year, nextDay, nextMonth, nextYear);
	}
	else if(month == 2) {
		dayFeb(day, month, year, nextDay, nextMonth, nextYear, isDate);
	}

	cout << "The next date is: " << nextDay << " " << nextMonth << " " << nextYear << endl;
	system("PAUSE");
	return 0;
}

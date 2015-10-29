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

#include <iostream>
#include <sstream> //std::ostringstream
#include <string>
using namespace std;



//determine a leap year
bool leapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else 
		return false;
}

int dayHandle(int day, int month, int year) {
	if(day > 31 || day <= 0 || month <= 0 || month > 12 || year < 0){
		return -1;
	}else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
		if (day <= 30) {
			return day+1;
		}
		else {
			return 1;
		}
	}else if(month == 4 || month == 6 || month == 9 || month == 11) {
		if (day <= 29) {
			return day+1;
		}else{
			return 1;
		}
	}else if(month == 12) {
		if (day <= 30) {
			return day + 1;
		}else {
			return 1;
		}
	}
	else if(month == 2) {
		if (day <= 27) {
			return day + 1;
		}
		else if (day == 28) {
			if (leapYear(year)) {
				return 29;
			}else {
				return 1;		
			}
		}
		else if (day == 29) {
			if (leapYear(year)) {
				return 1;
			}else {
				cout<<"Press any key to continue"<<endl;
				//cin.ignore().get();
				return -1;
			}
		}else
			return -1;
	}
}

int monthHandle(int day, int month, int year) {
	
	if(day > 31 || day <= 0 || month <= 0 || month > 12 || year < 0){
		return -1;
	}else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
		if (day <= 30) {
			return month;
		}
		else {
			return month+1;
		}
	}else if(month == 4 || month == 6 || month == 9 || month == 11) {
		if (day <= 29) {
			return month;
		}else {
			return month+1;
		}
	}else if(month == 12) {
		if (day <= 30) {
			return month;
		}else {
			return 1;	
		}
	}
	else if(month == 2) {
		if (day <= 27) {
			return month;
		}
		else if (day == 28) {
			if (leapYear(year)) {
				return month;
			}else {
				return 3;			
			}
		}
		else if (day == 29) {
			if (leapYear(year)) {
				return 3;
			}else {
				cout<<"Press any key to continue"<<endl;
				//cin.ignore().get();
				return -1;
			}
		}else
			return -1;
	}
}

int yearHandle(int day, int month, int year) {
	if(day > 31 || day <= 0 || month <= 0 || month > 12 || year < 0){
		return -1;
	}else if(month == 12) {
		if (day <= 30) 
			return year;
		else
			return year + 1;
	}
	else if(month == 2) {
		if(day <= 28){
			return year;
		}else if (day == 29) {
			if (!leapYear(year)) {
				cout<<"error"<<endl;
				//cin.ignore().get();
				return -1;
			}else
				return year;
		}else if(day > 29){
			return -1;
		}else
			return year;
	}else		
		return year;
}

/*
int main() {
	int day, month, year;
	int nextDay, nextMonth, nextYear; //the date, one day after the entered date
	//bool isDate; //does this date exist?
	
	cout << "Please enter the date, month, and year (MM DD YY): ";
	cin >> month >> day >> year;
	//if(day <= 31 && day > 0 && month > 0 && month < 13 && year >= 0)
	//	isDate = true;
	//else
	//	isDate = false;
	//if(isDate)
		nextDay = dayHandle(day, month, year);
		nextMonth = monthHandle(day, month, year);
		nextYear = yearHandle(day, month, year);
	//else
	//	cout<<"input error 0"<<endl;
	
	//cout << "The next date is: " << nextMonth << " " << nextDay << " " << nextYear << endl;
	//if(nextYear != 0 || nextMonth != 0 || nextDay != 0)
		cout << "The next date is: " << nextMonth << " " << nextDay << " " << nextYear << endl;
	//else
	//	cout<<"input error 1"<<endl;
	//cout<<"Press any key to continue"<<endl;
	//cin.ignore().get();
	//system("PAUSE");
	return 1;
}
*/


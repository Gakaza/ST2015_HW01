/*
Homework #1 Part 2 Triangle
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
using namespace std;

bool isTriangleCheck(int a, int b, int c) {
	if (a > 0 && b > 0 && c > 0 && a <= 200 && b <= 200 && c <= 200 && (a < b + c) && (b < a + c) && (c < b + a))
		return true;
	else
		return false;
}

int triangleType(bool isTriangleCheck, int a, int b, int c) {

	if (isTriangleCheck) {
		if ((a == b) && (b == c)){
			cout << "Equilateral" << endl;
			return 1;
		}else if ((a != b) && (b != c) && (a != c)){
			cout << "Scalene" << endl;
			return 2;
		}else{
			cout << "Isoscelese" << endl;
			return 3;
		}
	}
	else{
		
		return 0;
	}
}

/*
int main(){
	int sideA, sideB, sideC, triangle;
	bool isTriangle;

	//Input the three sides of a triangle
	cout << "Enter 3 integers which are the sides of a triangle (0 < side <= 200): ";
	cin >> sideA >> sideB >> sideC;
	cout << "\nThe three sides are: " << sideA << " " << sideB << " " << sideC << endl;
		
	isTriangle = isTriangleCheck(sideA, sideB, sideC); //Determine whether this is a triangle or not	
	triangle = triangleType(isTriangle, sideA, sideB, sideC); //Determine the type of the triangle
	if(!triangle)
		cout << "Not a Triangle" << endl;
	cout<<"Press any key to continue"<<endl;
	cin.ignore().get();
	return 0;
}

*/

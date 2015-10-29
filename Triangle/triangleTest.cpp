/*Test code for the triangle.cpp
 * Name: Shu-Hao Chang (Ken Chang)
 * Student ID: 0456151
 * Date: Oct 20, 2015
 * 
 * 
 * 
 * */
#include "triangle.cpp"
#include <gtest/gtest.h>
#include <iostream>
//ostringstream output;
//Guide to setup gtest in ubuntu: http://stackoverflow.com/questions/18908923/unit-test-using-gtest-1-6-how-to-check-what-is-printed-out


//Boundary Value Test: go through various of normal boundary value test cases (chapter 5 slide 19)
//and some extreme test cases
TEST(TriangleBoundaryTEST, TriangleCheck) {
	//1 side > sume of 2 sides
	EXPECT_FALSE(isTriangleCheck(1, 100, 1)) << "2 sides < 3rd side\n";
	EXPECT_FALSE(isTriangleCheck(1, 1, 100)) << "2 sides < 3rd side\n";
	EXPECT_FALSE(isTriangleCheck(3, 1, 1)) << "2 sides < 3rd side\n";
	
	//side length is larger than 200 (default)
	EXPECT_FALSE(isTriangleCheck(1, 1, 201));
	EXPECT_FALSE(isTriangleCheck(1, 201, 1));
	EXPECT_FALSE(isTriangleCheck(201, 1, 1));
	EXPECT_FALSE(isTriangleCheck(201, 201, 1));
	EXPECT_FALSE(isTriangleCheck(201, 201, 201));
	EXPECT_FALSE(isTriangleCheck(201, 201, 1));
	EXPECT_FALSE(isTriangleCheck(65535, 201, 300));
}

//(Eq, Scal, Iso) => (1, 2, 3)
TEST(TriangleBoundaryTEST, ScaleneTest) {
	//Scalene
	EXPECT_EQ(2, triangleType(true, 100, 95, 98)); //problem with the void print function...
	EXPECT_EQ(2, triangleType(true, 100, 70, 50));
	EXPECT_EQ(2, triangleType(true, 4, 3, 5));
}

TEST(TriangleBoundaryTEST, IsosecelesTest) {
	//Isoseceles
	EXPECT_EQ(3, triangleType(true, 100, 100, 1));
	EXPECT_EQ(3, triangleType(true, 100, 100, 2));
	EXPECT_EQ(3, triangleType(true, 1, 2, 2));
	EXPECT_EQ(3, triangleType(true, 2, 1, 2));
}

TEST(TriangleBoundaryTEST, EquilateralTest) {
	//Equilateral
	EXPECT_EQ(1, triangleType(true, 1, 1, 1));
	EXPECT_EQ(1, triangleType(true, 65535, 65535, 65535));
}

//Equivalence Class Testing: test one case per class
TEST(TriangleEqTEST, triangleEqTest) {
	//negative values or zero values
	EXPECT_FALSE(isTriangleCheck(0, 0, 0)) << "zero values\n";
	EXPECT_FALSE(isTriangleCheck(-1, 1, 1)) << "sideA is negative values\n";
	EXPECT_FALSE(isTriangleCheck(1, -1, 1)) << "sideB is negative values\n";
	EXPECT_FALSE(isTriangleCheck(1, 1, -1)) << "sideC is negative values\n";
	//2 sides smaller than 3rd side
	EXPECT_FALSE(isTriangleCheck(5, 1, 1)) << "2 sides < 3rd side, not a triangle\n";
}

TEST(TriangleEqTEST, OutOfRangeEqTest) {
	//negative values or zero values
	EXPECT_FALSE(isTriangleCheck(201, 150, 150)) << "sideA is out of range\n";
	EXPECT_FALSE(isTriangleCheck(150, 201, 150)) << "sideB is out of range\n";
	EXPECT_FALSE(isTriangleCheck(150, 150, 201)) << "sideC is out of range\n";
}

TEST(TriangleEqTEST, TypeTriangleEqTest) {
	EXPECT_EQ(1, triangleType(true, 1, 1, 1)); //Equilateral
	EXPECT_EQ(2, triangleType(true, 100, 95, 98)); //Scalene
	EXPECT_EQ(3, triangleType(true, 100, 100, 1));	//Isoseceles	
}

/*Edge Value: hybrid of Eq. class and boundary testing
 * */
TEST(TriangleEdgeTEST, NegAndZeroValueEDTest) {
	//zero values
	EXPECT_FALSE(isTriangleCheck(0, 0, 0)) << "zero values\n";
	EXPECT_FALSE(isTriangleCheck(2, 5, 0)) << "sideC is zero\n";
	EXPECT_FALSE(isTriangleCheck(2, 0, 5)) << "sideB is zero\n";
	EXPECT_FALSE(isTriangleCheck(0, 5, 10)) << "sideA is zero\n";
	//negative values
	EXPECT_FALSE(isTriangleCheck(-1, 1, 1)) << "sideA is negative values\n";
	EXPECT_FALSE(isTriangleCheck(1, -1, 1)) << "sideB is negative values\n";
	EXPECT_FALSE(isTriangleCheck(1, 1, -1)) << "sideC is negative values\n";
	EXPECT_FALSE(isTriangleCheck(1, -1, -1)) << "sideB/C are negative values\n";
	EXPECT_FALSE(isTriangleCheck(-1, 1, -1)) << "sideA/C are negative values\n";
	EXPECT_FALSE(isTriangleCheck(-1, -1, 1)) << "sideA/B are negative values\n";
	EXPECT_FALSE(isTriangleCheck(-1, -1, -1)) << "sideA/B/C are negative values\n";
}

TEST(TriangleEdgeTEST, twoSidesValueEDTest) {
	EXPECT_FALSE(isTriangleCheck(5, 1, 1)) << "2 sides < 3rd side, not a triangle\n";
	EXPECT_FALSE(isTriangleCheck(1, 5, 1)) << "2 sides < 3rd side, not a triangle\n";
	EXPECT_FALSE(isTriangleCheck(5, 1, 10)) << "2 sides < 3rd side, not a triangle\n";
}

TEST(TriangleEdgeTEST, OutOfRangeEDTest) {
	//negative values or zero values
	EXPECT_FALSE(isTriangleCheck(201, 150, 150)) << "sideA is out of range\n";
	EXPECT_FALSE(isTriangleCheck(150, 201, 150)) << "sideB is out of range\n";
	EXPECT_FALSE(isTriangleCheck(150, 150, 201)) << "sideC is out of range\n";
	EXPECT_FALSE(isTriangleCheck(1050, 150, 201)) << "sideA/C are out of range\n";
	EXPECT_FALSE(isTriangleCheck(1500, 1050, 200)) << "sideA/B are out of range\n";
	EXPECT_FALSE(isTriangleCheck(150, 1500, 201)) << "sideB/C are out of range\n";
	EXPECT_FALSE(isTriangleCheck(1500, 1050, 2000)) << "sideA/B/C are out of range\n";
}

TEST(TriangleEdgeTest, EquilateralEDTest){
	//Equilateral
	EXPECT_EQ(1, triangleType(1, 200, 200, 200)) << "Equal sides";
	EXPECT_EQ(1, triangleType(1, 1, 1, 1)) << "Equal sides";
	EXPECT_NE(1, triangleType(0, -1, -1, -1)) << "negative equal sides...";
}

TEST(TriangleEdgeTest, ScaleneEDTest){
	//Scalene
	EXPECT_EQ(2, triangleType(1, 200, 156, 170)) << "Scalene";
	EXPECT_EQ(2, triangleType(1, 20, 27, 25)) << "Scalene";
	EXPECT_EQ(2, triangleType(1, 3, 8, 9)) << "Scalene";
}

TEST(TriangleEdgeTest, IsosecelesEDTest){
	//Isoseceles	
	EXPECT_EQ(3, triangleType(1, 200, 170, 170)) << "Isoseceles";
	EXPECT_EQ(3, triangleType(1, 25, 27, 25)) << "Isoseceles";
	EXPECT_EQ(3, triangleType(1, 3, 3, 2)) << "Isoseceles";
}

/*Decision Table Based
 * 11 functional test cases:
	 * 3 impossible cases
	 * 3 to fail the triangle property
	 * one to get an equilateral triangle
	 * one to get a scalene triangle
	 * 3 to get isosceles triangle

 * */
TEST(TriangleDecisionTest, ImpossibleDecisionTest){
	//3 Impossible cases	
	EXPECT_NE(2, triangleType(0, 201, 15, 20)) << "ImpossibleTest";
	EXPECT_NE(3, triangleType(0, 25, 1500, 25)) << "ImpossibleTest";
	EXPECT_NE(1, triangleType(0, -4, 30, 2000)) << "ImpossibleTest";
}

TEST(TriangleDecisionTest, TriangleFailedDecisionTest){
	//3 cases that failed tirangle property	
	EXPECT_NE(2, triangleType(0, 200, 15, 20)) << "ImpossibleTest";
	EXPECT_NE(1, triangleType(0, 25, 150, 25)) << "ImpossibleTest";
	EXPECT_EQ(0, triangleType(0, 3, 30, 200)) << "ImpossibleTest";
}

TEST(TriangleDecisionTest, EquilateralDecisionTest){
	//1 equilateral
	EXPECT_EQ(1, triangleType(1, 15, 15, 15)) << "Equal sides";
}

TEST(TriangleDecisionTest, ScalenelDecisionTest){
	//1 Scalene
	EXPECT_EQ(2, triangleType(1, 15, 16, 17)) << "Scalene";
}

TEST(TriangleDecisionTest, IsoDecisionTest){
	//3 Isosceles
	EXPECT_EQ(3, triangleType(1, 200, 170, 170)) << "Isoseceles";
	EXPECT_EQ(3, triangleType(1, 25, 27, 25)) << "Isoseceles";
	EXPECT_EQ(3, triangleType(1, 3, 3, 2)) << "Isoseceles";
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

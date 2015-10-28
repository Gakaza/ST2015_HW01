#include "triangle.cpp"
#include <gtest/gtest.h>

//Boundary Value Test: go through various of normal boundary value test cases (chapter 5 slide 19)
//and some extreme test cases
TEST(TriangleBoundaryTEST, TriangleCheck) {
	//1 side > sume of 2 sides
	ASSERT_FALSE(isTriangleCheck(1, 100, 1)) << "2 sides < 3rd side\n";
	ASSERT_FALSE(isTriangleCheck(1, 1, 100)) << "2 sides < 3rd side\n";
	ASSERT_FALSE(isTriangleCheck(3, 1, 1)) << "2 sides < 3rd side\n";
	
	//side length is larger than 200 (default)
	ASSERT_TRUE(isTriangleCheck(1, 1, 201));
	ASSERT_TRUE(isTriangleCheck(1, 201, 1)) ;
	ASSERT_TRUE(isTriangleCheck(201, 1, 1)) ;
	ASSERT_TRUE(isTriangleCheck(201, 201, 1));
	ASSERT_TRUE(isTriangleCheck(201, 201, 201));
	ASSERT_TRUE(isTriangleCheck(201, 201, 1));
	ASSERT_TRUE(isTriangleCheck(65535, 201, 1));
}

TEST(TriangleBoundaryTEST, ScaleneTest) {
	//Scalene
	EXPECT_STREQ("Scalene", triangleType(1, 100, 95, 98));
	EXPECT_STREQ("Scalene", triangleType(1, 100, 70, 50));
	EXPECT_STREQ("Scalene", triangleType(1, 4, 3, 5));
}

TEST(TriangleBoundaryTEST, IsosecelesTest) {
	//Isoseceles
	EXPECT_STREQ("Isoseceles", triangleType(1, 100, 100, 1));
	EXPECT_STREQ("Isoseceles", triangleType(1, 100, 100, 2));
	EXPECT_STREQ("Isoseceles", triangleType(1, 1, 2, 2));
	EXPECT_STREQ("Isoseceles", triangleType(1, 2, 1, 2));
}

TEST(TriangleBoundaryTEST, EquilateralTest) {
	//Equilateral
	EXPECT_STREQ("Equilateral", triangleType(1, 1, 1, 1));
	EXPECT_STREQ("Equilateral", triangleType(1, 65535, 65535, 65535));
}

//Equivalence Class Testing: test one case per class
TEST(TriangleEqTEST, triangleEqTest) {
	//negative values or zero values
	ASSERT_FALSE(isTriangleCheck(0, 0, 0)) << "zero values\n";
	ASSERT_FALSE(isTriangleCheck(-1, 1, 1)) << "sideA is negative values\n";
	ASSERT_FALSE(isTriangleCheck(1, -1, 1)) << "sideB is negative values\n";
	ASSERT_FALSE(isTriangleCheck(1, 1, -1)) << "sideC is negative values\n";
	//2 sides smaller than 3rd side
	ASSERT_FALSE(isTriangleCheck(5, 1, 1)) << "2 sides < 3rd side, not a triangle\n";
}

TEST(TriangleEqTEST, OutOfRangeEqTest) {
	//negative values or zero values
	ASSERT_FALSE(isTriangleCheck(201, 150, 150)) << "sideA is out of range\n";
	ASSERT_FALSE(isTriangleCheck(150, 201, 150)) << "sideB is out of range\n";
	ASSERT_FALSE(isTriangleCheck(150, 150, 201)) << "sideC is out of range\n";
}

TEST(TriangleEqTEST, TypeTriangleEqTest) {
	EXPECT_STREQ("Equilateral", triangleType(1, 1, 1, 1)); //Equilateral
	EXPECT_STREQ("Isoseceles", triangleType(1, 100, 100, 1));	//Isoseceles
	EXPECT_STREQ("Scalene", triangleType(1, 100, 95, 98)); //Scalene
}

//Edge Value: hybrid of Eq. class and boundary testing
TEST(TriangleEdgeTEST, NegAndZeroValueEDTest) {
	//zero values
	ASSERT_FALSE(isTriangleCheck(0, 0, 0)) << "zero values\n";
	ASSERT_FALSE(isTriangleCheck(2, 5, 0)) << "sideC is zero\n";
	ASSERT_FALSE(isTriangleCheck(2, 0, 5)) << "sideB is zero\n";
	ASSERT_FALSE(isTriangleCheck(0, 5, 10)) << "sideA is zero\n";
	//negative values
	ASSERT_FALSE(isTriangleCheck(-1, 1, 1)) << "sideA is negative values\n";
	ASSERT_FALSE(isTriangleCheck(1, -1, 1)) << "sideB is negative values\n";
	ASSERT_FALSE(isTriangleCheck(1, 1, -1)) << "sideC is negative values\n";
	ASSERT_FALSE(isTriangleCheck(1, -1, -1)) << "sideB/C are negative values\n";
	ASSERT_FALSE(isTriangleCheck(-1, 1, -1)) << "sideA/C are negative values\n";
	ASSERT_FALSE(isTriangleCheck(-1, -1, 1)) << "sideA/B are negative values\n";
	ASSERT_FALSE(isTriangleCheck(-1, -1, -1)) << "sideA/B/C are negative values\n";
}

TEST(TriangleEdgeTEST, twoSidesValueEDTest) {
	ASSERT_FALSE(isTriangleCheck(5, 1, 1)) << "2 sides < 3rd side, not a triangle\n";
	ASSERT_FALSE(isTriangleCheck(1, 5, 1)) << "2 sides < 3rd side, not a triangle\n";
	ASSERT_FALSE(isTriangleCheck(5, 1, 10)) << "2 sides < 3rd side, not a triangle\n";
}

TEST(TriangleEdgeTEST, OutOfRangeEDTest) {
	//negative values or zero values
	ASSERT_FALSE(isTriangleCheck(201, 150, 150)) << "sideA is out of range\n";
	ASSERT_FALSE(isTriangleCheck(150, 201, 150)) << "sideB is out of range\n";
	ASSERT_FALSE(isTriangleCheck(150, 150, 201)) << "sideC is out of range\n";
	ASSERT_FALSE(isTriangleCheck(1050, 150, 201)) << "sideA/C are out of range\n";
	ASSERT_FALSE(isTriangleCheck(1500, 1050, 200)) << "sideA/B are out of range\n";
	ASSERT_FALSE(isTriangleCheck(150, 1500, 201)) << "sideB/C are out of range\n";
	ASSERT_FALSE(isTriangleCheck(1500, 1050, 2000)) << "sideA/B/C are out of range\n";
}
//Decision Table Based



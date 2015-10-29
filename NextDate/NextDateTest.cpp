/*Test code for the NextDate.cpp
 * Name: Shu-Hao Chang (Ken Chang)
 * Student ID: 0456151
 * Date: Oct 29, 2015
 * 
 * 
 * 
 * */
#include "NextDate.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream> //std:ostringstream
//ostringstream output;
//Guide to setup gtest in ubuntu: http://stackoverflow.com/questions/18908923/unit-test-using-gtest-1-6-how-to-check-what-is-printed-out


//Boundary Value Test: go through various of normal boundary value test cases (chapter 5 slide 19)
//and some extreme test cases
TEST(NextDateBoundaryTEST, UpperBoundaryTest) {
	//int monthHandle(int day, int month, int year)
	EXPECT_EQ(30, dayHandle(29, 10, 2015));
	EXPECT_EQ(10, monthHandle(29, 10, 2015));
	EXPECT_EQ(2015, yearHandle(29, 10, 2015));
	
	EXPECT_EQ(1, dayHandle(30, 4, 2015));
	EXPECT_EQ(5, monthHandle(30, 4, 2015));
	EXPECT_EQ(2015, yearHandle(30, 4, 2015));
	
	EXPECT_EQ(1, dayHandle(31, 12, 2015));
	EXPECT_EQ(1, monthHandle(31, 12, 2015));
	EXPECT_EQ(2016, yearHandle(31, 12, 2015));
	
	EXPECT_EQ(-1, dayHandle(29, 2, 2015));
	EXPECT_EQ(-1, monthHandle(29, 2, 2015));
	EXPECT_EQ(-1, yearHandle(29, 2, 2015));
}

TEST(NextDateBoundaryTEST, ZeroValueBoundaryTest) {
	EXPECT_EQ(-1, dayHandle(0, 10, 2015));
	EXPECT_EQ(-1, monthHandle(0, 10, 2015));
	EXPECT_EQ(-1, yearHandle(0, 10, 2015));
	
	EXPECT_NE(1, dayHandle(-1, 4, 2015));
	EXPECT_NE(5, monthHandle(-1, 4, 2015));
	EXPECT_NE(2015, yearHandle(-1, 4, 2015));
	
	EXPECT_EQ(1, dayHandle(31, 12, 0));
	EXPECT_EQ(1, monthHandle(31, 12, 0));
	EXPECT_EQ(1, yearHandle(31, 12, 0));
	
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
}



//Equivalence Class Testing: test one case per class
TEST(NextDateEQTEST, NegAndZeroValueEqTest) {
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
	
	EXPECT_EQ(-1, dayHandle(-1, 1, 1));
	EXPECT_EQ(-1, monthHandle(-1, 1, 1));
	EXPECT_EQ(-1, yearHandle(-1, 1, 1));
	
	EXPECT_EQ(-1, dayHandle(1, -1, 1));
	EXPECT_EQ(-1, monthHandle(1, -1, 1));
	EXPECT_EQ(-1, yearHandle(1, -1, 1));
	
	EXPECT_EQ(-1, dayHandle(1, 1, -1));
	EXPECT_EQ(-1, monthHandle(1, 1, -1));
	EXPECT_EQ(-1, yearHandle(1, 1, -1));
	
	EXPECT_EQ(-1, dayHandle(-1, -1, 1));
	EXPECT_EQ(-1, monthHandle(-1, -1, 1));
	EXPECT_EQ(-1, yearHandle(-1, -1, 1));
	
	EXPECT_EQ(-1, dayHandle(-1, 1, -1));
	EXPECT_EQ(-1, monthHandle(-1, 1, -1));
	EXPECT_EQ(-1, yearHandle(-1, 1, -1));
	
	EXPECT_EQ(-1, dayHandle(1, -1, -1));
	EXPECT_EQ(-1, monthHandle(1, -1, -1));
	EXPECT_EQ(-1, yearHandle(1, -1, -1));
	
	EXPECT_EQ(-1, dayHandle(-1, -1, -1));
	EXPECT_EQ(-1, monthHandle(-1, -1, -1));
	EXPECT_EQ(-1, yearHandle(-1, -1, -1));
}

TEST(NextDateEQTEST, MonthEqTest) {
	//int monthHandle(int day, int month, int year)
	//regular case
	EXPECT_EQ(15, dayHandle(14, 6, 2000));
	EXPECT_EQ(6, monthHandle(14, 6, 2000));
	EXPECT_EQ(2000, yearHandle(14, 6, 2000));
	
	//change year
	EXPECT_EQ(1, dayHandle(31, 12, 0));
	EXPECT_EQ(1, monthHandle(31, 12, 0));
	EXPECT_EQ(1, yearHandle(31, 12, 0));
	
	
	//invalid input
	EXPECT_EQ(-1, dayHandle(0, 2, 2000));
	EXPECT_EQ(-1, monthHandle(0, 2, 2000));
	EXPECT_EQ(-1, yearHandle(0, 2, 2000));
	
	EXPECT_EQ(-1, dayHandle(27, 13, 2000));
	EXPECT_EQ(-1, monthHandle(27, 13, 2000));
	EXPECT_EQ(-1, yearHandle(27, 13, 2000));
	
	EXPECT_EQ(-1, dayHandle(27, 12, -1));
	EXPECT_EQ(-1, monthHandle(27, 12, -1));
	EXPECT_EQ(-1, yearHandle(27, 12, -1));
	
	EXPECT_EQ(-1, dayHandle(35, 12, 0));
	EXPECT_EQ(-1, monthHandle(35, 12, 0));
	EXPECT_EQ(-1, yearHandle(35, 12, 0));
}

TEST(NextDateEQTEST, LeapYearEqTest) {
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
}

TEST(NextDateEQTEST, MonthLimitEqTest) {
	EXPECT_EQ(30, dayHandle(29, 7, 2000));
	EXPECT_EQ(7, monthHandle(29, 7, 2000));
	EXPECT_EQ(2000, yearHandle(29, 7, 2000));
	
	EXPECT_EQ(31, dayHandle(30, 7, 2000));
	EXPECT_EQ(7, monthHandle(30, 7, 2000));
	EXPECT_EQ(2000, yearHandle(30, 7, 2000));
}
/*Edge Value: hybrid of Eq. class and boundary testing
 * */
 
TEST(NextDateEQTEST, NegAndZeroValueEDTest) {
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
	
	EXPECT_EQ(-1, dayHandle(-1, 1, 1));
	EXPECT_EQ(-1, monthHandle(-1, 1, 1));
	EXPECT_EQ(-1, yearHandle(-1, 1, 1));
	
	EXPECT_EQ(-1, dayHandle(1, -1, 1));
	EXPECT_EQ(-1, monthHandle(1, -1, 1));
	EXPECT_EQ(-1, yearHandle(1, -1, 1));
	
	EXPECT_EQ(-1, dayHandle(1, 1, -1));
	EXPECT_EQ(-1, monthHandle(1, 1, -1));
	EXPECT_EQ(-1, yearHandle(1, 1, -1));
	
	EXPECT_EQ(-1, dayHandle(-1, -1, 1));
	EXPECT_EQ(-1, monthHandle(-1, -1, 1));
	EXPECT_EQ(-1, yearHandle(-1, -1, 1));
	
	EXPECT_EQ(-1, dayHandle(-1, 1, -1));
	EXPECT_EQ(-1, monthHandle(-1, 1, -1));
	EXPECT_EQ(-1, yearHandle(-1, 1, -1));
	
	EXPECT_EQ(-1, dayHandle(1, -1, -1));
	EXPECT_EQ(-1, monthHandle(1, -1, -1));
	EXPECT_EQ(-1, yearHandle(1, -1, -1));
	
	EXPECT_EQ(-1, dayHandle(-1, -1, -1));
	EXPECT_EQ(-1, monthHandle(-1, -1, -1));
	EXPECT_EQ(-1, yearHandle(-1, -1, -1));
	
	EXPECT_EQ(-1, dayHandle(-1, -2, -1));
	EXPECT_EQ(-1, monthHandle(-1, -2, -1));
	EXPECT_EQ(-1, yearHandle(-1, -2, -1));
	
	EXPECT_EQ(-1, dayHandle(-1, -2, -50));
	EXPECT_EQ(-1, monthHandle(-1, -2, -50));
	EXPECT_EQ(-1, yearHandle(-1, -2, -50));
	
	EXPECT_EQ(-1, dayHandle(0, 10, 2015));
	EXPECT_EQ(-1, monthHandle(0, 10, 2015));
	EXPECT_EQ(-1, yearHandle(0, 10, 2015));
	
	EXPECT_NE(1, dayHandle(-1, 4, 2015));
	EXPECT_NE(5, monthHandle(-1, 4, 2015));
	EXPECT_NE(2015, yearHandle(-1, 4, 2015));
	
	EXPECT_EQ(1, dayHandle(31, 12, 0));
	EXPECT_EQ(1, monthHandle(31, 12, 0));
	EXPECT_EQ(1, yearHandle(31, 12, 0));
	
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
}

TEST(NextDateEQTEST, MonthEDTest) {
	//int monthHandle(int day, int month, int year)
	//regular case
	EXPECT_EQ(15, dayHandle(14, 6, 2000));
	EXPECT_EQ(6, monthHandle(14, 6, 2000));
	EXPECT_EQ(2000, yearHandle(14, 6, 2000));
	
	//change year
	EXPECT_EQ(1, dayHandle(31, 12, 0));
	EXPECT_EQ(1, monthHandle(31, 12, 0));
	EXPECT_EQ(1, yearHandle(31, 12, 0));
	
	
	//invalid input
	EXPECT_EQ(-1, dayHandle(0, 2, 2000));
	EXPECT_EQ(-1, monthHandle(0, 2, 2000));
	EXPECT_EQ(-1, yearHandle(0, 2, 2000));
	
	EXPECT_EQ(-1, dayHandle(27, 13, 2000));
	EXPECT_EQ(-1, monthHandle(27, 13, 2000));
	EXPECT_EQ(-1, yearHandle(27, 13, 2000));
	
	EXPECT_EQ(-1, dayHandle(27, 12, -1));
	EXPECT_EQ(-1, monthHandle(27, 12, -1));
	EXPECT_EQ(-1, yearHandle(27, 12, -1));
	
	EXPECT_EQ(-1, dayHandle(35, 12, 0));
	EXPECT_EQ(-1, monthHandle(35, 12, 0));
	EXPECT_EQ(-1, yearHandle(35, 12, 0));
}

TEST(NextDateEQTEST, LeapYearEDTest) {
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
}

TEST(NextDateEQTEST, MonthLimitEDTest) {
	//Change of month test
	EXPECT_EQ(30, dayHandle(29, 10, 2015));
	EXPECT_EQ(10, monthHandle(29, 10, 2015));
	EXPECT_EQ(2015, yearHandle(29, 10, 2015));
	
	EXPECT_EQ(1, dayHandle(30, 4, 2015));
	EXPECT_EQ(5, monthHandle(30, 4, 2015));
	EXPECT_EQ(2015, yearHandle(30, 4, 2015));
	
	EXPECT_EQ(1, dayHandle(31, 12, 2015));
	EXPECT_EQ(1, monthHandle(31, 12, 2015));
	EXPECT_EQ(2016, yearHandle(31, 12, 2015));
	
	EXPECT_EQ(-1, dayHandle(29, 2, 2015));
	EXPECT_EQ(-1, monthHandle(29, 2, 2015));
	EXPECT_EQ(-1, yearHandle(29, 2, 2015));
	
	EXPECT_EQ(30, dayHandle(29, 7, 2000));
	EXPECT_EQ(7, monthHandle(29, 7, 2000));
	EXPECT_EQ(2000, yearHandle(29, 7, 2000));
	
	EXPECT_EQ(31, dayHandle(30, 7, 2000));
	EXPECT_EQ(7, monthHandle(30, 7, 2000));
	EXPECT_EQ(2000, yearHandle(30, 7, 2000));
}

/*Decision Table Based
 * based on slide 31 chap 07
*/
TEST(NextDateDecisionTEST, DecisionTest) {
	//Change of month test
	EXPECT_EQ(16, dayHandle(15, 4, 2001));
	EXPECT_EQ(4, monthHandle(15, 4, 2001));
	EXPECT_EQ(2001, yearHandle(15, 4, 2001));
	
	EXPECT_EQ(1, dayHandle(30, 4, 2015));
	EXPECT_EQ(5, monthHandle(30, 4, 2015));
	EXPECT_EQ(2015, yearHandle(30, 4, 2015));
	
	EXPECT_EQ(16, dayHandle(15, 1, 2001));
	EXPECT_EQ(1, monthHandle(15, 1, 2001));
	EXPECT_EQ(2001, yearHandle(15, 1, 2001));
	
	EXPECT_EQ(1, dayHandle(31, 1, 2001));
	EXPECT_EQ(2, monthHandle(31, 1, 2001));
	EXPECT_EQ(2001, yearHandle(31, 1, 2001));
	
	EXPECT_EQ(16, dayHandle(15, 12, 2001));
	EXPECT_EQ(12, monthHandle(15, 12, 2001));
	EXPECT_EQ(2001, yearHandle(15, 12, 2001));
	
	EXPECT_EQ(1, dayHandle(31, 12, 2015));
	EXPECT_EQ(1, monthHandle(31, 12, 2015));
	EXPECT_EQ(2016, yearHandle(31, 12, 2015));
	
	EXPECT_EQ(16, dayHandle(15, 2, 2001));
	EXPECT_EQ(2, monthHandle(15, 2, 2001));
	EXPECT_EQ(2001, yearHandle(15, 2, 2001));
	
	EXPECT_EQ(29, dayHandle(28, 2, 2004));
	EXPECT_EQ(2, monthHandle(28, 2, 2004));
	EXPECT_EQ(2004, yearHandle(28, 2, 2004));
	
	EXPECT_EQ(1, dayHandle(28, 2, 2001));
	EXPECT_EQ(3, monthHandle(28, 2, 2001));
	EXPECT_EQ(2001, yearHandle(28, 2, 2001));
	
	EXPECT_EQ(1, dayHandle(28, 2, 2015));
	EXPECT_EQ(3, monthHandle(28, 2, 2015));
	EXPECT_EQ(2015, yearHandle(28, 2, 2015));
	
	EXPECT_EQ(1, dayHandle(29, 2, 2004));
	EXPECT_EQ(3, monthHandle(29, 2, 2004));
	EXPECT_EQ(2004, yearHandle(29, 2, 2004));

	EXPECT_EQ(-1, dayHandle(30, 2, 2001));
	EXPECT_EQ(-1, monthHandle(30, 2, 2001));
	EXPECT_EQ(-1, yearHandle(30, 2, 2001));

	EXPECT_EQ(-1, dayHandle(29, 2, 2015));
	EXPECT_EQ(-1, monthHandle(29, 2, 2015));
	EXPECT_EQ(-1, yearHandle(29, 2, 2015));
	
}

TEST(NextDateDecisionTEST, FailedCaseTest) {
	EXPECT_EQ(-1, dayHandle(0, 0, 0));
	EXPECT_EQ(-1, monthHandle(0, 0, 0));
	EXPECT_EQ(-1, yearHandle(0, 0, 0));
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

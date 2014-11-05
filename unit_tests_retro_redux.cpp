// unit_tests_retro_redux.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

//include headers to test
#include "utility.h"

using namespace std;

//Tests
TEST(Utility, DegToRad)
{
	//45 degrees .7853975 rads
	EXPECT_NEAR(.7853975, Helper::DegreeToRadians(45), .001);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//method initialises google framework and must be called BEFORE RUN_ALL_TESTS
	::testing::InitGoogleTest(&argc, argv);

	/*RUN_ALL_TESTS autmatically detects and runs all the tests definexd usijng the TEST macro.
	It must be called only once in the code because multiple calls lead to conflicts and are not zsupported.
	*/
	int returnCode = RUN_ALL_TESTS();
	system("pause");
	return returnCode;
}


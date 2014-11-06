#ifndef _TEST_UTILITY_H_
#define _TEST_UTILITY_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

//code under test
#include "utility.h"

TEST(Utility, DegToRad)
{
	//45 degrees .7853975 rads
	EXPECT_NEAR(.7853975, Helper::DegreeToRadians(45), .001);

}

//TODO: get tests already written that weren't pushed to github

#endif
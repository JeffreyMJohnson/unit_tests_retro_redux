#ifndef _TEST_MATRIX_3_H_
#define _TEST_MATRIX_3_H_
/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "TheMath.h"

TEST(matrix3, constructorDefault)
{
	Matrix3 m;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			EXPECT_FLOAT_EQ(0, m.matrix[row][col]);
		}
	}
}


TEST(matrix3, constructor)
{
	Matrix3 m(
		10.0f, 11.0f, 12.0f,
		20.0f, 21.0f, 22.0f,
		30.0f, 31.0f, 32.0f);

	EXPECT_FLOAT_EQ(10, m.matrix[0][0]);
	EXPECT_FLOAT_EQ(11, m.matrix[0][1]);
	EXPECT_FLOAT_EQ(12, m.matrix[0][2]);
	EXPECT_FLOAT_EQ(20, m.matrix[1][0]);
	EXPECT_FLOAT_EQ(21, m.matrix[1][1]);
	EXPECT_FLOAT_EQ(22, m.matrix[1][2]);
	EXPECT_FLOAT_EQ(30, m.matrix[2][0]);
	EXPECT_FLOAT_EQ(31, m.matrix[2][1]);
	EXPECT_FLOAT_EQ(32, m.matrix[2][2]);

}

TEST(matrix3, equality)
{
	Matrix3 m1(
		2, 3, 4,
		2, 3, 4,
		2, 3, 4);

	Matrix3 m2(
		2, 3, 4,
		2, 3, 4,
		2, 3, 4);

	Matrix3 m3(
		1, 3, 4,
		2, 3, 4,
		2, 3, 4);

	EXPECT_TRUE(m1 == m2);
	EXPECT_TRUE(m1 == m1);
	EXPECT_FALSE(m1 == m3);

}



#endif

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
		10, 11, 12,
		20, 21, 22,
		30, 31, 32);

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

TEST(matrix3, assignmentOperator)
{
	Matrix3 m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3 m2;
	Matrix3 m3;
	m3 = m2 = m1;

	EXPECT_TRUE(m1 == m2);
	EXPECT_TRUE(m1 == m3);

}

TEST(matrix3, identity)
{
	Matrix3 expect(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	EXPECT_TRUE(expect == Matrix3::Identity());
}

TEST(matrix3, additionAssignemntOperator)
{
	Matrix3 m1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3 m2(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1);
	Matrix3 expect(
		10, 10, 10,
		10, 10, 10,
		10, 10, 10);
	EXPECT_TRUE(expect == (m1 += m2));
	EXPECT_TRUE(m2 ==
		Matrix3(
		9, 8, 7,
		6, 5, 4,
		3, 2, 1));
}


#endif

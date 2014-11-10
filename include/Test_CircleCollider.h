#ifndef _TEST_CIRCLE_COLLIDER_H_
#define _TEST_CIRCLE_COLLIDER_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

#include "CircleCollider.h"

TEST(circleCollider, constructor)
{
	CircleCollider c1;
	EXPECT_FLOAT_EQ(0, c1.radius) << c1;
	EXPECT_TRUE(Vector2() == c1.center) << c1;

	CircleCollider c2(23.5, Vector2(30, 100));
	EXPECT_FLOAT_EQ(23.5, c2.radius);
	EXPECT_TRUE(c2.center == Vector2(30, 100));
}

TEST(circleCollider, isCollided)
{
	CircleCollider c1(1, Vector2());
	CircleCollider is(1, Vector2(1,1));
	CircleCollider isNot(1, Vector2(11, 11));

	EXPECT_TRUE(c1.isCollided(is));
	EXPECT_FALSE(c1.isCollided(isNot)) << c1;
}
#endif
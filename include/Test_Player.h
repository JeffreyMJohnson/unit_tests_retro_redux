#ifndef _TEST_PLAYER_H_
#define _TEST_PLAYER_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

//code under test
#include "Player.h"

TEST(player, constructor)
{
	Player p("foo", 10, 10, true);

	EXPECT_FLOAT_EQ(10, p.width) << p;
	EXPECT_FLOAT_EQ(10, p.height) << p;

	EXPECT_EQ(100, p.spriteID_A) << p;
	EXPECT_EQ(101, p.spriteID_B) << p;
	EXPECT_EQ(100, p.spriteID) << p;
}

TEST(player, init)
{
	Player p("foo", 10, 10, true);
	Vector2 pos(100, 100);
	Vector2 vel(1, 0);
	float radius = 10;
	int health = 25;
	p.Init(pos, vel, radius, health);

	EXPECT_TRUE(pos == p.position) << p;
	EXPECT_TRUE(vel == p.velocity);
	EXPECT_FLOAT_EQ(50.0f, p.speed);
	EXPECT_FLOAT_EQ(radius, p.collider.radius);
	EXPECT_EQ(health, p.health);
}

TEST(player, inputLeft)
{
	Player p("foo", 10, 10, true);
	Vector2 pos(100, 100);
	Vector2 vel(0, 0);
	float radius = 10;
	int health = 25;
	p.Init(pos, vel, radius, health);

	//left key down with position.x > 0;
	p.Input(true, false, false, false);

	EXPECT_TRUE(Vector2(-1, 0) == p.velocity);

	p.Input(true, false, true, true);

	EXPECT_TRUE(Vector2(-1, 0) == p.velocity);

	p.Input(false, false, false, false);

	EXPECT_TRUE(vel == p.velocity);

	p.position = Vector2(-.2, 100);
	p.Input(true, false, false, false);

	EXPECT_TRUE(Vector2(0,100) == p.position);
	EXPECT_TRUE(vel == p.velocity);
}

TEST(player, inputRight)
{
	Player p("foo", 10, 10, true);
	Vector2 pos(100, 100);
	Vector2 vel(0, 0);
	float radius = 10;
	int health = 25;
	p.Init(pos, vel, radius, health);

	//right key down with position.x < screenwidth;
	p.Input(false, true, false, false);

	EXPECT_TRUE(Vector2(1, 0) == p.velocity);

	p.Input(false, true, false, true);

	EXPECT_TRUE(Vector2(1, 0) == p.velocity);

	p.Input(false, false, false, false);

	EXPECT_TRUE(vel == p.velocity);

	p.position = Vector2(screenWidth + .001, 100);
	p.Input(false, true, false, false);

	EXPECT_TRUE(Vector2(screenWidth - (p.height * .5), 100) == p.position);
	EXPECT_TRUE(vel == p.velocity);
}



#endif
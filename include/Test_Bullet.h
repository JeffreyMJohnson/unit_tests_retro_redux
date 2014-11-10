#ifndef _TEST_BULLET_H_
#define _TEST_BULLET_H_

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

//code under test
#include "Bullet.h"

TEST(bullet, constructor)
{
	Bullet b("foo", 10, 10, true);
	EXPECT_EQ(10, b.width);
	EXPECT_EQ(10, b.height);
	EXPECT_EQ(100, b.spriteID);
	EXPECT_FALSE(b.alive);
}

TEST(bullet, init)
{
	Bullet b("foo", 10, 10, true);
	b.Init(Vector2(10, 10), Vector2(1, 1), 100, 15, 25);

	EXPECT_TRUE(Vector2(10, 10) == b.position);
	EXPECT_TRUE(Vector2(1, 1) == b.velocity);
	EXPECT_FLOAT_EQ(100, b.speed);
	EXPECT_FLOAT_EQ(15, b.collider.radius);
	EXPECT_EQ(25, b.health);
}

TEST(bullet, spawn)
{
	Bullet b("foo", 10, 10, true);
	b.Init(Vector2(10, 10), Vector2(1, 1), 100, 15, 25);

	b.Spawn(Vector2(100, 100), Vector2(0, 1), 50.0f, 50);

	Vector2 expect(100, 100);
	EXPECT_TRUE(expect == b.position) << "expect: " << expect << "\nresult: " << b.position;
	expect = Vector2(0, 1);
	EXPECT_TRUE(expect == b.velocity) << "expect: " << expect << "\nresult: " << b.velocity;
	EXPECT_FLOAT_EQ(50.0f, b.speed);
	EXPECT_EQ(50, b.health);

}

TEST(bullet, update)
{
	float delta = 1.0f;
	Vector2 pos(100, 100);
	Vector2 vel(0, 1);
	float speed = 100;
	int health = 1;

	Bullet b("foo", 10, 10, true);
	b.Init(pos, vel, speed, 15, health);

	b.Spawn(pos,vel, speed, health);

	//call function under test testHook overload
	b.Update(delta, true);

	Vector2 expect(pos + vel * speed * delta);
	EXPECT_TRUE(expect == b.position) << "expect: " << expect << "\nresult: " << b.position;
	EXPECT_TRUE(expect == b.collider.center) << "expect: " << expect << "\nresult: " << b.collider.center;
	EXPECT_TRUE(b.alive);

	delta = 10.0f;
	b.Update(delta, true);
	EXPECT_FALSE(b.alive)  << b;

}


#endif
// unit_tests_retro_redux.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*
header file defines public API for Google test, needs to be included for any test program that uses it.
*/
#include "gtest/gtest.h"

//include test code from headers
#include "include\Test_JMath.h"
#include "include\Test_Vector2.h"
#include "include\Test_Vector3.h"
#include "include\Test_Matrix3.h"

#include "Test_CircleCollider.h"
#include "include\Test_Bullet.h"
#include "include\Test_Player.h"

//HACK:: 
extern const int screenWidth = 600;
extern const int screenHeight = 800;
extern const int NUM_ENEMYS = 36;
extern const int NUM_ENEMY_COLS = 9;
extern const int NUM_ENEMY_ROWS = 4;


int _tmain(int argc, _TCHAR* argv[])
{
	//method initializes Google framework and must be called BEFORE RUN_ALL_TESTS
	::testing::InitGoogleTest(&argc, argv);

	/*RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.
	It must be called only once in the code because multiple calls lead to conflicts and are not supported.
	*/
	return RUN_ALL_TESTS();
}


#pragma once 
#include "Includes.h"
using namespace std;

struct Mouse {
	static void MoverPOINTandPress(POINT Points);

	static void MoverPOINTandPressTwoTimes(POINT Points); 

	static void MouseMoveAtoB(POINT PointA, POINT PointB); 
};

struct Keyboard {
	static void KeyboardInput(int keyforInput);

	static void KeyboardInput_MovAndPress(int keyforInput, POINT Points);
};
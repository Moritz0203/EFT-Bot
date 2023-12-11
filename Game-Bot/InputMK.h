#pragma once 
#include "Includes.h"
using namespace std;

struct Mouse {
	static void MoverPOINTandPress(POINT Points);

	static void MoverPOINTandPressTwoTimes(POINT Points); 

	static void MouseMoveAtoB(POINT PointA, POINT PointB); 

	static void MouseMove(POINT Point);

	static void ClickLeftButton();
};

struct Keyboard {
	static void KeyboardInput(int keyforInput);
	static void KeyboardHoldFirstAndPressSecond(int keyforInput, int keyforInput2);
	static void KeyboardTypeString(const char* string);
};

struct MouseAndKeyboard {
	static void KeyboardInput_MovAndPress(int keyforInput, POINT Points);
};
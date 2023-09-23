#include "InputMK.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

void Mouse::MoverPOINTandPress(POINT Points)
{
	SetCursorPos(Points.x, Points.y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void Mouse::MoverPOINTandPressTwoTimes(POINT Points)
{
	SetCursorPos(Points.x, Points.y);
	Sleep(8);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(1);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(1);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	//cout << "MouseMovPressTwoTimes" << endl;
}

void Mouse::MouseMoveAtoB(POINT PointA, POINT PointB)
{
	SetCursorPos(PointA.x, PointA.y);
	Sleep(1);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(17);//17
	SetCursorPos(PointB.x, PointB.y);
	Sleep(20);//20
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	//cout << "MouseMoveAtoB" << endl;
}

void Keyboard::KeyboardInput(int keyforInput)
{
	INPUT ip{};
	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	// Press the key
	ip.ki.wVk = keyforInput;
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
}

void MouseAndKeyboard::KeyboardInput_MovAndPress(int keyforInput, POINT Point)
{
	INPUT ip{};
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press and hold the key
    ip.ki.wVk = keyforInput;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

	Sleep(20);

    SetCursorPos(Point.x, Point.y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	Sleep(20);


    // Release the key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}


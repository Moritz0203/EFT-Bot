#include "InputMK.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <random>
#include <ctime>

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


void Mouse::MouseMove(POINT Point) {
	SetCursorPos(Point.x, Point.y);
}

void Mouse::ClickLeftButton() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
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

void Keyboard::KeyboardHoldFirstAndPressSecond(int keyforInput, int keyforInput2) {

	INPUT ip{};
	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	INPUT ip2{};
	// Set up a generic keyboard event.
	ip2.type = INPUT_KEYBOARD;
	ip2.ki.wScan = 0; // hardware scan code for key
	ip2.ki.time = 0;
	ip2.ki.dwExtraInfo = 0;

	// Hold the key
	ip.ki.wVk = keyforInput;
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));


		// Press the key
		ip2.ki.wVk = keyforInput2;
		ip2.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip2, sizeof(INPUT));

		// Release the key
		ip2.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		SendInput(1, &ip2, sizeof(INPUT));


	// Release the key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));
}

void Keyboard::KeyboardTypeString(const char* string) {

	if (OpenClipboard(NULL)) {
		EmptyClipboard();
		HGLOBAL hGlob = GlobalAlloc(GMEM_MOVEABLE, strlen(string) + 1);
		if (hGlob) {
			char* pData = (char*)GlobalLock(hGlob);
			
			if (!pData) {
				return;
			}
			else {
				strcpy_s(pData, strlen(string) + 1, string);
				GlobalUnlock(hGlob);
				SetClipboardData(CF_TEXT, hGlob);
			}
		}
		CloseClipboard();
	}

	KeyboardHoldFirstAndPressSecond(0x11, 0x56);//virtual - key code for the "CTRL" key and "V" key
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
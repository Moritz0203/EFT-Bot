#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

namespace Mouse {
	bool Mover(vector<POINT> &Points) {
		/*char Pressdkey = _getch();*/
		for (int i = 0; i < Points.size(); i++) {
			Sleep(800);
			cout << Points[i].y << " " << Points[i].x << endl;
			SetCursorPos(Points[i].x, Points[i].y);
		}
		return true;
	}

	void MoverPOINTandPress(POINT Points) {
		SetCursorPos(Points.x, Points.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		cout << "MouseMovPress" << endl;

		return;
	}
	void MoverPOINTandPressTwoTimes(POINT Points) {
		SetCursorPos(Points.x, Points.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		cout << "MouseMovPressTwoTimes" << endl;

		return;
	}
	void MouseMoveAtoB(POINT PointA, POINT PointB) {
		SetCursorPos(PointA.x, PointA.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		SetCursorPos(PointB.x, PointB.y);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		cout << "MouseMoveAtoB" << endl;

		return;
	}
}

namespace Keyboard {
	bool KeyboardInput(float keyforInput) {
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


		return true;
	}
}
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

	bool MoverPOINT(POINT Points) {
		SetCursorPos(Points.x, Points.y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		cout << "MouseMov" << endl;

		return true;
	}
}

namespace Keyboard {
	
}
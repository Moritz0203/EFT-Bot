#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

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
}

namespace Keyboard {
	
}
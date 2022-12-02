#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "InputMT.h"
#include "DistributorForMatching.h"
using namespace std;
using namespace cv;




namespace StartUp {
	bool CheckForFails();
	
	void Entrance() {
		while (CheckForFails() == false)
		{
			POINT point = {};
			point.y = 729;
			point.x = 961;
			Mouse::MoverPOINT(point); //729 961
			cout << "ok" << endl;
		}
		
	}


	bool CheckForFails() {
		HWND hWND = FindeWindow();
		if (!hWND) {
			SetForegroundWindow(hWND);
			Mat MatScreen = getMat(hWND);
			if (!MatScreen.empty()) {
				Mat templ = imread("ObjectImages/Banner.png");
				if (!templ.empty()) {
					POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.98);
					if (point.y || point.x != 0)
						return true;
				}
					
			}
		}
		return false;
	}
}



#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "getMat.h"
#include "InputMK.h"
#include "DistributorForMatching.h"
using namespace std;
using namespace cv;



namespace StartUp {
	void CheckForFails();
	void CheckScrollbarPositions();
	array<Mat, 11> TakeScreenshots();

	void Entrance() {
		CheckForFails();
		CheckScrollbarPositions();		
	}

	void CheckForFails() {
		Mat MatScreen;
		Mat templ;
		POINT pointMouse = {};
		pointMouse.y = 729;
		pointMouse.x = 961;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);

		templ = imread("ObjectImages/Banner.png");
		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.98);
		if (point.y || point.x != 0)
			Mouse::MoverPOINTandPress(pointMouse); //729 961
	}

	void CheckScrollbarPositions() {
		Mat MatScreen;
		Mat templ;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);

		templ = imread("ObjectImages/scrollbar.png");
		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
		if (point.y > 79) {// Later with screen resolution
			point.y = (templ.rows / 2) + point.y;
			point.x = (templ.cols / 2) + point.x;
			Mouse::MoverPOINTandPress(point);
			int keyforInput = 0x21;// virtual-key code for the "PAGE UP KEY" key
			Keyboard::KeyboardInput(keyforInput);
		}

		POINT pointBarClick{};
		pointBarClick.y = 171;
		pointBarClick.x = 1903;
		Mouse::MoverPOINTandPress(pointBarClick);
	}

	array<Mat, 11> TakeScreenshots() {
		Mat MatScreen;
		array<Mat, 11> ReturnMatScreen;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later

		POINT point{};
		point.y = 171;
		point.x = 1903;
		Mouse::MoverPOINTandPress(point);

		int size = sizeof(ReturnMatScreen) / sizeof(Mat);
		for (int i = 0; i < size; i++) {
			Sleep(500);
			ReturnMatScreen[i] = getMat(hWND);
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
		}

		return ReturnMatScreen;
	}
}
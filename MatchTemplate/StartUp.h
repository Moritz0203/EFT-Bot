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
		
		CheckForFails();
		
		
		
	}


	bool CheckForFails() {
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
			Mouse::MoverPOINT(pointMouse); //729 961
		else
			return true;
	}
}



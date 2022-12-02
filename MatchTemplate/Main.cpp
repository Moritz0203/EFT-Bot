#include "getMat.h"
#include "StartUp.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

//external controllers for applications / ECFA
void startFunktion(vector<POINT> &Returner, Mat MatScreen);


int main() {

	vector<POINT> Returner;
	
	
	HWND hWND = FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(100);
	Mat MatScreen = getMat(hWND);
	

	string Start;
	cin >> Start;

	if (Start == "start") {
		startFunktion(Returner, MatScreen);
	}
	else if (Start == "test") {
		
		
		
		StartUp::Entrance();
		
		
		
		
		//const char* image_window = "Source Image";
		//namedWindow(image_window, WINDOW_AUTOSIZE);
		//Mat templ = imread("ObjectImages/press.png");

		//int width = templ.cols / 2;
		//int height = templ.rows / 2;
	
		//POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.98);

		//cout << point.y + height << " " << point.x + width << endl;

		//point.y = height + point.y;
		//point.x = width + point.x;

		//Mouse::MoverPOINT(point);
		///*Mat img_display;
		//img.copyTo(img_display);
		//imshow(image_window, img);
		//waitKey(0);*/


	}

	//for (int i = 0; i < Returner.size(); i++) {
	//		cout << Returner[i].y << " " << Returner[i].x << endl;
	//}
}

void startFunktion(vector<POINT> &Returner, Mat MatScreen) {
	Returner = Matching::AmmunitionMatching(MatScreen);
}
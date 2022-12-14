#include "getMat.h"
#include "StartUp.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

//external controllers for applications / ECFA
//Rick and Morty Staffel 4 - Folge 4
void startFunktion(vector<POINT>& Returner, Mat MatScreen);


int main() {
	vector<POINT> Returner;
	
	
	HWND hWND = FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(100);
	Mat MatScreen = getMat(hWND);
	

	string Start;
	cin >> Start;

	if (Start == "start") {
		/*startFunktion(Returner, MatScreen);*/
		StartUp::Entrance();
	}
	if (Start == "test") {
		
		/*const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);*/
		Mat templ = imread("ObjectImages/Intel.png");

		/*int width = templ.cols / 2;
		int height = templ.rows / 2;*/
		
		TemplateMatching::templateMatchingItems( "ObjectImages/THICCcase.png", 0.90, false, false, "Intel", Returner, MatScreen);   // 807  464  122    div1  343  div2  342     1Solt

																																	// 814  471  128    div1  343  div2  343     1Slot
																																	
																																	// 500  157         div1  343                2Solt

																																	// 535  192         div1  343                3Slot
		/*cout << point.y + height << " " << point.x + width << endl;*/

		/*point.y = height + point.y;
		point.x = width + point.x;*/

		
		/*Mat img_display;
		img.copyTo(img_display);
		imshow(image_window, img);
		waitKey(0);*/


	}

	for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}
}

void startFunktion(vector<POINT> &Returner, Mat MatScreen) {
	Returner = Matching::AmmunitionMatching(MatScreen);
}

	


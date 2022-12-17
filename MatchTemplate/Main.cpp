#include "CaseMatching.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

//external controllers for applications / ECFA
//Rick and Morty Staffel 4 - Folge 4



int main() {
	vector<POINT> Returner;
	
	
	HWND hWND = FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(100);
	Mat MatScreen = getMat(hWND);
	

	string Start;
	cin >> Start;

	if (Start == "start") {
		StartUp::Entrance();
	}
	if (Start == "test") {
		Mat templ;
		Color color;
		
		vector<POINT> ReturnPoints;
		templ = imread("ObjectImages/THICCcase.png");
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);

		TemplateMatching::templateMatchingItems("ObjectImages/THICCcase.png", 0.91, false, false, "thicc", ReturnPoints, MatScreen);
		
		cout << "------" << endl;
		
		Rect Rec(ReturnPoints[0].x, ReturnPoints[0].y, templ.cols, templ.rows);

		Mat Roi = MatScreen(Rec);
		imshow(image_window, Roi);
		waitKey(0);

		color = TemplateMatching::ColorMatching(Rec, MatScreen);
		
		
		cout << color << " " << "color" << endl;





		/*CaseMatching::THICCcase();*/
	}
	else if (Start == "2test") {
	}

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/
}



	


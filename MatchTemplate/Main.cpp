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
	/*	Color color;*/
		
		vector<POINT> ReturnPoints;
		templ = imread("itemImages/CaseImages/AmmoCase.png");
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);
		/*const char* image_window2 = "Source Image2222222222";
		namedWindow(image_window2, WINDOW_AUTOSIZE);*/

		TemplateMatching::templateMatchingItems("itemImages/CaseImages/AmmoCase.png", 0.80, false, false, "AmmoCase", ReturnPoints, MatScreen);
		
		cout << "------" << endl;
		
		Rect Rec(ReturnPoints[0].x, ReturnPoints[0].y, templ.cols, templ.rows);

		Mat Roi2;
		Mat Roi = MatScreen(Rec);
		
		/*string str;
		TextMatching::textMatching(MatScreen, Rec, str);
		
		cout << str << endl;*/

		imshow(image_window, Roi);
		/*imshow(image_window2, Roi2);*/
		waitKey(0);
		
		
		
		
		
		/*cv::cvtColor(Roi, Roi, cv::COLOR_BGR2HSV);*/

		//if (!ReturnPoints[0].y <= 500) {
		//	/*Roi2 = Roi + cv::Scalar(-17, -17, -17);*/
		//	Roi2 = Roi + cv::Scalar(-20, -20, -20);
		//	cout << "hey" << endl;
		//}

		//int i{}, i2{}, i3{};
		//while (true)
		//{
		//	i--;
		//	i2--;
		//	i3--;
		//	Roi2 = Roi + cv::Scalar(i, i2, i3);	

		//	color = TemplateMatching::ColorMatching(Rec, Roi2);

		//	system("cls");
		//	cout << color << " " << "color " << i << " " << i2 << " " << i3 <<  endl;
		//	if (color == 4)// Green -34 / Blue -64 / 
		//		break;
		//}


		

	/*	color = TemplateMatching::ColorMatching(Rec, Roi);
		
		
		cout << color << " " << "color" << endl;*/





		/*CaseMatching::THICCcase();*/
	}
	else if (Start == "2test") {
	}

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/
}



	


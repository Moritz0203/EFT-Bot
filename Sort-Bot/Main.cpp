#include "StartUp.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
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
		Mat templ1;
		
		vector<POINT> ReturnPoints;
		vector<POINT> ReturnPoints1;
		templ = imread("itemImages/AmmunitionImages/7.62RUS/PS.png");
		templ1 = imread("CaseImages/AmmoCase.png");
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);
		/*const char* image_window2 = "Source Image2222222222";
		namedWindow(image_window2, WINDOW_AUTOSIZE);*/

		TemplateMatching::templateMatchingItems("itemImages/AmmunitionImages/7.62RUS/PS.png", 0.89, false, true, "BP", ReturnPoints, MatScreen);
		
		TemplateMatching::templateMatchingItems("CaseImages/AmmoCase.png", 0.90, false, false, "amo", ReturnPoints1, MatScreen);

		/*cout << ReturnPoints[0].y << " " << ReturnPoints[0].x << endl;
		cout << ReturnPoints1[0].y << " " << ReturnPoints1[0].x << endl;*/

		POINT pointA{};
		POINT pointB{};

		pointB.y = (templ1.rows / 2) + ReturnPoints1[0].y;
		pointB.x = (templ1.cols / 2) + ReturnPoints1[0].x;

		vector<POINT> neu;
		//for (int i = 0; i < ReturnPoints.size(); i++) {
		//	/*cout << "--1" << endl;*/
		//	bool noture = false;
		//	for (int i2 = 0; i2 < ReturnPoints.size(); i2++) {
		//		/*cout << "--2" << endl;*/

		//		int temp = 0;
		//	
		//		temp = ReturnPoints[i].x;
		//		

		//		temp = temp - 1;
		//	

		//		cout << temp << endl;
		//		
		//		
		//		for (int i3 = 0; i3 < 3; i3++) {
		//			cout << "--3" << endl;
		//			

		//			if (ReturnPoints[i2].x == temp) {
		//				cout << "-- " << ReturnPoints[i2].x << " " << temp << " " << i << "<- i  i2 ->" << i2 << endl;
		//				if (i == i2) {
		//					cout << "true---" << endl;
		//					break;
		//				}
		//				else if (i != i2){
		//					cout << "---true" << endl;
		//					int temp = 0;
		//					temp = i2;
		//					temp - 1;
		//					ReturnPoints.erase(ReturnPoints.begin() + temp);
		//					noture = true;
		//				}
		//			}
		//			temp = temp + 1;
		//		}
		//	}
		//	if(noture)
		//		neu.push_back(ReturnPoints[i]);
		//}



		unordered_set<int> seen;
		vector<POINT> result;
		for (POINT point : ReturnPoints) {
			int x_minus_1 = point.x - 1;
			int x_plus_1 = point.x + 1;
			if (seen.find(point.x) == seen.end() && seen.find(x_minus_1) == seen.end() && seen.find(x_plus_1) == seen.end()) {
				result.push_back(point);
				seen.insert(point.x);
				seen.insert(x_minus_1);
				seen.insert(x_plus_1);
			}
		}


		for (int i = 0; i < result.size(); i++) {
			cout << result[i].y << " " << result[i].x << " ----" << endl;
		}
		/*for (int i = 0; i < ReturnPoints.size(); i++) {
			cout << ReturnPoints[i].y << " " << ReturnPoints[i].x << "----2" << endl;
		}*/


	/*	for (int i = 0; i < ReturnPoints.size(); i++) {
			pointA.y = (templ.rows / 2) + ReturnPoints[i].y;
			pointA.x = (templ.cols / 2) + ReturnPoints[i].x;

			Mouse::MouseMoveAtoB(pointA, pointB);

			Sleep(60);
		}*/
		
		//cout << "------" << endl;
		//
		//Rect Rec(ReturnPoints[0].x + 45, ReturnPoints[0].y + 46, templ.cols - 45, templ.rows - 46);
		////Rect Rec(ReturnPoints[0].x , ReturnPoints[0].y , templ.cols, templ.rows );

		//Mat Roi2;
		//Mat Roi = MatScreen(Rec);
	

		/*Mat temp = imread("ObjectImages/FoundInRaid/FoundInRaid-Blue.png");
		if (TemplateMatching::templateMatchingBool(Roi, temp, 0.99)) {
			cout << "found in raid" << endl;
		}*/

		/*Mat blacktext = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_5.png");

		cv::imshow(image_window, blacktext);

		TextMatching::txttest(blacktext);*/

		/*MatScreen = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_5.png");*/

		/*const string str = TextMatching::textMatching(MatScreen, Rec);

		cout << str << endl;*/


		//const char test = '-';
		///*if (str[9] == test) {
		//	cout << "test" << endl;
		//}*/

		//int i1 = -1;
		//for (int i = 0; i < str.length(); i++) {
		//	i1++;
		//	cout << str[i] << " --- " << i1 << endl;
		//}

		//cout << str[str.back() - 1] << "<------ " << i1 << endl;

		/*cout << "123" << endl;*/
		//imshow(image_window, Roi);
		///*imshow(image_window2, Roi2);*/
		//waitKey(0);
		
		
		
		
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
		//	if (color == 0)// Green -34 / Blue -64 / 
		//		break;
		//}

		/*color = TemplateMatching::ColorMatching(Rec, Roi);
		
		cout << color << " " << "color" << endl;*/





		/*CaseMatching::THICCcase();*/
	}

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/
}



	


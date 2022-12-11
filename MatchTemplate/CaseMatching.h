#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "DistributorForMatching.h"
#include "getMat.h"
#include "StartUp.h"
using namespace std;
using namespace cv;


struct CaseMatching
{
	vector<vector<POINT>> PointVectorTemp;
	vector<vector<POINT>> PointVectorCleanUp;
	void THICC() {
		Mat templ;
		array<Mat, 11> ReturntMatScreen;
		vector<POINT> ReturnPoints;
		ReturntMatScreen = StartUp::TakeScreenshots();
		templ = imread("ObjectImages/THICCcase.png");

		for (int i = 0; i < 7; i++) {// 5 must later be size 
			TemplateMatching::templateMatchingItems("", "ObjectImages/THICCcase.png", 0.90, false, false, "Intel", ReturnPoints, ReturntMatScreen[i]);
			if (!ReturnPoints.empty()) {
				PointVectorTemp.push_back(ReturnPoints);
				ReturnPoints.clear();
			}
			else {
				PointVectorTemp.push_back(ReturnPoints);
				ReturnPoints.clear();
			}
			cout << "-----------------------------------------------------------------------------------\n";
		}

		StartUp::cleanUpVector(PointVectorTemp, PointVectorCleanUp);
		StartUp::CheckScrollbarPositions();

		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
			if (!PointVectorCleanUp[i].size() == 0) {
				OpenCaseAndTakeScreen(PointVectorCleanUp[i], templ);
			}
			else {
				float keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
				Keyboard::KeyboardInput(keyforInput);
			}
		}

		//HWND hWND = FindeWindow();
		//SetForegroundWindow(hWND);
		//Sleep(5);//Delete later
		//MatScreen = getMat(hWND);
	}

	void OpenCaseAndTakeScreen(vector<POINT> tempPoints, Mat templ) {
		

		/*point.y = (templ.rows / 2) + point.y;
		point.x = (templ.cols / 2) + point.x;
		Mouse::MoverPOINTandPress(point);*/
	}
};
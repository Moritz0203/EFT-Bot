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
		Mat MatScreen;
		Mat templ;
		array<Mat, 11> ReturntMatScreen;
		vector<POINT> ReturnPoints;
		ReturntMatScreen = StartUp::TakeScreenshots();

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

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);
	}
};
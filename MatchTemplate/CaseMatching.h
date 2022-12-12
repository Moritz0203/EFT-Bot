#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "DistributorForMatching.h"
#include "getMat.h"
#include "StartUp.h"
using namespace std;
using namespace cv;


class CaseMatching
{
	vector<vector<POINT>> PointVectorTemp;
	vector<vector<POINT>> PointVectorCleanUp;
	void THICC() {
		Mat templ;
		array<Mat, 11> ReturntMatScreen;
		vector<POINT> ReturnPoints;
		ReturntMatScreen = StartUp::TakeScreenshots();
		templ = imread("ObjectImages/THICCcase.png");
		String NameOfCase = "THICCcase";

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
				OpenCaseAndTakeScreen(PointVectorCleanUp[i], templ, NameOfCase);
			}
			else {
				float keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
				Keyboard::KeyboardInput(keyforInput);
			}
		}

		
	}
	
	vector<vector<PointCase>> pointCase;

	void OpenCaseAndTakeScreen(vector<POINT> tempPoints, Mat templ, std::string NameOfCase) {
		Color color;
		Mat MatScreen;
		vector<PointCase> pointCasetemp;


		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);


		for (int i = 0; i < tempPoints.size(); i++) {
			Rect Rec(tempPoints[i].x, tempPoints[i].y, templ.cols, templ.rows);
			color = TemplateMatching::ColorMatching(Rec, MatScreen);
			switch (color)
			{
				case Color::RED:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::RED, templ.rows, templ.cols);
				case Color::ORANGSH:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::ORANGSH, templ.rows, templ.cols);
				case Color::GREEN:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::GREEN, templ.rows, templ.cols);
				case Color::BLUE:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::BLUE, templ.rows, templ.cols);
				case Color::PURPLE:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::PURPLE, templ.rows, templ.cols);
				case Color::PINK:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::PINK, templ.rows, templ.cols);
				case Color::GRAY:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::GRAY, templ.rows, templ.cols);
				case Color::NOCOLOR:
					pointCasetemp.emplace_back(tempPoints[i], NameOfCase, Color::NOCOLOR, templ.rows, templ.cols);
			}
		}
		
		pointCase.emplace_back(pointCasetemp);
		
		/*point.y = (templ.rows / 2) + point.y;
		point.x = (templ.cols / 2) + point.x;
		Mouse::MoverPOINTandPress(point);*/
	}
};
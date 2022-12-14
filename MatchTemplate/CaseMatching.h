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
	void OpenCaseAndTakeScreen(vector<POINT> tempPoints, Mat templ, std::string NameOfCase, int page);
	void MoveTopBarTHICCcase();

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
			TemplateMatching::templateMatchingItems("ObjectImages/THICCcase.png", 0.90, false, false, "THICCcase", ReturnPoints, ReturntMatScreen[i]);
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

		int page = 0;
		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
			if (!PointVectorCleanUp[i].size() == 0) {
				OpenCaseAndTakeScreen(PointVectorCleanUp[i], templ, NameOfCase, page);
			}
			else {
				float keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
				Keyboard::KeyboardInput(keyforInput);
			}
			page++;
		}
	}
	
	vector<vector<PointCaseInStash>> pointCaseInStash;

	void OpenCaseAndTakeScreen(vector<POINT> tempPoints, Mat templ, std::string NameOfCase, int page) {
		Color color;
		Mat MatScreen;
		vector<PointCaseInStash> pointCasetempStash;
		vector<Mat> MatScreenVector;


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
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::RED, templ.rows, templ.cols, page);
				case Color::ORANGSH:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::ORANGSH, templ.rows, templ.cols, page);
				case Color::GREEN:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::GREEN, templ.rows, templ.cols, page);
				case Color::BLUE:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::BLUE, templ.rows, templ.cols, page);
				case Color::PURPLE:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::PURPLE, templ.rows, templ.cols, page);
				case Color::PINK:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::PINK, templ.rows, templ.cols, page);
				case Color::GRAY:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::GRAY, templ.rows, templ.cols, page);
				case Color::NOCOLOR:
					pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, Color::NOCOLOR, templ.rows, templ.cols, page);
			}
		}
		
		pointCaseInStash.emplace_back(pointCasetempStash);
		
		POINT point{};
		for (int i = 0; i < pointCasetempStash.size(); i++) {
			point.y = (pointCasetempStash[i].heightTempl / 2) + pointCasetempStash[i].point.y;
			point.x = (pointCasetempStash[i].widthTempl / 2) + pointCasetempStash[i].point.x;
			Mouse::MoverPOINTandPressTwoTimes(point);
			
			if (NameOfCase == "THICCcase") {
				MoveTopBarTHICCcase();
			}
			
			HWND hWND = FindeWindow();
			SetForegroundWindow(hWND);
			MatScreenVector.push_back(getMat(hWND));

			float keyforInput = 0x1B;// virtual-key code for the "ESC button" key
			Keyboard::KeyboardInput(keyforInput);

			
		}

		MatchingCase(MatScreenVector, tempPoints);
	}


	std::array<std::string, 6> Cases{
		"itemImages/CaseImages/AmmoCase.png",
		"itemImages/CaseImages/GrenadCase.png",
		"itemImages/CaseImages/HolodilnickCase.png",
		"itemImages/CaseImages/MagCase.png",
		"itemImages/CaseImages/MedCase.png",
		"itemImages/CaseImages/MoneyCase.png",
	};

	std::array<std::string, 6> NameOfItemCases{
		"AmmoCase",
		"GrenadCase",
		"HolodilnickCase",
		"MagCase",
		"MedCase",
		"MoneyCase",
	};

	std::array<double, 6> CasesThreshold{
		0.90,//AmmoCase
		0.90,//GrenadCase
		0.90,//HolodilnickCase
		0.90,//MagCase
		0.90,//MedCase
		0.90,//MoneyCase
	};

	

	void MatchingCase(vector<Mat> MatScreenVector, vector<POINT> tempPoints) {
		string  filename, templatename;
		double	threshold;
		int size = sizeof(Cases) / sizeof(string);
		vector<PointCaseInCase> pointCaseInCase;

		vector<POINT> ReturnDataCase;
		for (int i = 0; i < MatScreenVector.size(); i++) {
			for (int i2 = 0; i2 < size; i2++) {
				threshold = CasesThreshold[i2];
				templatename = Cases[i2];

				TemplateMatching::templateMatchingItems(templatename, threshold, false, true, NameOfItemCases[i], ReturnDataCase, MatScreenVector[i]);

				for (int i3 = 0; i3 < ReturnDataCase.size(); i3++) {
					pointCaseInCase.emplace_back(ReturnDataCase[i3], tempPoints[i], NameOfItemCases[i], )
				}
			}
		}
		
	}

	void MoveTopBarTHICCcase() {
		Mat MatScreen;
		Mat templ;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		MatScreen = getMat(hWND);

		templ = imread("ObjectImages/THICCtopBar.png");
		POINT pointA = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
		pointA.y = (templ.rows / 2) + pointA.y;
		pointA.x = (templ.cols / 2) + pointA.x;

		POINT pointB{};
		pointB.x = pointA.x - 200;
		Mouse::MouseMoveAtoB(pointA, pointB);
	}
};
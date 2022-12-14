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
	void MatchingCaseInCase(vector<Mat>& MatScreenVector, vector<POINT> tempPoints, int page);
	void MoveTopBarTHICCcase();

	vector<vector<POINT>> PointVectorTemp;
	vector<vector<POINT>> PointVectorCleanUp;

	void THICCcase() {
		Mat templ;
		array<Mat, 11> ReturntMatScreen;
		vector<POINT> ReturnPoints;
		ReturntMatScreen = StartUp::TakeScreenshots();
		templ = imread("ObjectImages/THICCcase.png");
		String NameOfCase = "THICCcase";

		for (int i = 0; i < 7; i++) {// 5 must later be size 
			TemplateMatching::templateMatchingItems("ObjectImages/THICCcase.png", 0.90, false, false, NameOfCase, ReturnPoints, ReturntMatScreen[i]);
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
		PointVectorTemp.clear();
		PointVectorCleanUp.clear();
	}

	void ItemsCase() {
		Mat templ;
		array<Mat, 11> ReturntMatScreen;
		vector<POINT> ReturnPoints;
		ReturntMatScreen = StartUp::TakeScreenshots();
		templ = imread("ObjectImages/ItemsCase.png");
		String NameOfCase = "ItemsCase";

		for (int i = 0; i < 7; i++) {// 5 must later be size 
			TemplateMatching::templateMatchingItems("ObjectImages/ItemsCase.png", 0.90, false, false, NameOfCase, ReturnPoints, ReturntMatScreen[i]);
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
		PointVectorTemp.clear();
		PointVectorCleanUp.clear();
	}
	
	std::array<std::string, 8> Cases{
		"itemImages/CaseImages/AmmoCase.png",
		"itemImages/CaseImages/GrenadCase.png",
		"itemImages/CaseImages/HolodilnickCase.png",
		"itemImages/CaseImages/MagCase.png",
		"itemImages/CaseImages/MedCase.png",
		"itemImages/CaseImages/MoneyCase.png",
		"itemImages/CaseImages/JunkCase.png",
		"itemImages/CaseImages/WeaponsCase.png",
	};

	std::array<std::string, 8> NameOfItemCases{
		"AmmoCase",
		"GrenadCase",
		"HolodilnickCase",
		"MagCase",
		"MedCase",
		"MoneyCase",
		"JunkCase",
		"WeaponsCase",
	};

	std::array<double, 8> CasesThreshold{
		0.90,//AmmoCase
		0.90,//GrenadCase
		0.90,//HolodilnickCase
		0.90,//MagCase
		0.90,//MedCase
		0.90,//MoneyCase
		0.90,//JunkCase
		0.90,//WeaponsCase
	};

	void OtherCases() {

	}


	vector<vector<PointCaseInStash>> pointCaseInStash;
	vector<vector<PointCaseInCase>> pointCaseInCase;

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
			pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, color, templ.rows, templ.cols, page);
		}
		
		pointCaseInStash.emplace_back(pointCasetempStash);
		pointCasetempStash.clear();
		
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

		MatchingCaseInCase(MatScreenVector, tempPoints, page);
	}



	std::array<std::string, 6> CasesInCase{
		"itemImages/CaseImages/AmmoCase.png",
		"itemImages/CaseImages/GrenadCase.png",
		"itemImages/CaseImages/HolodilnickCase.png",
		"itemImages/CaseImages/MagCase.png",
		"itemImages/CaseImages/MedCase.png",
		"itemImages/CaseImages/MoneyCase.png",
	};

	std::array<std::string, 6> NameOfItemCasesInCase{
		"AmmoCase",
		"GrenadCase",
		"HolodilnickCase",
		"MagCase",
		"MedCase",
		"MoneyCase",
	};

	std::array<double, 6> CasesInCaseThreshold{
		0.90,//AmmoCase
		0.90,//GrenadCase
		0.90,//HolodilnickCase
		0.90,//MagCase
		0.90,//MedCase
		0.90,//MoneyCase
	};

	void MatchingCaseInCase(vector<Mat> &MatScreenVector, vector<POINT> tempPoints, int page) {
		string  filename, templatename;
		double	threshold;
		int size = sizeof(CasesInCase) / sizeof(string);
		vector<PointCaseInCase> pointCaseInCasetemp;
		Mat templ;
		Color color{};

		vector<POINT> ReturnDataCase;
		for (int i = 0; i < MatScreenVector.size(); i++) {
			for (int i2 = 0; i2 < size; i2++) {
				threshold = CasesInCaseThreshold[i2];
				templatename = CasesInCase[i2];
				templ = imread(CasesInCase[i2]);

				TemplateMatching::templateMatchingItems(templatename, threshold, false, true, NameOfItemCasesInCase[i], ReturnDataCase, MatScreenVector[i]);

				for (int i3 = 0; i3 < ReturnDataCase.size(); i3++) {
					Rect Rec(ReturnDataCase[i3].x, ReturnDataCase[i3].y, templ.cols, templ.rows);

					color = TemplateMatching::ColorMatching(Rec, MatScreenVector[i]);
					pointCaseInCasetemp.emplace_back(ReturnDataCase[i3], tempPoints[i], NameOfItemCasesInCase[i], color, templ.rows, templ.cols, page);
				}
			}
			pointCaseInCase.emplace_back(pointCaseInCasetemp);
			pointCaseInCasetemp.clear();
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
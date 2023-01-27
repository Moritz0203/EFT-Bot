#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "StartUp.h"
using namespace std;
using namespace cv;



namespace CaseProcessor
{
	void OpenCaseAndTakeScreen(int i, int i1);
	void MatchingCaseInCase(Mat& MatScreen, int page, POINT parentCasePoints);
	void MoveTopBarTHICCcase();

	void caseProcess() {
		array<Mat, 11> ReturntMatScreen;

		StartUp::CheckScrollbarPositions();
		ReturntMatScreen = StartUp::TakeScreenshots();

		Matching::CaseMatching(ReturntMatScreen);
		cleanVector::cleanUpVectorCase();

		for (int i = 0; i < pointCaseInStash_C.size(); i++) {
			for (int i1 = 0; i1 < pointCaseInStash_C[i].size(); i1++) {
				if (pointCaseInStash_C[i][i1].nameOfCase == "THICCcase" || pointCaseInStash_C[i][i1].nameOfCase == "ItemsCase") {
					OpenCaseAndTakeScreen(i, i1);
				}
			}
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
			Sleep(500);
		}
	}


	void OpenCaseAndTakeScreen(int i, int i1) {		
		Mat MatScreen;
		POINT point{};
		
		point.y = (pointCaseInStash_C[i][i1].heightTempl / 2) + pointCaseInStash_C[i][i1].point.y;
		point.x = (pointCaseInStash_C[i][i1].widthTempl / 2) + pointCaseInStash_C[i][i1].point.x;
		Mouse::MoverPOINTandPressTwoTimes(point);

		if (pointCaseInStash_C[i][i1].nameOfCase == "THICCcase") {
			MoveTopBarTHICCcase();
		}

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		MatScreen = getMat(hWND);

		int keyforInput = 0x1B;// virtual-key code for the "ESC button" key
		Keyboard::KeyboardInput(keyforInput);
		
		MatchingCaseInCase(MatScreen, pointCaseInStash_C[i][i1].page, pointCaseInStash_C[i][i1].point);
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

	void MatchingCaseInCase(Mat &MatScreen, int page, POINT parentCasePoints) {
		string  filename, templatename;
		double	threshold;
		int sizeString = sizeof(CasesInCase) / sizeof(string);
		Mat templ;

		vector<POINT> ReturnDataCase;
		for (int i2 = 0; i2 < sizeString; i2++) {
			threshold = CasesInCaseThreshold[i2];
			templatename = CasesInCase[i2];
			templ = imread(CasesInCase[i2]);

			TemplateMatching::templateMatchingItems(templatename, threshold, false, true, NameOfItemCasesInCase[i2], ReturnDataCase, MatScreen);

			for (int i3 = 0; i3 < ReturnDataCase.size(); i3++) {
				Rect Rec(ReturnDataCase[i3].x, ReturnDataCase[i3].y, 13/*templ.cols*/, templ.rows);

				const string tagCase = TextMatching::textMatching(MatScreen, Rec);
				if (Matching::checkSecondLastChar(tagCase)) {
					pointCaseInCase[page].emplace_back(ReturnDataCase[i3], parentCasePoints, NameOfItemCasesInCase[i2], tagCase, templ.rows, templ.cols, page);
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
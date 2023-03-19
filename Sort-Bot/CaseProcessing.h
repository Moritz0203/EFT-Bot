#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "StartUp.h"
using namespace std;
using namespace cv;



namespace CaseProcessor {
	void OpenCaseAndTakeScreen(std::shared_ptr<PointCaseInStash> ptr_PCIS);
	void MatchingCaseInCase(Mat& MatScreen, int page, POINT parentCasePoints);
	void MoveTopBarTHICCcase();

	void caseProcess() {
		array<Mat, 11> ReturntMatScreen;
		checksPublic checks;

		checks.CheckScrollbarPositions();
		ReturntMatScreen = StartUp::TakeScreenshots();

		Matching::CaseMatching(ReturntMatScreen);
		cleanUpVectorCase();

		std::shared_ptr<PointCaseInStash> ptr_PCIS;
		findingFreeSlots findeFreeSlot;


		for (int i = 0; i < pointCaseInStash_C.size(); i++) {
			for (PointCaseInStash INpointCase : pointCaseInStash_C[i]) {
				ptr_PCIS = std::make_shared<PointCaseInStash>(INpointCase);

				if (INpointCase.nameOfCase == "THICCcase" || INpointCase.nameOfCase == "ItemsCase") {
					OpenCaseAndTakeScreen(ptr_PCIS);
				}
				else {
					findeFreeSlot.findeSlots(ptr_PCIS);
				}
			}
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
			Sleep(500);
		}
	}


	void OpenCaseAndTakeScreen(std::shared_ptr<PointCaseInStash> ptr_PCIS) {
		Mat MatScreen;
		POINT point{};
		
		point.y = (ptr_PCIS->heightTempl / 2) + ptr_PCIS->point.y;
		point.x = (ptr_PCIS->widthTempl / 2) + ptr_PCIS->point.x;
		Mouse::MoverPOINTandPressTwoTimes(point);

		if (ptr_PCIS->nameOfCase == "THICCcase") {
			MoveTopBarTHICCcase();
		}

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		MatScreen = getMat(hWND);

		int keyforInput = 0x1B;// virtual-key code for the "ESC button" key
		Keyboard::KeyboardInput(keyforInput);
		
		MatchingCaseInCase(MatScreen, ptr_PCIS->page, ptr_PCIS->point);
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
		string filename, templatename;
		double threshold;
		int sizeString = sizeof(CasesInCase) / sizeof(string);
		Mat templ;
		std::shared_ptr<PointCaseInCase> ptr_PCIC;
		findingFreeSlots findeFreeSlot;

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
					pointCaseInCase[page].emplace_back(ReturnDataCase[i3], parentCasePoints, NameOfItemCasesInCase[i2], tagCase, templ.rows, templ.cols, page, NULL);
					ptr_PCIC = make_shared<PointCaseInCase>(pointCaseInCase[page]);
					findeFreeSlot.findeSlots(ptr_PCIC);
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

void cleanUpVectorCase() {
	vector<PointCaseInStash> temp;

	temp = pointCaseInStash_NC[0];
	pointCaseInStash_C.emplace_back(temp);
	temp.clear();

	int iTemp = 1;
	for (int i = 1; i < pointCaseInStash_NC.size(); i++) {
		iTemp++;

		if (iTemp == pointCaseInStash_NC.size())
			break;

		for (PointCaseInStash pointCase : pointCaseInStash_NC[i]) {
			for (PointCaseInStash inPointCase : pointCaseInStash_NC[iTemp]) {
				PointCaseInStash tempPointCase = inPointCase;
				tempPointCase.point.y = tempPointCase.point.y + 343;

				int x_minus_1 = tempPointCase.point.x - 1;
				int x_plus_1 = tempPointCase.point.x + 1;

				if (tempPointCase.point.y == pointCase.point.y) {
					if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
						temp.emplace_back(pointCase);
					}
				}
			}
		}
		if (iTemp == 10) {
			for (PointCaseInStash pointCase : pointCaseInStash_NC[iTemp]) {
				if (pointCase.point.y >= 618) {
					temp.emplace_back(pointCase);
				}
			}
		}
		pointCaseInStash_C.emplace_back(temp);
		temp.clear();
	}
}

class findingFreeSlots {
public:
	template <typename T>
	void findeSlots(shared_ptr<T> case_shared_ptr) { //parent case must be open to use this function
		Mat MatScreen;
		Mat templ = imread("ObjectImages/EmptySquare.png");
		int freeSlots = {};
		
		Mouse::MoverPOINTandPressTwoTimes(case_shared_ptr->point);

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);

		vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ, 0.99999);

		vector<POINT> Clean_ReturnPoints = Matching::removeDuplicates(ReturnPoints);

		freeSlots = Clean_ReturnPoints.size() - 1;

		case_shared_ptr->freeSlots = freeSlots;
	}
};
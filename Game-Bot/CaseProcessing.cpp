#pragma once
#include "CaseProcessing.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "TemplateMatching.h"
#include "DistributorForMatching.h"
#include "getMat.h"
#include "InputMK.h"
#include "Checks.h"
#include <set>
#include "c_log.h"
#include "ItemProcessing.h"
using namespace std;
using namespace cv;

//std::mutex ItemsProcessing::mtx;
//std::condition_variable ItemsProcessing::cv;
//bool ItemsProcessing::ready = false;
//std::mutex ItemsProcessing::i_M;


namespace CaseVector {
	const vector<PathNameThreshold> Case{
		{ "CaseImages/AmmoCase.png",										"AmmoCase",					0.79 },//AmmoCase
		{ "CaseImages/GrenadCase.png",										"GrenadCase",				0.909 },//GrenadCase
		{ "CaseImages/HolodilnickCase.png",									"HolodilnickCase",			0.909 },//HolodilnickCase
		{ "CaseImages/MagCase.png",											"MagCase",					0.88 },//MagCase
		{ "CaseImages/MedCase.png",											"MedCase",					0.92 },//MedCase
		{ "CaseImages/MoneyCase.png",										"MoneyCase",				0.88 },//MoneyCase
		{ "CaseImages/JunkCase.png",										"JunkCase",					0.80 },//JunkCase
		{ "CaseImages/WeaponsCase.png",										"WeaponsCase",				0.88 },//WeaponsCase
		{ "CaseImages/ItemsCase.png",										"ItemsCase",				0.88 },//ItemsCase
		{ "CaseImages/THICCcase.png",										"THICCcase",				0.88 },//THICCcase
	};

	const vector<PathNameThreshold> CaseMedical{
		{ "CaseImages/MedCase.png",											"MedCase",					0.92 },//MedCase
	};
}


void CaseProcessing::CaseOperator_Medical() { // TODO: add at matching constructor definition if only MedCase is needed, Make a new class for PointCaseInStashMedical
	std::shared_ptr<vector<vector<POINT>>> ptr_FreeSlots;
	ItemProcessing itemProcessing;
	checksPublic ChecksPublic;
	Matching matching(730, 300);
	
	c_log::Start("CaseOperator                    ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");
	
	matching.CaseMatching(CaseVector::CaseMedical);

	cleanUpVectorCase();

	std::shared_ptr<vector<PointMedical>> ptr_MedicalVec;
	int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key

	ChecksPublic.CheckScrollbarPositions();
	for (uint8_t i = 0; i < PointCaseInStashMedical::pointCaseInStashMedical_C.size(); i++) {
		bool moved = false;
		for (PointCaseInStashMedical& INpointCase : PointCaseInStashMedical::pointCaseInStashMedical_C[i]) {
			ptr_MedicalVec = std::make_shared<vector<PointMedical>>(INpointCase.ItemsInCase);

			POINT point;
			point.y = (INpointCase.heightTempl / 2) + INpointCase.point.y;
			point.x = (INpointCase.widthTempl / 2) + INpointCase.point.x;

			Sleep(500);
			Mouse::MoverPOINTandPressTwoTimes(point);

			HWND hWND = NULL;
			hWND = GetMat::FindeWindow();//NOTE: später besser anpassen 
			Sleep(500);
			const Mat MatScreen = GetMat::getMat(hWND);

			Rect Rec(730, 300, MatScreen.cols - 1460, MatScreen.rows - 600);
			Mat MatScreenTemp = MatScreen(Rec);

			itemProcessing.MedicalProcess_OneScreen(ptr_MedicalVec, MatScreen);
			Keyboard::KeyboardInput(0x1B);// virtual-key code for the "ESC" key

			moved = true;
		}
		if (moved)
			ChecksPublic.ClickScrollbarPositions();

		Sleep(400);
		Keyboard::KeyboardInput(keyforInput);
	}

	c_log::End("CaseOperator                    ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");
}


// not in do not use will be later used to match other items in cases
void CaseProcessing::CaseOperator() { 
	std::shared_ptr<vector<vector<POINT>>> ptr_FreeSlots;
	findFreeSlots FindFreeSlots;
	checksPublic ChecksPublic;
	Matching matching;


	c_log::Start("CaseOperator                    ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");

	cleanUpVectorCase();

	std::shared_ptr<PointCaseInStash> ptr_PCIS;
	int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key

	ChecksPublic.CheckScrollbarPositions();
	for (uint8_t i = 0; i < PointCaseInStash::pointCaseInStash_C.size(); i++) {
		bool moved = false;
		for (PointCaseInStash& INpointCase : PointCaseInStash::pointCaseInStash_C[i]) {
			ptr_PCIS = std::make_shared<PointCaseInStash>(INpointCase);

			if (INpointCase.nameOfCase == "THICCcase" || INpointCase.nameOfCase == "ItemsCase") {
				//OpenCaseAndTakeScreen(ptr_PCIS);
			}
			else {
				Sleep(500);
				PointCaseInStash* ptr_pointCaseInStash = new PointCaseInStash(INpointCase);

				//FindFreeSlots.Print_Out_Case_EmptySlots();
				delete ptr_pointCaseInStash;
				moved = true;
			}
		}
		if (moved)
			ChecksPublic.ClickScrollbarPositions();

		Sleep(400);
		Keyboard::KeyboardInput(keyforInput);
	}

	c_log::End("CaseOperator                    ", c_log::LCyan, " | [Thread]", c_log::White, "Parent Thread", c_log::LCyan, "StartUp_Thread");
}



//void CaseProcessing::MoveTopBarTHICCcase() {
//	Mat MatScreen;
//	Mat templ;
//
//	HWND hWND = GetMat::FindeWindow();
//	SetForegroundWindow(hWND);
//	MatScreen = GetMat::getMat(hWND);
//
//	templ = imread("ObjectImages/THICCtopBar.png");
//	POINT pointA = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
//	pointA.y = (templ.rows / 2) + pointA.y;
//	pointA.x = (templ.cols / 2) + pointA.x;
//
//	POINT pointB{};
//	pointB.x = pointA.x - 200;
//	Mouse::MouseMoveAtoB(pointA, pointB);
//}

//void CaseProcessing::OpenCaseAndTakeScreen(std::shared_ptr<PointCaseInStash> ptr_PCIS) {
//	Mat MatScreen;
//	POINT point{};
//	GetMat getMat;
//
//	point.y = (ptr_PCIS->heightTempl / 2) + ptr_PCIS->point.y;
//	point.x = (ptr_PCIS->widthTempl / 2) + ptr_PCIS->point.x;
//	Mouse::MoverPOINTandPressTwoTimes(point);
//
//	HWND hWND = GetMat::FindeWindow();
//	SetForegroundWindow(hWND);
//	MatScreen = GetMat::getMat(hWND);
//
//	int keyforInput = 0x1B;// virtual-key code for the "ESC button" key
//	Keyboard::KeyboardInput(keyforInput);
//
//	MatchingCaseInCase(MatScreen, ptr_PCIS->page, ptr_PCIS->point);
//}

//void CaseProcessing::MatchingCaseInCase(Mat& MatScreen, uint8_t page, POINT parentCasePoints) {
//	string filename, templatename;
//	double threshold;
//	int sizeString = sizeof(CasesInCase) / sizeof(string);
//	Mat templ;
//	findFreeSlots FindFreeSlots;
//	vector<vector<POINT>> freeSlots_empty{};
//	Matching matching;
//	vector<POINT> ReturnDataCase_Clean;
//	vector<POINT> ReturnDataCase;
//
//	for (uint8_t i2 = 0; i2 < sizeString; i2++) {
//		threshold = CasesInCaseThreshold[i2];
//		templatename = NameOfItemCasesInCase[i2];
//		templ = imread(CasesInCase[i2]);
//
//		ReturnDataCase = TemplateMatching::templateMatchingItems(templatename, threshold, false, true, NameOfItemCasesInCase[i2], MatScreen);
//
//		if (!ReturnDataCase.empty()) {
//			ReturnDataCase_Clean = matching.removeDuplicates(ReturnDataCase);
//
//			for (uint16_t i3 = 0; i3 < ReturnDataCase_Clean.size(); i3++) {
//				double rows = templ.rows;
//				rows -= rows / 3.0;
//				const Rect Rec(ReturnDataCase_Clean[i3].x, ReturnDataCase_Clean[i3].y, rows, 12);
//
//				string tagCase = TextMatching::textMatching(MatScreen, Rec);
//				if (Matching::checkSecondLastChar(tagCase)) {
//					PointCaseInCase::pointCaseInCase[page].emplace_back(ReturnDataCase_Clean[i3], parentCasePoints, NameOfItemCasesInCase[i2], tagCase, templ.rows, templ.cols, page, 0x0, freeSlots_empty, prefix);
//					PointCaseInCase* ptr_pointCaseInCase = new PointCaseInCase(PointCaseInCase::pointCaseInCase[page].back());
//
//					FindFreeSlots.findeSlots(ptr_pointCaseInCase, PointCaseInCase::pointCaseInCase[page].back().freeSlots);
//					delete ptr_pointCaseInCase;
//				}
//			}
//		}
//	}
//}


struct POINT_PAGE {
	POINT point;
	uint8_t page;
	bool operator<(const POINT_PAGE& other) const {
		return point.x < other.point.x || (point.x == other.point.x && (point.y < other.point.y || (point.y == other.point.y && page < other.page)));
	}
};


void CaseProcessing::cleanUpVectorCase() {
	vector<PointCaseInStash> temp;
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;


	temp = PointCaseInStash::pointCaseInStash_NC[0];
	PointCaseInStash::pointCaseInStash_C.emplace_back(temp);
	temp.clear();

	uint8_t iTemp = 1;
	for (uint8_t i = 1; i < PointCaseInStash::pointCaseInStash_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointCaseInStash::pointCaseInStash_NC.size())
			break;

		for (PointCaseInStash pointCase : PointCaseInStash::pointCaseInStash_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;
			
			bool Found = false;
			uint8_t multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointCaseInStash::pointCaseInStash_NC.size() - 1 || iTempLoop < iTemp + 3; iTempLoop++) {

				for (PointCaseInStash inPointCase : PointCaseInStash::pointCaseInStash_NC[iTempLoop]) {
					PointCaseInStash tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = tempPointCase.point.x + 1;
					

					//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
						//cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfCase << " " << tempPointCase.nameOfCase << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (pointCase.nameOfCase != inPointCase.nameOfCase)
						continue;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
							//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
								//cout << "\n---------- push " << pointCase.point.y << " " << pointCase.point.x << " -- " << tempPointCase.point.y << " " << tempPointCase.point.x << " -- " << inPointCase.point.y << " " << inPointCase.point.x << " -- " << pointCase.nameOfCase << " " << tempPointCase.nameOfCase << " " << pointCase.page << " " << tempPointCase.page << "\n" << endl;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				temp.emplace_back(pointCase);
		}
		if (iTemp == 10) {
			for (PointCaseInStash pointCase : PointCaseInStash::pointCaseInStash_NC[iTemp]) {
				if (pointCase.point.y >= 618) {
					temp.emplace_back(pointCase);
				}
			}
		}
		PointCaseInStash::pointCaseInStash_C.emplace_back(temp);
		temp.clear();
	}
}
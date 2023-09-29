#pragma once
#include "BuyItemsFlea.h"
#include "InputMK.h"
#include "getMat.h"
#include "TemplateMatching.h"
#include "ItemVectors.h"
#include "Includes.h"
using namespace cv;

void BuyItemsFlea::TranslateNameAndPasteIn(const char* nameOfItem) {
	for (auto& vec : ArrayName) {
		for (auto& item : vec) {
			if (strcmp(item.Name.c_str(), nameOfItem) == 0) {
				Keyboard::KeyboardTypeString(item.FleaName.c_str());
				break;
			}
		}
	}
}

void BuyItemsFlea::TranslateNameAndPasteIn_Medical(const char* nameOfItem) {
	for (auto& item : MedicalVector::Medical) {
		if (strcmp(item.Name.c_str(), nameOfItem) == 0) {
			Keyboard::KeyboardTypeString(item.FleaName.c_str());
			break;
		}
	}
}

void BuyItemsFlea::BuyItem(uint8_t quantity) {
	const Mat templ_BuySuccessful = imread("ObjectImages/BuySuccessful.png");
	const Mat templ_SecurityCheck = imread("ObjectImages/SecurityCheck.png");
	const HWND hWND = GetMat::FindeWindow();

	while (quantity == 0) {
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		const Mat MatScreen = GetMat::getMat(hWND);

		Rect Rec(610, 140, MatScreen.cols - 660, MatScreen.rows - 1005);
		Mat MatScreenTemp = MatScreen(Rec);

		const Mat templ_PurchaseButton = imread("ObjectImages/PurchaseButton.png");
		POINT point = TemplateMatching::templateMatchingObjects(MatScreenTemp, templ_PurchaseButton, 0.90);

		point.y = (templ_PurchaseButton.rows / 2) + point.y + 140;
		point.x = (templ_PurchaseButton.cols / 2) + point.x + 610;

		Mouse::MoverPOINTandPress(point);
		Sleep(100);

		Keyboard::KeyboardInput(0x59); //virtual - key code for the "Y" key

		Sleep(450);

		const Mat MatScreen2 = GetMat::getMat(hWND);
		if (TemplateMatching::templateMatchingBool(MatScreen2, templ_BuySuccessful, 0.95)) {
			quantity--;
		}
		else if (TemplateMatching::templateMatchingBool(MatScreen2, templ_SecurityCheck, 0.95)) {
			if(securityCheck.MakeSecurityCheck())
				quantity--;
		}
	}
}

void BuyItemsFlea::OpenFlea(HWND hWND) {
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_FleaMarketButton = imread("ObjectImages/FleaMarketButton.png");


	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_FleaMarketButton, 0.90);
	point.y = (templ_FleaMarketButton.rows / 2) + point.y;
	point.x = (templ_FleaMarketButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(2500);
}

void BuyItemsFlea::CloseFlea(HWND hWND) {
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_CharacterButton = imread("ObjectImages/CharacterButton.png");


	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_CharacterButton, 0.90);
	point.y = (templ_CharacterButton.rows / 2) + point.y;
	point.x = (templ_CharacterButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(2500);
}

bool BuyItemsFlea::BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity, bool IsMedical) {// Make funktion to open flea market and close it
	const HWND hWND = GetMat::FindeWindow();

	if(!ExplicitlyMoreItems)
		OpenFlea(hWND);

	const Mat MatScreen = GetMat::getMat(hWND);

	const Mat templ_FleaSearchBar = imread("ObjectImages/FleaSearchBar.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_FleaSearchBar, 0.95);
	
	if (point.x == 0 && point.y == 0) {		
		return false;
	}

	point.y = (templ_FleaSearchBar.rows / 2) + point.y;
	point.x = (templ_FleaSearchBar.cols / 2) + point.x;
	
	Mouse::MoverPOINTandPress(point);
	Sleep(20);

	if(IsMedical)
		TranslateNameAndPasteIn_Medical(nameOfItem);
	else
		TranslateNameAndPasteIn(nameOfItem);

	Sleep(1500);

	POINT point_ClickItem = point;
	point_ClickItem.y += 45;
	Mouse::MoverPOINTandPress(point_ClickItem);

	Sleep(1000);
	BuyItem(quantity);

	Mouse::MoverPOINTandPress(point);
	Sleep(200);
	Keyboard::KeyboardInput(0x2E); //virtual - key code for the "DEL" key

	if(!ExplicitlyMoreItems)
		CloseFlea(hWND);

	return true;
}












string SecurityCheck::ExtraktSpaceAndNewlines(string input) {
	string result;
	for (char c : input) {
		if (c != ' ' && c != '\n' && c != '\r') {
			result += c;
		}
	}
	return result;
}

bool SecurityCheck::FailSafeDefault(ItemNamePathThreshold& pathNameThreshold, HWND hWND, Mat MatScreen) {
	const Mat templ_SecurityCheckCloseButtom = imread("ObjectImages/CloseButton.png");
	const Mat templ_FleaMarketButton = imread("ObjectImages/FleaMarketButton.png");

	cout << "FailSafeDefault" << endl;

	if (pathNameThreshold.Path == "") {
		POINT point{};
		point = TemplateMatching::templateMatchingObjects(MatScreen, templ_SecurityCheckCloseButtom, 0.90);

		point.y = (templ_SecurityCheckCloseButtom.rows / 2) + point.y;
		point.x = (templ_SecurityCheckCloseButtom.cols / 2) + point.x;

		Mouse::MoverPOINTandPress(point);

		Sleep(3000);

		Mat MatScreen_Home = GetMat::getMat(hWND);

		point = TemplateMatching::templateMatchingObjects(MatScreen_Home, templ_FleaMarketButton, 0.80);

		point.y = (templ_FleaMarketButton.rows / 2) + point.y;
		point.x = (templ_FleaMarketButton.cols / 2) + point.x;

		Mouse::MoverPOINTandPress(point);

		Sleep(1000);

		return false;
	}
	else {
		return true;
	}
}

bool SecurityCheck::FailSafeWithMatching(ItemNamePathThreshold& pathNameThreshold, vector<POINT>& vecItemsToClick , Mat MatScreen, Rect Rec, HWND hWND) {
	const Mat templ_SecurityCheckCloseButtom = imread("ObjectImages/CloseButton.png");
	const Mat templ_FleaMarketButton = imread("ObjectImages/FleaMarketButton.png");
	bool foundItem = false;
	Matching matching(600, 0);
	POINT point{};

	cout << "FailSafeWithMatching" << endl;

	if (vecItemsToClick.empty()) {
		double Threshold = pathNameThreshold.Threshold;

		for (int i = 1; i < 8; i++) {
			Mat templ = imread(pathNameThreshold.Path);

			Threshold -= 0.01;

			cout << Threshold << endl;

			vecItemsToClick = TemplateMatching::templateMatchingItems(pathNameThreshold.Path, Threshold, false, false, pathNameThreshold.Name, MatScreen(Rec));
			vecItemsToClick = matching.removeDuplicates_Rec(vecItemsToClick);

			if (!vecItemsToClick.empty()) {
				foundItem = true;
				break;
			}
		}

		if (!foundItem) {
			cout << "Items not found" << endl;

			point = TemplateMatching::templateMatchingObjects(MatScreen, templ_SecurityCheckCloseButtom, 0.90);

			point.y = (templ_SecurityCheckCloseButtom.rows / 2) + point.y;
			point.x = (templ_SecurityCheckCloseButtom.cols / 2) + point.x;

			Mouse::MoverPOINTandPress(point);

			Sleep(3000);

			Mat MatScreen_Home = GetMat::getMat(hWND);

			point = TemplateMatching::templateMatchingObjects(MatScreen_Home, templ_FleaMarketButton, 0.90);

			point.y = (templ_FleaMarketButton.rows / 2) + point.y;
			point.x = (templ_FleaMarketButton.cols / 2) + point.x;

			Mouse::MoverPOINTandPress(point);

			Sleep(1000);

			return false;
		}
	}
	else {
		return true;
	}
}

void SecurityCheck::ExtraktNameFromSecurityCheck(ItemNamePathThreshold& pathNameThreshold, Mat MatScreen) {
	const Mat templ_SecurityCheckWithName = imread("ObjectImages/SecurityCheckWithName.png");
	bool found = false;
	POINT point{};

	point = TemplateMatching::templateMatchingObjects(MatScreen, templ_SecurityCheckWithName, 0.60);
	Rect Rec(point.x + 30, point.y + 42, templ_SecurityCheckWithName.cols - 60, templ_SecurityCheckWithName.rows - 45);
	string ItemName = TextMatching::textMatching_ItemName(MatScreen, Rec);
	ItemName = ExtraktSpaceAndNewlines(ItemName);

	for (auto& vec : ArrayName) {
		if (found)
			break;

		for (auto& item : vec) {
			string FleaName = ExtraktSpaceAndNewlines(item.FleaName);

			if (ItemName == FleaName) {
				pathNameThreshold.Path = item.Path;
				pathNameThreshold.Name = item.Name;
				pathNameThreshold.FleaName = item.FleaName;
				pathNameThreshold.Threshold = (double)item.Threshold;
				found = true;
				break;
			}
		}
	}

	if (!found) {
		for (auto& item : MedicalVector::Medical) {
			string FleaName = ExtraktSpaceAndNewlines(item.FleaName);

			if (ItemName == FleaName) {
				pathNameThreshold.Path = item.Path;
				pathNameThreshold.Name = item.Name;
				pathNameThreshold.FleaName = item.FleaName;
				pathNameThreshold.Threshold = item.Threshold;
				break;
			}
		}
	}
}

void SecurityCheck::ClickItemsAndConfirm(vector<POINT> vecItemsToClick, Mat templ, HWND hWND, Rect Rec, int ShiftX) {
	const Mat templ_SecurityConfirmButton = imread("ObjectImages/ConfirmButton.png");
	POINT point_ClickItem{};
	POINT point{};

	for (POINT point : vecItemsToClick) {
		point_ClickItem.y = (templ.rows / 2) + point.y;
		point_ClickItem.x = (templ.cols / 2) + point.x;

		cout << point_ClickItem.x << " " << point_ClickItem.y << endl;

		Mouse::MoverPOINTandPress(point_ClickItem);
		Sleep(100);
	}

	Mat MatScreen = GetMat::getMat(hWND);
	point = TemplateMatching::templateMatchingObjects(MatScreen(Rec), templ_SecurityConfirmButton, 0.80);

	point.y = (templ_SecurityConfirmButton.rows / 2) + point.y;
	point.x = (templ_SecurityConfirmButton.cols / 2) + point.x + ShiftX;

	Mouse::MoverPOINTandPress(point);
}




bool SecurityCheck::MakeSecurityCheck() { // testen fehler ausarbeiten 
	const Mat templ_SecurityCheck = imread("ObjectImages/SecurityCheck.png");
	const Mat templ_BuySuccessful = imread("ObjectImages/BuySuccessful.png");
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(50);//Delete later
	Mat MatScreen = GetMat::getMat(hWND);
	Matching matching(600, 0);
	uint8_t OutOfTrys = 5;

	while (TemplateMatching::templateMatchingBool(MatScreen, templ_SecurityCheck, 0.95) != false || OutOfTrys == 0) {
		vector<POINT> vecItemsToClick;
		MatScreen = GetMat::getMat(hWND);	
		ItemNamePathThreshold pathNameThreshold{};	
		
		ExtraktNameFromSecurityCheck(pathNameThreshold, MatScreen);

		if(!FailSafeDefault(pathNameThreshold, hWND, MatScreen))
			continue;

		Rect Rec2(600, 0, MatScreen.cols - 1200, MatScreen.rows);
		Mat templ = imread(pathNameThreshold.Path);
		vecItemsToClick = TemplateMatching::templateMatchingItems(pathNameThreshold.Path, pathNameThreshold.Threshold - 0.01, false, false, pathNameThreshold.Name, MatScreen(Rec2));
		vecItemsToClick = matching.removeDuplicates_Rec(vecItemsToClick);

		if(!FailSafeWithMatching(pathNameThreshold, vecItemsToClick, MatScreen, Rec2, hWND))
			continue;

		ClickItemsAndConfirm(vecItemsToClick, templ, hWND, Rec2, 600);
		
		OutOfTrys--;
		if (OutOfTrys == 0) {
			MatScreen = GetMat::getMat(hWND);
			break;
		}

		Sleep(500);
		MatScreen = GetMat::getMat(hWND);
	}


	if (OutOfTrys != 0) {
		cout << "SecurityCheck good" << endl;

		if (TemplateMatching::templateMatchingBool(MatScreen, templ_BuySuccessful, 0.95)) 
			return true;
		else
			return false;
	}
	else {
		cout << "SecurityCheck wait 5 Min" << endl;
		Sleep(300000);// fail save wait for time 5 min
		return false;
	}
}
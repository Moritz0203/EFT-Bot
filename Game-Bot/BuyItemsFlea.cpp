#include "BuyItemsFlea.h"
#include "InputMK.h"
#include "getMat.h"
#include "TemplateMatching.h"
#include "ItemVectors.h"

void BuyItemsFlea::TranslateNameAndPasteIn(const char* nameOfItem) {
	for (auto& vec : ArrayName) {
		for (auto& item : vec) {
			if (strcmp(item.Name, nameOfItem) == 0) {
				Keyboard::KeyboardTypeString(item.FleaName);
				break;
			}
		}
	}
}

void BuyItemsFlea::TranslateNameAndPasteIn_Medical(const char* nameOfItem) {
	for (auto& item : MedicalVector::Medical) {
		if (strcmp(item.Name, nameOfItem) == 0) {
			Keyboard::KeyboardTypeString(item.FleaName);
			break;
		}
	}
}

void BuyItemsFlea::BuyItem() { // make buy quantity work so it buys the right amount
	if(quantity == 0)
		return;

	const HWND hWND = GetMat::FindeWindow();
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

	//Check if SecurityCheck is open
	const Mat MatScreen2 = GetMat::getMat(hWND);
	const Mat templ_BuySuccessful = imread("ObjectImages/BuySuccessful.png");
	const Mat templ_SecurityCheck = imread("ObjectImages/SecurityCheck.png");
	if (TemplateMatching::templateMatchingBool(MatScreen2, templ_BuySuccessful, 0.95)) {
		quantity--;	
		BuyItem();
	}else if (TemplateMatching::templateMatchingBool(MatScreen2, templ_SecurityCheck, 0.95)) {
		if (securityCheck.MakeSecurityCheck()) {
			BuyItem();
		}
	}else {
		BuyItem();
	}
}

bool BuyItemsFlea::BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity, bool IsMedical) {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);

	this->quantity = quantity;

	const Mat templ = imread("ObjectImages/FleaSearchBar.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.95);
	
	if (point.x == 0 && point.y == 0) {		
		return false;
	}

	point.y = (templ.rows / 2) + point.y;
	point.x = (templ.cols / 2) + point.x;
	
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
	BuyItem();

	Mouse::MoverPOINTandPress(point);
	Sleep(200);
	Keyboard::KeyboardInput(0x2E); //virtual - key code for the "DEL" key

	return true;
}






__forceinline string SecurityCheck::ExtraktSpace(string input) {
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	return input;
}


bool SecurityCheck::MakeSecurityCheck() {
	//const HWND hWND = GetMat::FindeWindow();
	//SetForegroundWindow(hWND);
	//Sleep(5);//Delete later
	//const Mat MatScreen = GetMat::getMat(hWND);
	ItemNamePathThreshold pathNameThreshold{};
	bool found = false;

	// GetNameOfItem 
	
	Mat MatScreenTest = imread("ObjectImages/Screenshot_4.png");
	const Mat templ_SecurityCheckWithName = imread("ObjectImages/SecurityCheckWithName.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreenTest, templ_SecurityCheckWithName, 0.60);

	Rect Rec(point.x + 30, point.y + 42, templ_SecurityCheckWithName.cols - 60, templ_SecurityCheckWithName.rows - 45);
	string ItemName = TextMatching::textMatching_ItemName(MatScreenTest, Rec);

	cout << ItemName << endl;	

	for (auto& vec : ArrayName) {
		for (auto& item : vec) {
			if (ItemName == ExtraktSpace(item.FleaName)) {
				pathNameThreshold.Path = (char*)item.Path;
				pathNameThreshold.Name = (char*)item.Name;
				pathNameThreshold.FleaName = (char*)item.FleaName;
				pathNameThreshold.Threshold = (double)item.Threshold;
				found = true;
				break;	
			}
		}
	}

	if (!found) {
		for (auto& item : MedicalVector::Medical) {
			if (ItemName == ExtraktSpace(item.FleaName)) {
				pathNameThreshold.Path = (char*)item.Path;
				pathNameThreshold.Name = (char*)item.Name;
				pathNameThreshold.FleaName = (char*)item.FleaName;
				pathNameThreshold.Threshold = (double)item.Threshold;
				break;
			}
		}
	}

	cout << pathNameThreshold.Name << endl;
	
	

	/*const char* image_window = "Source Image";
	namedWindow(image_window, WINDOW_AUTOSIZE);
	imshow(image_window, MatScreenTest);
	waitKey(0);*/

	// Find Item in SecurityCheck
	// Click Item
	// Check if SecurityCheck passed
	// If not Try again until passed if time out wait never return until passed
	// return true

	return true;
}
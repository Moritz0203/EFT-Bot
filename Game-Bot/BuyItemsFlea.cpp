#include "BuyItemsFlea.h"
#include "InputMK.h"
#include "getMat.h"
#include "TemplateMatching.h"
#include "ItemVectors.h"

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

void BuyItemsFlea::BuyItem() {
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






__forceinline string SecurityCheck::ExtraktSpaceAndNewlines(string input) {
	string result;
	for (char c : input) {
		if (c != ' ' && c != '\n' && c != '\r') {
			result += c;
		}
	}
	return result;
}


bool SecurityCheck::MakeSecurityCheck() { // testen fehler ausarbeiten 
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(50);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	ItemNamePathThreshold pathNameThreshold{};
	Matching matching(600, 0);
	bool found = false;
	POINT point{};

	// GetNameOfItem 
	
	//Mat MatScreenTest = imread("ObjectImages/Screenshot_3.png");
	const Mat templ_SecurityCheckWithName = imread("ObjectImages/SecurityCheckWithName.png");
	point = TemplateMatching::templateMatchingObjects(MatScreen, templ_SecurityCheckWithName, 0.60);

	Rect Rec(point.x + 30, point.y + 42, templ_SecurityCheckWithName.cols - 60, templ_SecurityCheckWithName.rows - 45);
	string ItemName = TextMatching::textMatching_ItemName(MatScreen, Rec);

	ItemName = ExtraktSpaceAndNewlines(ItemName);

	cout << ItemName << endl;	

	for (auto& vec : ArrayName) {
		if(found)
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


	if (pathNameThreshold.Path == "") {
		const Mat templ_SecurityCheckCloseButtom = imread("ObjectImages/CloseButton.png");
		point = TemplateMatching::templateMatchingObjects(MatScreen, templ_SecurityCheckCloseButtom, 0.90);

		point.y = (templ_SecurityCheckCloseButtom.rows / 2) + point.y;
		point.x = (templ_SecurityCheckCloseButtom.cols / 2) + point.x;

		Mouse::MoverPOINTandPress(point);

		Sleep(2000);

		Mat MatScreen_Home = GetMat::getMat(hWND);

		const Mat templ_FleaMarketButton = imread("ObjectImages/FleaMarketButton.png");
		point = TemplateMatching::templateMatchingObjects(MatScreen_Home, templ_FleaMarketButton, 0.80);

		point.y = (templ_FleaMarketButton.rows / 2) + point.y;
		point.x = (templ_FleaMarketButton.cols / 2) + point.x;

		Mouse::MoverPOINTandPress(point);

		Sleep(500);

		MakeSecurityCheck();
	}


	// Find Item in SecurityCheck
	Rect Rec2(600, 0, MatScreen.cols - 1200, MatScreen.rows);	
	Mat TemplateMatching = MatScreen(Rec2);

	/*const char* image_window = "Source Image";
	namedWindow(image_window, WINDOW_AUTOSIZE);
	imshow(image_window, TemplateMatching);
	waitKey(0);*/

	Mat templ = imread(pathNameThreshold.Path);
	vector<POINT> vecItemsToClick = TemplateMatching::templateMatchingItems(pathNameThreshold.Path, pathNameThreshold.Threshold , false, false, pathNameThreshold.Name, TemplateMatching);
	vecItemsToClick = matching.removeDuplicates_Rec(vecItemsToClick);
	

	if (vecItemsToClick.empty()) {
		const Mat templ_SecurityCheckCloseButtom = imread("ObjectImages/CloseButton.png");
		point = TemplateMatching::templateMatchingObjects(MatScreen, templ_SecurityCheckCloseButtom, 0.90);

		point.y = (templ_SecurityCheckCloseButtom.rows / 2) + point.y;
		point.x = (templ_SecurityCheckCloseButtom.cols / 2) + point.x;

		Mouse::MoverPOINTandPress(point);

		Sleep(2000);

		Mat MatScreen_Home = GetMat::getMat(hWND);

		const Mat templ_FleaMarketButton = imread("ObjectImages/FleaMarketButton.png");
		point = TemplateMatching::templateMatchingObjects(MatScreen, MatScreen_Home, 0.80);

		point.y = (templ_FleaMarketButton.rows / 2) + point.y;
		point.x = (templ_FleaMarketButton.cols / 2) + point.x;

		Mouse::MoverPOINTandPress(point);

		Sleep(500);

		MakeSecurityCheck();
	}


	// Click Item

	POINT point_ClickItem{};
	for (POINT point : vecItemsToClick) {
		point_ClickItem.y = (templ.rows / 2) + point.y;
		point_ClickItem.x = (templ.cols / 2) + point.x;

		cout << point_ClickItem.x << " " << point_ClickItem.y << endl;	

		Mouse::MoverPOINTandPress(point_ClickItem);
		Sleep(100);
	}

	// Check if SecurityCheck passed
	TemplateMatching = GetMat::getMat(hWND);
	const Mat templ_SecurityCheckBotton= imread("ObjectImages/ConfirmButton.png");
	point = TemplateMatching::templateMatchingObjects(TemplateMatching(Rec2), templ_SecurityCheckBotton, 0.80);
	
	point.x += 600;

	cout << point.x << " " << point.y << endl;	

	Mouse::MoverPOINTandPress(point);

	// If not Try again until passed if time out wait never return until passed
	
	Sleep(500);

	Mat MatScreen_New = GetMat::getMat(hWND);

	const Mat templ_SecurityCheck = imread("ObjectImages/SecurityCheck.png");
	if (TemplateMatching::templateMatchingBool(MatScreen_New, templ_SecurityCheck, 0.95)) {
		cout << "SecurityCheck good" << endl;
		OutOfTrys = 5;
		return true;
	}else if (OutOfTrys == 0) { 
		Sleep(300000);// fail save wait for time 5 min
		OutOfTrys = 5;
		return true;
	}


	cout << "weiter" << endl;	

	Sleep(500);
	OutOfTrys--;
	MakeSecurityCheck();
}
#include "BuyItemsFlea.h"
#include "InputMK.h"
#include "getMat.h"
#include "TemplateMatching.h"

vector<InternelNameToFleaName> NameTranslation{
	{"AFAK",		"AFAK tactical individual first aid kit"},
	{"AI2",			"AI-2 medkit"},
	{"AluSplint",	"Aluminum splint"},
	{"Analgin",		"Analgin painkillers"},
	{"ArmyBandage", "Army bandage"},
	{"Augmentin",	"Augmentin antibiotic pills"},
	{"Bandage",		"Aseptic bandage"},
	{"CarKit",		"Car first aid kit"},
	{"CAT",			"CAT hemostatic tourniquet"},
	{"CMS",			"CMS surgical kit"},
	{"Esmarch",		"Esmarch tourniquet"},
	{"GoldenStar",	"Golden Star Balsam"},
	{"Grizzly",		"Grizzly medical kit"},
	{"Hemostatic",	"CALOK-B hemostatic applicator"},
	{"Ibuprofen",	"Ibuprofen painkillers"},
	{"IFAK",		"IFAK individual first aid kit"},
	{"Salewa",		"Salewa first aid kit"},
	{"Splint",		"Immobilizing splint"},
	{"Surv12",		"Surv12 field surgical kit"},
	{"Vaseline",	"Vaseline balm"},
};

void BuyItemsFlea::TranslateNameAndPasteIn(const char* nameOfItem) {
	for (auto& item : NameTranslation) {
		if (strcmp(item.InternelName, nameOfItem) == 0) {
			Keyboard::KeyboardTypeString(item.FleaName);
			break;
		}
	}
}

void BuyItemsFlea::BuyItem(uint8_t quantity) { // make buy quantity work so it buys the right amount
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);

	Rect Rec(610, 140, MatScreen.cols - 660, MatScreen.rows - 1005);
	Mat MatScreenTemp = MatScreen(Rec);

	const Mat templ = imread("ObjectImages/PurchaseButton.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreenTemp, templ, 0.90);
	
	point.y = (templ.rows / 2) + point.y + 140;
	point.x = (templ.cols / 2) + point.x + 610;
	
	Mouse::MoverPOINTandPress(point);
	Sleep(100);
	
	Keyboard::KeyboardInput(0x59); //virtual - key code for the "Y" key

	Sleep(450);

	//Check if SecurityCheck is open
	const Mat MatScreen2 = GetMat::getMat(hWND);
	const Mat templ2 = imread("ObjectImages/BuySuccessful.png");
	cout << TemplateMatching::templateMatchingBool(MatScreen2, templ2, 0.95) << endl;
}

bool BuyItemsFlea::BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity) {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);

	const Mat templ = imread("ObjectImages/FleaSearchBar.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.95);
	
	if (point.x == 0 && point.y == 0) {		
		return false;
	}

	point.y = (templ.rows / 2) + point.y;
	point.x = (templ.cols / 2) + point.x;
	
	Mouse::MoverPOINTandPress(point);
	Sleep(20);
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

	return true;
}

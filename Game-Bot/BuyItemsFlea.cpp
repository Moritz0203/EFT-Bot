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
			//Keyboard::KeyboardInput(0x0D); //virtual - key code for the "ENTER" key
			break;
		}
	}
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

	TranslateNameAndPasteIn(nameOfItem);

	// buy item 

	Mouse::MoverPOINTandPress(point);
	Sleep(200);
	Keyboard::KeyboardInput(0x2E); //virtual - key code for the "DEL" key

	return true;
}

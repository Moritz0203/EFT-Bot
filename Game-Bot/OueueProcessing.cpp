#include "OueueProcessing.h"
#include "getMat.h"
#include "TemplateMatching.h"
#include "InputMK.h"
#include "Utility.h"

void OueueProcessing::ClickNextButton() {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_NextButton = imread("ObjectImages/NextButton.png");

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_NextButton, 0.85);
	point.y = (templ_NextButton.rows / 2) + point.y;
	point.x = (templ_NextButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(1000);
}

void OueueProcessing::ResetMousePosition() {
	POINT point = { 960, 540 };
	Mouse::MouseMove(point);
}

void OueueProcessing::ClickApplyButton() {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_ApplyButton = imread("ObjectImages/ApplyButton.png");

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_ApplyButton, 0.90);
	point.y = (templ_ApplyButton.rows / 2) + point.y;
	point.x = (templ_ApplyButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(1000);
}

void OueueProcessing::ClickReadyButton() {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_ReadyButton = imread("ObjectImages/ReadyButton.png");

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_ReadyButton, 0.90);
	point.y = (templ_ReadyButton.rows / 2) + point.y;
	point.x = (templ_ReadyButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(1000);

}

void OueueProcessing::ClickEscapeFromTarkov() {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_EscapeFromTarkovButton = imread("ObjectImages/EscapeFromTarkovButton.png");

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_EscapeFromTarkovButton, 0.90);
	point.y = (templ_EscapeFromTarkovButton.rows / 2) + point.y;
	point.x = (templ_EscapeFromTarkovButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(1000);
}

void OueueProcessing::ClickOnMap() {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	const Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_Map = imread(MapVector[MapToRun].Path);

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_Map, MapVector[MapToRun].Threshold);
	point.y = (templ_Map.rows / 2) + point.y;
	point.x = (templ_Map.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(1000);
}

void OueueProcessing::SelectTime() {

	if(MapVector[MapToRun].NoTimeLimit == true)
		return;
	
	while (true) {
		BothTimes bothTimes = TarkovTime::realTimeToTarkovTime();

		if (IsTimeInRange(bothTimes.left, MapVector[MapToRun].LowerTimeLimit, MapVector[MapToRun].UpperTimeLimite) == true) {
			Mouse::MoverPOINTandPress(POINT{ 785, 870 });
			return;
		}
		else if (IsTimeInRange(bothTimes.right, MapVector[MapToRun].LowerTimeLimit, MapVector[MapToRun].UpperTimeLimite) == true) {
			Mouse::MoverPOINTandPress(POINT{ 980, 870 });
			return;
		}

		std::this_thread::sleep_for(std::chrono::minutes(5));
	}
}

void OueueProcessing::Incurance() {
	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later

	Mat MatScreen = GetMat::getMat(hWND);
	const Mat templ_InsureAllButton = imread("ObjectImages/InsureAllButton.png");

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_InsureAllButton, 0.90);
	point.y = (templ_InsureAllButton.rows / 2) + point.y;
	point.x = (templ_InsureAllButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(100);

	MatScreen = GetMat::getMat(hWND);

	Rect Rec(1650, 850, MatScreen.cols - 1783, MatScreen.rows - 1010);
	int number = TextMatching::textMatching_OnlyNumbers(MatScreen, Rec);// later push to server 

	const Mat templ_InsureButton = imread("ObjectImages/InsureButton.png");

	point = TemplateMatching::templateMatchingObjects(MatScreen, templ_InsureButton, 0.90);
	point.y = (templ_InsureButton.rows / 2) + point.y;
	point.x = (templ_InsureButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(1000);
}

void OueueProcessing::ExtractRaidInformation() {
	HWND hWND = GetMat::FindeWindow();
	Mat MatScreen1 = GetMat::getMat(hWND);

	Rect Rec(1050, 655, MatScreen1.cols - 1825, MatScreen1.rows - 1050);

	std::tm timeStruct = TextMatching::textMatching_OnlyNumbers_Time(MatScreen1, Rec);// later push to server 

	// Add ECP extraction 
	Mat MatScreen2 = GetMat::getMat(hWND);

	Rect RecEXP(930, 710, MatScreen2.cols - 1660, MatScreen2.rows - 1010);

	int EXP = TextMatching::textMatching_OnlyNumbers(MatScreen2, RecEXP);// later push to server

	//cout << "EXP: " << EXP << endl;

	//Mat RecMat = MatScreen2(RecEXP);
	//imshow("MatScreen2", RecMat);
	//waitKey(0);
}




void OueueProcessing::OueueProcess_InGame() {
	ClickEscapeFromTarkov();
	ClickNextButton();
	ClickOnMap();	

	if (MapVector[MapToRun].NoTimeLimit == true) {
		ClickReadyButton();
	} 
	else {
		SelectTime();
		
		if(NeedIncurance != true) {
			ClickReadyButton();
		}
		else {
			ClickNextButton();
			ClickNextButton();
		}
	}

	if (NeedIncurance == true)
		Incurance();

	ClickNextButton();	
	ClickReadyButton();
}

void OueueProcessing::OueueProcess_OutOfGame() {
	ExtractRaidInformation();
	ClickNextButton();

	Mouse::ClickLeftButton();

	Sleep(1000);

	Mouse::ClickLeftButton();

	Sleep(1000);

	Mouse::ClickLeftButton();
	
	Sleep(1000);

	if (NeedAutoHeal) {
		ClickApplyButton();
		ClickNextButton(); 
	}
	else {
		ClickNextButton();
	}

	Mat MatScreen;
	while (true) {
		Sleep(1000);
		MatScreen = GetMat::getMat(GetMat::FindeWindow());

		if(TemplateMatching::templateMatchingBool(MatScreen, imread("ObjectImages/EscapeFromTarkovButton.png"), 0.90) == true)
			break;
	}
}
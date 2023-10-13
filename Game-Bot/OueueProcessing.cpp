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

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_NextButton, 0.90);
	point.y = (templ_NextButton.rows / 2) + point.y;
	point.x = (templ_NextButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(500);
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

	Sleep(500);
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

	Sleep(500);
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

	Sleep(500);
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

	// read in cost of insurance

	const Mat templ_InsureButton = imread("ObjectImages/InsureButton.png");

	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ_InsureButton, 0.90);
	point.y = (templ_InsureButton.rows / 2) + point.y;
	point.x = (templ_InsureButton.cols / 2) + point.x;

	Mouse::MoverPOINTandPress(point);

	Sleep(500);
}




void OueueProcessing::OueueProcess() {
	

}

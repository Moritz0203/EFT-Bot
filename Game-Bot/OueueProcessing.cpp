#include "OueueProcessing.h"
#include "getMat.h"
#include "TemplateMatching.h"
#include "InputMK.h"

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


}

void OueueProcessing::SelectTime() {


}

void OueueProcessing::Incurance() {


}




void OueueProcessing::OueueProcess() {
	

}

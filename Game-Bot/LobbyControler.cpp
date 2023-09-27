#pragma once
#include "LobbyControler.h"
#include "Checks.h"
#include "getMat.h"
#include "LobbyControler.h"
#include "Includes.h"
#include "TemplateMatching.h"
#include "InputMK.h"

void LobbyControler::TakeScreenShots() {
	checksPublic ChecksPublic;
	GetMat getMat;

	ChecksPublic.CheckScrollbarPositions();
	Sleep(300);
	getMat.TakeScreenshots(Stash_Version);
}

void LobbyControler::OpenStashView() {
	const HWND hWND = GetMat::FindeWindow();
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



void LobbyControler::StashControler() {

	OpenStashView();


}

void LobbyControler::ServerControler() {// Later 


}

void LobbyControler::QueueControler() {// next to do 


}



void LobbyControler::Controler() {


}


#pragma once
#include "LobbyControler.h"
#include "Checks.h"
#include "getMat.h"
#include "LobbyControler.h"

void LobbyControler::TakeScreenShots() {
	checksPublic ChecksPublic;
	GetMat getMat;

	ChecksPublic.CheckScrollbarPositions();
	Sleep(300);
	getMat.TakeScreenshots(Stash_Version);
}



void LobbyControler::StashControler() {


}

void LobbyControler::ServerControler() {


}



void LobbyControler::Controler() {


}


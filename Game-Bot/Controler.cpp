#pragma once
#include "Controler.h"
#include "Checks.h"
#include "getMat.h"

void Controler::TakeScreenShots() {
	checksPublic ChecksPublic;
	GetMat getMat;

	ChecksPublic.CheckScrollbarPositions();
	Sleep(300);
	getMat.TakeScreenshots(Stash_Version);
}

#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "TemplateMatching.h"
#include "getMat.h"
#include "Utility.h"
#include "CaseProcessing.h"
#include "PouchProcessing.h"
#include "ReadConfigFile.h"
#include "c_log.h"
#include "BuyItemsFlea.h"
#include "LobbyControler.h"
#include "ItemMoving.h"
#include "StashObject.h"
#include "InputMK.h"
#include "HumanizedMovement.h"

#include <cmath>
#include <random>


// HighCard | High T | K 
// SecurityCheck Items Barter / Medical / Food 
// ObjectAvoidance = evade 




int main() {
	//c_log::add_out(new c_log::c_log_consolestream);

	const HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(1000);//Delete later


	Mat MatScreen = GetMat::getMatWithRect(hWND, POINT{ 0,0 }, 150, 150);

	imshow("test", MatScreen);	
	waitKey(0);
}
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

// HighCard | High T
// SecurityCheck Items Barter / Medical / Food 

int main() {
	c_log::add_out(new c_log::c_log_consolestream);

	/*ProgrammScheduler programmScheduler;

	programmScheduler.Scheduler();*/

	//checksPublic ChecksPublic;
	//CaseProcessing caseProcessing;
	//PouchProcessing pouchProcessing(Gamma);
	//GetMat getMat;

	//ChecksPublic.CheckScrollbarPositions();
	//Sleep(300);
	//getMat.TakeScreenshots(1);

	////caseProcessing.CaseOperator();

	//pouchProcessing.PouchMatching();

	//pouchProcessing.Pouch_FirstStart();


	/*ReadPrefixConfigFile readPrefixConfigFile("ConfigPrefix.txt");

	readPrefixConfigFile.ParseConfig();
	readPrefixConfigFile.PrintData();*/

	/*BuyItemsFlea buyItemsFlea;

	buyItemsFlea.BuyItemsFleaOperator("Bandage", 0, true);*/

	/*std::vector<POINT> vec{};

	Matching matching;	
	Mat MatScreen = imread("ObjectImages/SecurityCheck.png");
	vec = TemplateMatching::templateMatchingItems("itemImages/MedicalImages/Medical/Grizzly.png", 0.85, false, false, "Grizzly", MatScreen);

	vec = matching.removeDuplicates(vec);

	for (auto& item : vec) {
		cout << item.x << " " << item.y << endl;
	}*/	


	/*SecurityCheck securityCheck;
	securityCheck.MakeSecurityCheck();*/




	/*LobbyControler lobbyControler;
	lobbyControler.Controler();*/

	/*while (true) {
		BothTimes bothTimes = TarkovTime::realTimeToTarkovTime();
		cout << bothTimes.left.tm_hour << " " << bothTimes.left.tm_min << " " << bothTimes.left.tm_sec << " -- " << bothTimes.right.tm_hour << " " << bothTimes.right.tm_min << " " << bothTimes.right.tm_sec << endl;
		Sleep(1000);	
	}*/

	//ItemMoving itemMoving;
	//PointerStack prefix{};

	//const HWND hWND = GetMat::FindeWindow();
	//SetForegroundWindow(hWND);
	//Sleep(5);//Delete later
	//const Mat MatScreen = GetMat::getMat(hWND);

	//POINT point = TemplateMatching::templateMatchingObjects(MatScreen, imread("itemImages/MedicalImages/Medical/Grizzly.png"), 0.85);

	//Pouch::pouch.pointPouch = TemplateMatching::templateMatchingObjects(MatScreen, imread("CaseImages/Secure_container_Gamma.png"), 0.90);

	//prefix.pointItem.page = 1;
	//prefix.pointItem.point.x = point.x;
	//prefix.pointItem.point.y = point.y;
	//prefix.pointItem.widthTempl = 127;
	//prefix.pointItem.heightTempl = 127;	
	//prefix.pointItem.nameOfItem = "Grizzly";

	//itemMoving.MovFromStash(prefix);


	/*BuyItemsFlea buyItemsFlea;

	buyItemsFlea.EasyBuyItemsAPI("Grizzly", 1);*/


	//const HWND hWND = GetMat::FindeWindow();
	////SetForegroundWindow(hWND);
	//Sleep(10);//Delete later

	//const char* image_window = "Source Image";
	//namedWindow(image_window, WINDOW_AUTOSIZE);

	//POINT point = { 830, 560 };

	//Mat MatScreen = GetMat::getMatWithRect(hWND, point, 265, 65);

	//cv::imshow(image_window, MatScreen);
	//waitKey(0);


	/*Mat MatTemplate = imread("ObjectImages/GetReadyBanner.png");
	POINT point = TemplateMatching::templateMatchingObjects(imread("ObjectImages/Screenshot_2.png"), MatTemplate, 0.85);

	cout << point.x + MatTemplate.rows << " " << point.y + MatTemplate.cols << endl;*/	
}
#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "TemplateMatching.h"
#include "getMat.h"
#include "Checks.h"
#include "CaseProcessing.h"
#include "PouchProcessing.h"
#include "ReadConfigFile.h"
#include "c_log.h"
#include "BuyItemsFlea.h"

// HighCard 
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

	buyItemsFlea.BuyItemsFleaOperator("Bandage", 0);*/

	std::vector<POINT> vec{};

	Matching matching;	
	Mat MatScreen = imread("ObjectImages/SecurityCheck.png");
	vec = TemplateMatching::templateMatchingItems("itemImages/MedicalImages/Medical/Grizzly.png", 0.85, false, false, "Grizzly", MatScreen);

	vec = matching.removeDuplicates(vec);

	for (auto& item : vec) {
		cout << item.x << " " << item.y << endl;
	}	
}
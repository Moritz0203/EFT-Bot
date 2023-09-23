#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "getMat.h"
#include "Checks.h"
#include "CaseProcessing.h"
#include "PouchProcessing.h"
#include "ReadConfigFile.h"
#include "c_log.h"
#include "BuyItemsFlea.h"


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

	BuyItemsFlea buyItemsFlea;

	buyItemsFlea.BuyItemsFleaOperator("Salewa", 0);
}
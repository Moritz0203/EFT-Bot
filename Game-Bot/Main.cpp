#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "getMat.h"
#include "Checks.h"
#include "CaseProcessing.h"
#include "PouchProcessing.h"
#include "ReadConfigFile.h"


int main() {
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


	ReadPrefixConfigFile readPrefixConfigFile("ConfigPrefix.txt");

	readPrefixConfigFile.ParseConfig();
	readPrefixConfigFile.PrintData();
}
#include "ProgrammScheduler.h"

#include "DistributorForMatching.h"
#include "getMat.h"
#include "Checks.h"
#include "CaseProcessing.h"



int main() {
	/*ProgrammScheduler programmScheduler;

	programmScheduler.Scheduler();*/

	checksPublic ChecksPublic;
	CaseProcessing caseProcessing;
	GetMat getMat;

	ChecksPublic.CheckScrollbarPositions();
	Sleep(300);
	getMat.TakeScreenshots(11);

	caseProcessing.CaseOperator();
}
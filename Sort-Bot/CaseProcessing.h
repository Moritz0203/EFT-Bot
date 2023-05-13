#pragma once
#include "Includes.h"
using namespace cv;

class CaseProcessor {
	static void OpenCaseAndTakeScreen(std::shared_ptr<PointCaseInStash> ptr_PCIS);

	static void MatchingCaseInCase(Mat& MatScreen, uint8_t page, POINT parentCasePoints);

	static void cleanUpVectorCase();

public:
	static void caseProcess();

	static void MoveTopBarTHICCcase();
};
#pragma once
#include "Includes.h"
using namespace cv;

class CaseProcessing {
	//static void OpenCaseAndTakeScreen(std::shared_ptr<PointCaseInStash> ptr_PCIS);

	//static void MatchingCaseInCase(Mat& MatScreen, uint8_t page, POINT parentCasePoints);

	static void cleanUpVectorCase();

public:
	void CaseOperator_Medical();
	void CaseOperator();

	//static void MoveTopBarTHICCcase();
};
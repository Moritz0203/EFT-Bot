#pragma once
#include "Includes.h"
using namespace cv;

class Matching {
public:
	static bool checkSecondLastChar(const string tagCase);

	vector<POINT> removeDuplicates(vector<POINT>& points);

	void AmmunitionMatching(array<Mat, 11>& arrayMatScreen);

	void CaseMatching();

	void MagazineMatching(array<Mat, 11>& arrayMatScreen);

	void BarterMatching(array<Mat, 11>& arrayMatScreen);	
};
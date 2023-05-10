#pragma once
#include "Includes.h"
using namespace cv;

class Matching {
public:
	static bool checkSecondLastChar(string &tagCase);

	vector<POINT> removeDuplicates(vector<POINT>& points);

	void AmmunitionMatching();

	void CaseMatching();

	void MagazineMatching();

	void BarterMatching();	
};
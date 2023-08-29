#pragma once
#include "Includes.h"
using namespace cv;

struct PathNameThreshold {
	const char* Path;
	const char* Name;
	const double Threshold;
};

struct PathNameThresholdItemSize {
	const char* Path;
	const char* Name;
	const double Threshold;
	const uint8_t ItemSize;
};

class Matching {
public:
	static bool checkSecondLastChar(string &tagCase);

	vector<POINT> removeDuplicates(vector<POINT>& points);

	vector<PointAmmunition> removeDuplicatesPage(vector<PointAmmunition>& points);

	void AmmunitionMatching(vector<PathNameThreshold> input);

	void CaseMatching(vector<PathNameThreshold> input);

	void MagazineMatching(vector<PathNameThreshold> input);

	void BarterMatching(vector<PathNameThresholdItemSize> input, vector<vector<PointBarter>> &input_vec);
};
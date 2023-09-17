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

struct PathNameThresholdItemSizeMaxHP {
	const char* Path;
	const char* Name;
	const double Threshold;
	const uint8_t ItemSize;
	const uint16_t MaxHp;
};

class Matching {
public:
	static bool checkSecondLastChar(string &tagCase);

	vector<POINT> removeDuplicates(vector<POINT>& points);

	vector<POINT> removeDuplicates_Medical(vector<POINT>& points);

	//vector<PointAmmunition> removeDuplicatesPage(vector<PointAmmunition>& points);

	//void AmmunitionMatching(vector<PathNameThreshold> input);

	void CaseMatching(vector<PathNameThreshold> input);

	//void BarterMatching(vector<PathNameThresholdItemSize> input, vector<vector<PointBarter>> &input_vec);

	void MedicalMatching_OneScreen(vector<PathNameThresholdItemSizeMaxHP> input, shared_ptr<vector<PointMedical>>& ptr_MedicalVec, Mat MatScreen);
};
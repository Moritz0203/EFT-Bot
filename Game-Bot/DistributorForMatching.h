#pragma once
#include "Includes.h"
using namespace cv;

struct PathNameThreshold {
	const string Path;
	const string Name;
	const double Threshold;
};

struct PathNameThresholdItemSize{
	const string Path;
	const string Name;
	const string FleaName;
	const double Threshold;
	const uint8_t ItemSize;
};

struct PathNameThresholdItemSizeMaxHP {
	const string Path;
	const string Name;
	const string  FleaName;
	const double Threshold;
	const uint8_t ItemSize;
	const uint16_t MaxHp;
};

class Matching {
	uint16_t X{}, Y{};

public:
	Matching();

	Matching(uint16_t x, uint16_t y) {
		this->X = x;
		this->Y = y;
	}

	static bool checkSecondLastChar(string &tagCase);

	vector<POINT> removeDuplicates(vector<POINT>& points);

	vector<POINT> removeDuplicates_Rec(vector<POINT>& points);

	//vector<PointAmmunition> removeDuplicatesPage(vector<PointAmmunition>& points);

	//void AmmunitionMatching(vector<PathNameThreshold> input);

	void CaseMatching(vector<PathNameThreshold> input, vector<vector<PointCase>>& vec);

	//void BarterMatching(vector<PathNameThresholdItemSize> input, vector<vector<PointBarter>> &input_vec);

	void BarterMatching_OneScreen(vector<PathNameThresholdItemSize> input, shared_ptr<vector<PointBarter>>& ptr_BarterVec, Mat MatScreen);

	void MedicalMatching_OneScreen(vector<PathNameThresholdItemSizeMaxHP> input, shared_ptr<vector<PointMedical>>& ptr_MedicalVec, Mat MatScreen);

	void MedicalMatching(vector<PathNameThresholdItemSizeMaxHP> input);

	vector<vector<PointMedical>> OneItemMedicalMatching(PathNameThresholdItemSizeMaxHP input);
	vector<vector<PointBarter>> OneItemBarterMatching(PathNameThresholdItemSize input);
};
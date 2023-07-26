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

	void CaseMatching();

	void MagazineMatching();

	void BarterMatching();

private:
	friend class CaseProcessing;
	static std::mutex mtx;
	static std::condition_variable cv;
	static bool ready;
};
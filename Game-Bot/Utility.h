#pragma once
#include "PointCase.h"

using namespace std;

class checksPublic {
public:
	void CheckScrollbarPositions();

	void ClickScrollbarPositions();

	void CheckForFails();
};

class findFreeSlots {
	vector<vector<POINT>> FinalResults;
	vector<POINT> Clean_ReturnPoints;

	vector<vector<POINT>> SortINrows(vector<POINT> vector_Input);

	static bool comparePoints(const POINT& a, const POINT& b);

public:
	void findeSlots(const PointCase* pointCase, std::vector<std::vector<POINT>>& freeSlots);

	void Print_Out_Case_EmptySlots();
};

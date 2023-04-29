#pragma once
#include "Includes.h"
using namespace std;

class checksPublic {
public:
	void CheckScrollbarPositions();

	void CheckForFails();
};

class findFreeSlots {
	vector<vector<POINT>> FinalResults;
	vector<POINT> Clean_ReturnPoints;

	vector<vector<POINT>> SortINrows(vector<POINT> vector_Input);

	static bool comparePoints(const POINT& a, const POINT& b);

public:
	void findeSlots(POINT pointCase, shared_ptr<std::vector<std::vector<POINT>>> freeSlots);

	void Print_Out_Case_EmptySlots();
};

class Check_for_Space {
	struct SpecsForItem {
		int columns;
		int rows;
	};

	bool One_Slot(shared_ptr<vector<vector<POINT>>>& ptr_vector);

	bool Vertical_Horizontal(shared_ptr<vector<vector<POINT>>>& ptr_vector, const SpecsForItem specsForItem);

	void remove_duplicates(std::vector<std::shared_ptr<std::vector<POINT>>>& points, const std::shared_ptr<std::vector<int>>& values);

	bool check_Column(std::vector<std::vector<int>>& input, const std::shared_ptr<std::vector<POINT>>& points);

	//bool check_Column_Lambda(std::vector<std::vector<int>>& input, std::shared_ptr<std::vector<POINT>> points) {
	//	bool found = false;
	//	input.erase(std::remove_if(input.begin(), input.end(), [&](const std::vector<int>& vec) {
	//		for (const auto& val : vec) {
	//			if (std::find_if(points->begin(), points->end(), [&](const POINT& point) { return point.x == val; }) == points->end()) {
	//				return true;
	//			}
	//		}
	//		found = true;
	//		return false;
	//	}), input.end());
	//
	//	return found;
	//}

public:
	bool check_for_Space(shared_ptr<vector<vector<POINT>>>& ptr_vector, const int ItemSize);
};


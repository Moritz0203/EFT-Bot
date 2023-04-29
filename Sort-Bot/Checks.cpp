#pragma once
#include "Checks.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <unordered_set>
#include <windows.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "getMat.h"
#include "InputMK.h"
#include "TemplateMatching.h"
#include "DistributorForMatching.h"
using namespace std;
using namespace cv;

void checksPublic::CheckScrollbarPositions() {
	Mat MatScreen;
	Mat templ;

	HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	MatScreen = GetMat::getMat(hWND);

	templ = imread("ObjectImages/scrollbar.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
	if (point.y > 79) {// Later with screen resolution
		point.y = (templ.rows / 2) + point.y;
		point.x = (templ.cols / 2) + point.x;
		Mouse::MoverPOINTandPress(point);
		int keyforInput = 0x21;// virtual-key code for the "PAGE UP KEY" key
		Keyboard::KeyboardInput(keyforInput);
	}

	POINT pointBarClick{};
	pointBarClick.y = 171;
	pointBarClick.x = 1903;
	Mouse::MoverPOINTandPress(pointBarClick);
}

void checksPublic::CheckForFails() {
	Mat MatScreen;
	Mat templ;
	POINT pointMouse = {};
	pointMouse.y = 729;
	pointMouse.x = 961;

	HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	MatScreen = GetMat::getMat(hWND);

	templ = imread("ObjectImages/Banner.png");
	POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.98);
	if (point.y || point.x != 0)
		Mouse::MoverPOINTandPress(pointMouse); //729 961
}

vector<vector<POINT>> findFreeSlots::SortINrows(vector<POINT> vector_Input) {
	vector<vector<POINT>> vector_return;
	vector<POINT> temp;
	unordered_set<int> unset;

	for (POINT point : vector_Input) {
		if (unset.find(point.y) == unset.end()) {
			unset.insert(point.y);

			for (POINT pointIN : vector_Input) {

				if (point.y == pointIN.y) {
					temp.push_back(pointIN);
				}
			}

			std::sort(temp.begin(), temp.end(), comparePoints);
			vector_return.push_back(temp);
			temp.clear();
		}
	}
	return vector_return;
}

bool findFreeSlots::comparePoints(const POINT& a, const POINT& b) {
	return a.x < b.x;
}


void findFreeSlots::findeSlots(POINT pointCase, shared_ptr<std::vector<std::vector<POINT>>> freeSlots) { //parent case must be open to use this function
	Mat MatScreen;
	Mat templ = imread("ObjectImages/EmptySquare.png");
	Matching matching;


	Mouse::MoverPOINTandPressTwoTimes(pointCase);

	HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(5);//Delete later
	MatScreen = GetMat::getMat(hWND);

	vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ, 0.99999);

	Clean_ReturnPoints = matching.removeDuplicates(ReturnPoints);

	FinalResults = SortINrows(Clean_ReturnPoints);

	*freeSlots = FinalResults;
}

void findFreeSlots::Print_Out_Case_EmptySlots() {
	if (!FinalResults.empty()) {
		for (int i = 0; i < FinalResults.size(); i++) {
			if (FinalResults[i].size() == 0) {
				cout << "       |->";
				cout << " Lines: " << std::to_string(i) << " Total slots: " << Clean_ReturnPoints.size() - 1 << endl;
				break;
			}

			int count = 0;
			int length = 0;
			string str = {};
			string strIE = {};
			string strER = {};

			for (POINT point : FinalResults[i]) {
				string strY = "Y:  " + std::to_string(point.y);
				string strX = "  ---  X:  " + std::to_string(point.x);
				strER = "       |-> ";
				str = strY + strX;

				cout << strER + str;
				length = 30 - str.length();
				for (int i2 = 0; i2 < length; i2++) {
					cout << " ";
				}

				strIE = "Index: " + std::to_string(i) + "  ---  Empty per line: " + std::to_string(++count);
				cout << strIE << "\n";
			}

			cout << "       |";
			for (int i2 = 0; i2 < ((strER.length() - 8) + length + str.length() + strIE.length()); i2++) {
				cout << "-";
			}
			cout << " " << strIE << "\n";
		}
		FinalResults.clear();
	}
	else {
		cout << "You must first call the function: findFreeSlots::findSlots()." << endl;
	}
}


bool Check_for_Space::One_Slot(shared_ptr<vector<vector<POINT>>>& ptr_vector) {
	for (vector<POINT>& row : *ptr_vector) {
		for (auto iterrator = row.begin(); iterrator != row.end(); ++iterrator) {
			row.erase(iterrator);
			return true;
		}
	}
	return false;
}

bool Check_for_Space::Vertical_Horizontal(shared_ptr<vector<vector<POINT>>>& ptr_vector, const SpecsForItem specsForItem) {
	vector<vector<POINT>> vector_row = (*ptr_vector);
	vector<vector<int>> points_for_LookUp{};
	vector<int> IN_temp_Pairs_for_LookUp{};
	shared_ptr<vector<POINT>> ptr_vector_row{};
	vector<shared_ptr<vector<POINT>>> vector_ptr_vector_row{};
	shared_ptr<vector<int>> ptr_vector_for_clean{};

	for (int i = 0; i < vector_row.size(); i++) {
		for (int i2 = 0; i2 < vector_row[i].size(); i2++) {
			int index = i2 + 1;
			int temp_LookUp = vector_row[i][i2].x + 63;
			bool break_tryNew = false;

			if (index == vector_row[i].size())
				break;

			IN_temp_Pairs_for_LookUp.push_back(vector_row[i][i2].x);
			for (int column = 1; column < specsForItem.columns; column++) {

				if (temp_LookUp == vector_row[i][index].x) {
					IN_temp_Pairs_for_LookUp.push_back(vector_row[i][index].x);

					int index_check = index + 1;
					if (index_check != vector_row[i].size())
						index++;
					else
						break;

					temp_LookUp += 63;
				}
				else {
					break_tryNew = true;
					IN_temp_Pairs_for_LookUp.clear();
					break;
				}
			}

			if (break_tryNew == false) {
				points_for_LookUp.push_back(IN_temp_Pairs_for_LookUp);
				IN_temp_Pairs_for_LookUp.clear();
			}

		}

		if (points_for_LookUp.size() != 0) {
			bool space_is_free = true;
			int index = i;

			for (int rows = 1; rows < specsForItem.rows; rows++) {

				if (++index == vector_row.size()) {
					space_is_free = false;
					break;
				}

				ptr_vector_row = make_shared<vector<POINT>>(vector_row[index]);
				vector_ptr_vector_row.push_back(ptr_vector_row);

				if (!check_Column(points_for_LookUp, ptr_vector_row)) {
					space_is_free = false;
					break;
				}
			}

			if (space_is_free) {
				ptr_vector_for_clean = make_shared<vector<int>>(points_for_LookUp[0]);
				remove_duplicates(vector_ptr_vector_row, ptr_vector_for_clean);
				return true;
			}
			else
				vector_ptr_vector_row.clear();

			points_for_LookUp.clear();
		}
	}
	return false;
}

void Check_for_Space::remove_duplicates(std::vector<std::shared_ptr<std::vector<POINT>>>& points, const std::shared_ptr<std::vector<int>>& values) {
	for (shared_ptr<vector<POINT>>& vec : points) {
		vec->erase(std::remove_if(vec->begin(), vec->end(),
			[&](const POINT& p) {
				return std::find(values->begin(), values->end(), p.x) != values->end();
			}), vec->end());
	}
}

bool Check_for_Space::check_Column(std::vector<std::vector<int>>& input, const std::shared_ptr<std::vector<POINT>>& points) {
	bool found = false;
	std::vector<std::vector<int>> result;
	for (const vector<int>& vec : input) {

		bool allMatch = true;
		for (const int& val : vec) {

			bool match = false;
			for (const POINT& point : *points) {
				if (point.x == val) {
					match = true;
					break;
				}
			}
			if (!match) {
				allMatch = false;
				break;
			}
		}
		if (allMatch) {
			found = true;
			result.push_back(vec);
		}
	}
	input = result;
	return found;
}

bool Check_for_Space::check_for_Space(shared_ptr<vector<vector<POINT>>>& ptr_vector, const int ItemSize) {
	SpecsForItem SlotsVertical;
	SpecsForItem SlotsHorizontal;

	switch (ItemSize)
	{
	case 1:
		if (One_Slot(ptr_vector))
			return true;
		else
			return false;

	case 2:
		SlotsVertical.rows = 1;
		SlotsVertical.columns = 2;

		SlotsHorizontal.rows = 2;
		SlotsHorizontal.columns = 1;

		if (Vertical_Horizontal(ptr_vector, SlotsVertical))
			return true;
		else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal))
			return true;
		else
			return false;


	case 3:
		SlotsVertical.rows = 1;
		SlotsVertical.columns = 3;

		SlotsHorizontal.rows = 3;
		SlotsHorizontal.columns = 1;

		if (Vertical_Horizontal(ptr_vector, SlotsVertical))
			return true;
		else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal))
			return true;
		else
			return false;


	case 4:
		//only vertical because it is a rectangle  
		SlotsVertical.rows = 2;
		SlotsVertical.columns = 2;

		if (Vertical_Horizontal(ptr_vector, SlotsVertical))
			return true;
		else
			return false;


	case 6:
		SlotsVertical.columns = 3;
		SlotsVertical.rows = 2;

		SlotsHorizontal.columns = 2;
		SlotsHorizontal.rows = 3;

		if (Vertical_Horizontal(ptr_vector, SlotsVertical))
			return true;
		else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal))
			return true;
		else
			return false;

	case 8:
		SlotsVertical.columns = 2;
		SlotsVertical.rows = 4;

		SlotsHorizontal.columns = 4;
		SlotsHorizontal.rows = 2;

		if (Vertical_Horizontal(ptr_vector, SlotsVertical))
			return true;
		else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal))
			return true;
		else
			return false;

	case 9:
		SlotsVertical.columns = 3;
		SlotsVertical.rows = 3;

		if (Vertical_Horizontal(ptr_vector, SlotsVertical))
			return true;
		else
			return false;
	}
}
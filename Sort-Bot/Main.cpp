//#include "StartUp.h"
#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include <utility>
#include <functional>
#include "ItemMoving.h"
#include "InitializeMovPrefix.h"
#include "DistributorForMatching.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "TemplateMatching.h"
#include "getMat.h"
#include "PointItems.h"
#include "ItemsProcessing.h"
#include "PrefixProcessing.h"
#include "Checks.h"
using namespace std;
using namespace cv;

//external controllers for applications / ECFA
//Rick and Morty Staffel 4 - Folge 4

//struct pair_hash {
//	template <class T1, class T2>
//	size_t operator()(const pair<T1, T2>& p) const {
//		return hash<T1>()(p.first) ^ hash<T2>()(p.second);
//	}
//};
//bool comparePoints(const POINT& a, const POINT& b);

//class findFreeSlots_test{
//	vector<vector<POINT>> FinalResults;
//	vector<POINT> Clean_ReturnPoints;
//
//	vector<vector<POINT>> SortINrows(vector<POINT> vector_Input) {
//		vector<vector<POINT>> vector_return;
//		vector<POINT> temp;
//		unordered_set<int> unset;
//
//		for (POINT point : vector_Input) {
//			if (unset.find(point.y) == unset.end()) {
//				unset.insert(point.y);
//
//				for (POINT pointIN : vector_Input) {
//
//					if (point.y == pointIN.y) {
//						temp.push_back(pointIN);
//					}
//				}
//
//				std::sort(temp.begin(), temp.end(), comparePoints);
//				vector_return.push_back(temp);
//				temp.clear();
//			}
//		}
//
//		return vector_return;
//	}
//
//	static bool comparePoints(const POINT& a, const POINT& b) {
//		return a.x < b.x;
//	}
//
//
//public:
//	vector<vector<POINT>> findeSlots(vector<POINT> ReturnPoints) { //parent case must be open to use this function
//		//Mat MatScreen;
//		//Mat templ = imread("ObjectImages/EmptySquare.png");
//		//int freeSlots = {};
//
//		//Mouse::MoverPOINTandPressTwoTimes(case_shared_ptr->point);
//
//		//HWND hWND = FindeWindow();
//		//SetForegroundWindow(hWND);
//		//Sleep(5);//Delete later
//		//MatScreen = getMat(hWND);
//
//		/*vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ, 0.99999);*/
//
//		Matching matching;
//
//		Clean_ReturnPoints = matching.removeDuplicates(ReturnPoints);
//
//		return FinalResults = SortINrows(Clean_ReturnPoints);
//
//		/*case_shared_ptr->freeSlots = FinalResults;*/
//	}
//
//	void Print_Out_Case_EmptySlots() {
//		if (!FinalResults.empty()) {
//			for (int i = 0; i < FinalResults.size(); i++) {
//				if (FinalResults[i].size() == 0) {
//					cout << "       |->";
//					cout << " Lines: " << std::to_string(i) << " Total slots: " << Clean_ReturnPoints.size() - 1 << endl;
//					break;
//				}
//
//				int count = 0;
//				int length = 0;
//				string str = {};
//				string strIE = {};
//				string strER = {};
//
//				for (POINT point : FinalResults[i]) {
//					string strY = "Y:  " + std::to_string(point.y);
//					string strX = "  ---  X:  " + std::to_string(point.x);
//					strER = "       |-> ";
//					str = strY + strX;
//
//					cout << strER + str;
//
//					length = 30 - str.length();
//
//					for (int i2 = 0; i2 < length; i2++) {
//						cout << " ";
//					}
//
//					strIE = "Index: " + std::to_string(i) + "  ---  Empty per line: " + std::to_string(++count);
//					cout << strIE << "\n";
//				}
//
//				cout << "       |";
//				for (int i2 = 0; i2 < ((strER.length() - 8) + length + str.length() + strIE.length()); i2++) {
//					cout << "-";
//				}
//				cout << " " << strIE << "\n";
//			}
//			FinalResults.clear();
//		}
//		else {
//			cout << "You must first call the function: findFreeSlots::findSlots()." << endl;
//		}
//	}
//};

//bool Vertical_Horizontal(shared_ptr<vector<vector<POINT>>> ptr_vector, SpecsForItem specsForItem);
//void remove_duplicates(std::vector<std::shared_ptr<std::vector<POINT>>>& points, std::shared_ptr<std::vector<int>> values);
//bool check_Column(std::vector<std::vector<int>>& input, std::shared_ptr<std::vector<POINT>>& points);
//bool Check_for_Space(shared_ptr<vector<vector<POINT>>> ptr_vector, int ItemSize);

//class Check_for_Space_test {
//	struct SpecsForItem {
//		int columns;
//		int rows;
//	};
//
//
//	bool One_Slot(shared_ptr<vector<vector<POINT>>> ptr_vector) {
//		for (vector<POINT>& row : *ptr_vector) {
//			for (auto iterrator = row.begin(); iterrator != row.end(); ++iterrator) {
//				row.erase(iterrator);
//				return true;
//			}
//		}
//		return false;
//	}
//
//	bool Vertical_Horizontal(shared_ptr<vector<vector<POINT>>> ptr_vector, SpecsForItem specsForItem) {
//		vector<vector<POINT>> vector_row = (*ptr_vector);
//		vector<vector<int>> points_for_LookUp{};
//		vector<int> IN_temp_Pairs_for_LookUp{};
//		shared_ptr<vector<POINT>> ptr_vector_row{};
//		vector<shared_ptr<vector<POINT>>> vector_ptr_vector_row{};
//		shared_ptr<vector<int>> ptr_vector_for_clean{};
//
//		for (int i = 0; i < vector_row.size(); i++) {
//			cout << "\nfirst in INDEX: " << i << endl;
//			for (int i2 = 0; i2 < vector_row[i].size(); i2++) {
//				cout << "second in" << endl;
//				int index = i2 + 1;
//				int temp_LookUp = vector_row[i][i2].x + 63;
//				bool break_tryNew = false;
//
//
//				if (index == vector_row[i].size()) {
//					cout << "Vector out of range\n" << endl;
//					break;
//				}
//
//				IN_temp_Pairs_for_LookUp.push_back(vector_row[i][i2].x);
//				for (int column = 1; column < specsForItem.columns; column++) {
//
//
//
//					cout << "in -- in " << index << endl;
//					if (temp_LookUp == vector_row[i][index].x) {
//						cout << "Points sind gleich --- " << temp_LookUp << " " << vector_row[i][index].x << "\n" << endl;
//						IN_temp_Pairs_for_LookUp.push_back(vector_row[i][index].x);
//
//						int index_check = index + 1;
//						if (index_check != vector_row[i].size())
//							index++;
//						else
//							break;
//
//						temp_LookUp += 63;
//					}
//					else {
//						cout << "die points sind nicht gleich --- " << temp_LookUp << " " << vector_row[i][index].x << "\n" << endl;
//						break_tryNew = true;
//						IN_temp_Pairs_for_LookUp.clear();
//						break;
//					}
//				}
//
//				if (break_tryNew == false) {
//					for (int x : IN_temp_Pairs_for_LookUp) {
//						cout << "X: " << x << " ";
//					}
//					points_for_LookUp.push_back(IN_temp_Pairs_for_LookUp);
//					IN_temp_Pairs_for_LookUp.clear();
//					cout << "--- Es wurden alle in einer reie gefunden\n\n" << endl;
//				}
//
//			}
//
//			if (points_for_LookUp.size() != 0) {
//				bool space_is_free = true;
//				int index = i;
//
//				for (int rows = 1; rows < specsForItem.rows; rows++) {
//					if (++index == vector_row.size()) {
//						space_is_free = false;
//						cout << "Check row vector out of range" << endl;
//						break;
//					}
//
//					ptr_vector_row = make_shared<vector<POINT>>(vector_row[index]);
//					vector_ptr_vector_row.push_back(ptr_vector_row);
//
//					if (!check_Column(points_for_LookUp, ptr_vector_row)) {
//						space_is_free = false;
//						break;
//					}
//				}
//
//				if (space_is_free) {
//					ptr_vector_for_clean = make_shared<vector<int>>(points_for_LookUp[0]);
//					remove_duplicates(vector_ptr_vector_row, ptr_vector_for_clean);
//					return true;
//				}
//				else {
//					vector_ptr_vector_row.clear();
//				}
//
//				points_for_LookUp.clear();
//			}
//		}
//
//		return false;
//	}
//
//	void remove_duplicates(std::vector<std::shared_ptr<std::vector<POINT>>>& points, std::shared_ptr<std::vector<int>> values) {
//		for (shared_ptr<vector<POINT>>& vec : points) {
//			vec->erase(std::remove_if(vec->begin(), vec->end(),
//				[&](const POINT& p) {
//					return std::find(values->begin(), values->end(), p.x) != values->end();
//				}), vec->end());
//		}
//	}
//
//	bool check_Column(std::vector<std::vector<int>>& input, std::shared_ptr<std::vector<POINT>>& points) {
//		bool found = false;
//		vector<vector<int>> result;
//		for (const vector<int>& vec : input) {
//
//			bool allMatch = true;
//			for (const int& val : vec) {
//
//				bool match = false;
//				for (const POINT& point : *points) {
//					if (point.x == val) {
//						match = true;
//						break;
//					}
//				}
//				if (!match) {
//					allMatch = false;
//					break;
//				}
//			}
//			if (allMatch) {
//				found = true;
//				result.push_back(vec);
//			}
//		}
//		input = result;
//		return found;
//	}
//
//	//bool check_Column_Lambda(std::vector<std::vector<int>>& input, std::shared_ptr<std::vector<POINT>> points) {
//	//	bool found = false;
//	//	input.erase(std::remove_if(input.begin(), input.end(), [&](const std::vector<int>& vec) {
//	//		for (const auto& val : vec) {
//	//			if (std::find_if(points->begin(), points->end(), [&](const POINT& point) { return point.x == val; }) == points->end()) {
//	//				return true;
//	//			}
//	//		}
//	//		found = true;
//	//		return false;
//	//	}), input.end());
//	//
//	//	return found;
//	//}
//
//public:
//	bool check_for_Space(shared_ptr<vector<vector<POINT>>> ptr_vector, int ItemSize) {
//		SpecsForItem SlotsVertical;
//		SpecsForItem SlotsHorizontal;
//
//		switch (ItemSize)
//		{
//		case 1:
//			if (One_Slot(ptr_vector)) {
//				cout << "es ist genug platz vorhanden" << endl;
//				return true;
//			}
//			else {
//				cout << "es ist nicht genug platz vorhanden" << endl;
//				return false;
//			}
//
//		case 2:
//			SlotsVertical.rows = 1;
//			SlotsVertical.columns = 2;
//
//			SlotsHorizontal.rows = 2;
//			SlotsHorizontal.columns = 1;
//
//			if (Vertical_Horizontal(ptr_vector, SlotsVertical)) {
//				cout << "es ist genug platz vorhanden Vertical" << endl;
//				return true; // genug Platz vorhanden
//			}
//			else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal)) {
//				cout << "es ist genug platz vorhanden Horizontal" << endl;
//				return true; // genug Platz vorhanden
//			}
//			else {
//				//Do something : wenn beides fehlschlägt
//				cout << "beides fehlgeschlagen" << endl;
//				return false;
//			}
//
//		case 3:
//			SlotsVertical.rows = 1;
//			SlotsVertical.columns = 3;
//
//			SlotsHorizontal.rows = 3;
//			SlotsHorizontal.columns = 1;
//
//			if (Vertical_Horizontal(ptr_vector, SlotsVertical)) {
//				cout << "es ist genug platz vorhanden Vertical" << endl;
//				return true; // genug Platz vorhanden
//			}
//			else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal)) {
//				cout << "es ist genug platz vorhanden Horizontal" << endl;
//				return true; // genug Platz vorhanden
//			}
//			else {
//				//Do something : wenn beides fehlschlägt
//				cout << "beides fehlgeschlagen" << endl;
//				return false;
//			}
//
//		case 4:
//			//only vertical because it is a rectangle  
//			SlotsVertical.rows = 2;
//			SlotsVertical.columns = 2;
//
//			if (Vertical_Horizontal(ptr_vector, SlotsVertical)) {
//				cout << "es ist genug platz vorhanden" << endl;
//				return true; // genug Platz vorhanden
//			}
//			else {
//				//Do something : wenn beides fehlschlägt
//				cout << "fehlgeschlagen" << endl;
//				return false;
//			}
//
//		case 6:
//			SlotsVertical.columns = 3;
//			SlotsVertical.rows = 2;
//
//			SlotsHorizontal.columns = 2;
//			SlotsHorizontal.rows = 3;
//
//			if (Vertical_Horizontal(ptr_vector, SlotsVertical)) {
//				cout << "es ist genug platz vor handen Vertical" << endl;
//				return true; // genug Platz vor handen
//			}
//			else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal)) {
//				cout << "es ist genug platz vor handen Horizontal" << endl;
//				return true; // genug Platz vor handen
//			}
//			else {
//				//Do something : wenn beides fehlschlägt
//				cout << "beides fehlgeschlagen" << endl;
//				return false;
//			}
//
//		case 8:
//			SlotsVertical.columns = 2;
//			SlotsVertical.rows = 4;
//
//			SlotsHorizontal.columns = 4;
//			SlotsHorizontal.rows = 2;
//
//			if (Vertical_Horizontal(ptr_vector, SlotsVertical)) {
//				cout << "es ist genug platz vor handen Vertical" << endl;
//				return true; // genug Platz vor handen
//			}
//			else if (Vertical_Horizontal(ptr_vector, SlotsHorizontal)) {
//				cout << "es ist genug platz vor handen Horizontal" << endl;
//				return true; // genug Platz vor handen
//			}
//			else {
//				//Do something : wenn beides fehlschlägt
//				cout << "beides fehlgeschlagen" << endl;
//				return false;
//			}
//
//		case 9:
//			SlotsVertical.columns = 3;
//			SlotsVertical.rows = 3;
//
//			if (Vertical_Horizontal(ptr_vector, SlotsVertical)) {
//				cout << "es ist genug platz vor handen" << endl;
//				return true; // genug Platz vor handen
//			}
//			else {
//				//Do something : wenn beides fehlschlägt
//				cout << "fehlgeschlagen" << endl;
//				return false;
//			}
//		}
//
//
//	}
//};






//extern void CombinePrefixAndCase();



//std::vector<std::vector<PointItem*>> combineVectors(
//	const std::vector<std::vector<PointAmmunition>>& vecAmmunition,
//	const std::vector<std::vector<PointMagazine>>& vecMagazine,
//	const std::vector<std::vector<PointBarter>>& vecBarter) {
//
//	std::vector<std::vector<PointItem*>> result;
//
//	size_t max_size = std::max({ vecAmmunition.size(), vecMagazine.size(), vecBarter.size() });
//
//	for (size_t i = 0; i < max_size; ++i) {
//		std::vector<PointItem*> row;
//		if (i < vecAmmunition.size()) {
//			for (const auto& item : vecAmmunition[i]) {
//				row.push_back(new PointAmmunition(item));
//			}
//		}
//		if (i < vecMagazine.size()) {
//			for (const auto& item : vecMagazine[i]) {
//				row.push_back(new PointMagazine(item));
//			}
//		}
//		if (i < vecBarter.size()) {
//			for (const auto& item : vecBarter[i]) {
//				row.push_back(new PointBarter(item));
//			}
//		}
//		result.push_back(row);
//	}
//
//	return result;
//}


//bool operator==(const POINT& lhs, const POINT& rhs) {
//	return lhs.x == rhs.x && lhs.y == rhs.y;
//}
//
//void deleteMatchingPoints_test(std::vector<PointItem*>& pointItems, std::shared_ptr<std::vector<POINT>> points) {
//	std::vector<PointItem*> result;
//	for (auto it = pointItems.begin(); it != pointItems.end(); ++it) {
//		bool matchFound = false;
//		for (auto jt = points->begin(); jt != points->end(); ++jt) {
//			if ((*it)->point == *jt) {
//				matchFound = true;
//				break;
//			}
//		}
//		if (!matchFound) {
//			result.push_back(*it);
//		}
//	}
//	pointItems = result;
//}


int main() {
	
	
  /*cout << "//    ___ ___ _____         ___  ___  ___ _____         ___  ___ _____  " << endl;
	cout << "//   | __| __|_   _|  ___  / __|/ _ \| _ \_   _|  ___  | _ )/ _ \_   _| " << endl;
	cout << "//   | _|| _|  | |   |___| \__ \ (_) |   / | |   |___| | _ \ (_) || |   " << endl;
	cout << "//   |___|_|   |_|      _  |___/\___/|_|_\_|_|_ _      |___/\___/ |_|   " << endl;
	cout << "//                     | |__ _  _  | __/ __| __/_\                      " << endl;
	cout << "//                     | '_ \ || | | _| (__| _/ _ \                     " << endl;
	cout << "//                     |_.__/\_, | |___\___|_/_/ \_\                    " << endl;
	cout << "//                           |__/                                       " << endl;*/

	cout << "Welcome to EFT-SORT-BOT" << endl;
	cout << "by ECFA" << endl;
	cout << endl;
		
	
	/*InitializeMovPrefix::Initialize();*/



	HWND hWND = GetMat::FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(100);
	Mat MatScreen = GetMat::getMat(hWND);
	

	string Start = "start";
	
	//cin >> Start;

	if (Start == "start") {
		ItemMoving itemMoving;
		PrefixProcessing prefixProcessing;
		ItemsProcessing	itemsProcessing;		
		checksPublic ChecksPublic;
		GetMat getMat;



		ChecksPublic.CheckScrollbarPositions();
		Sleep(300);
		getMat.TakeScreenshots();

		InitializeMovPrefix::Initialize();
		prefixProcessing.CombinePrefixAndCase();

		for (vector<PointCaseInStash> vec : PointCaseInStash::pointCaseInStash_C) {
			for (PointCaseInStash Point : vec) {
				cout << Point.nameOfCase << " " << Point.tagCase << " " << Point.prefix.nameOfItems.size() <<" \n";
				for (string str : Point.prefix.nameOfItems) {
					cout << str << endl;
				}
				cout << Point.freeSlots.size() << endl;
			}
			cout << "\n" << endl;
		}


		//itemsProcessing.AmmunitionProcess();
		//itemMoving.itemMoving();
	}
	else {













		//PointAmmunition pointAmmo;
		//pointAmmo.heightTempl = {};
		//pointAmmo.widthTempl = {};
		//pointAmmo.nameOfItem = "ItemAmo";
		//pointAmmo.page = 0;
		//pointAmmo.point.y = 2;
		//pointAmmo.point.x = 4;
		//pointAmmo.stackSize = 354;

		//PointAmmunition pointAmmo1;
		//pointAmmo1.heightTempl = {};
		//pointAmmo1.widthTempl = {};
		//pointAmmo1.nameOfItem = "ItemAmo1";
		//pointAmmo1.page = 1;
		//pointAmmo1.point.y = 2;
		//pointAmmo1.point.x = 4;
		//pointAmmo1.stackSize = 354;

		//PointAmmunition pointAmmo2;
		//pointAmmo2.heightTempl = {};
		//pointAmmo2.widthTempl = {};
		//pointAmmo2.nameOfItem = "ItemAmo2";
		//pointAmmo2.page = 2;
		//pointAmmo2.point.y = 2;
		//pointAmmo2.point.x = 4;
		//pointAmmo2.stackSize = 354;

		//PointAmmunition pointAmmo4;
		//pointAmmo4.heightTempl = {};
		//pointAmmo4.widthTempl = {};
		//pointAmmo4.nameOfItem = "ItemAmo3";
		//pointAmmo4.page = 3;
		//pointAmmo4.point.y = 2;
		//pointAmmo4.point.x = 4;
		//pointAmmo4.stackSize = 354;

		//vector<vector<PointAmmunition>> vecAmmo{ {pointAmmo,pointAmmo,pointAmmo,pointAmmo,pointAmmo},{pointAmmo1,pointAmmo1,pointAmmo1,pointAmmo1,pointAmmo1},{pointAmmo2,pointAmmo2,pointAmmo2,pointAmmo2,pointAmmo2,pointAmmo2},{pointAmmo4,pointAmmo4,pointAmmo4,pointAmmo4} };


		//PointMagazine pointMag;
		//pointMag.heightTempl = {};
		//pointMag.widthTempl = {};
		//pointMag.nameOfItem = "ItemMag";
		//pointMag.page = 0;
		//pointMag.point.y = 2;
		//pointMag.point.x = 4;
		//pointMag.fillStatus = 34;

		//PointMagazine pointMag1;
		//pointMag1.heightTempl = {};
		//pointMag1.widthTempl = {};
		//pointMag1.nameOfItem = "ItemMag1";
		//pointMag1.page = 1;
		//pointMag1.point.y = 2;
		//pointMag1.point.x = 4;
		//pointMag1.fillStatus = 34;

		//PointMagazine pointMag2;
		//pointMag2.heightTempl = {};
		//pointMag2.widthTempl = {};
		//pointMag2.nameOfItem = "ItemMag2";
		//pointMag2.page = 2;
		//pointMag2.point.y = 24;
		//pointMag2.point.x = 4;
		//pointMag2.fillStatus = 34;

		//PointMagazine pointMag3;
		//pointMag3.heightTempl = {};
		//pointMag3.widthTempl = {};
		//pointMag3.nameOfItem = "ItemMag3";
		//pointMag3.page = 3;
		//pointMag3.point.y = 24;
		//pointMag3.point.x = 4;
		//pointMag3.fillStatus = 34;

		//vector<vector<PointMagazine>> vecMag{ {pointMag,pointMag,pointMag,pointMag,pointMag},{pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1,pointMag1},{pointMag2,pointMag2,pointMag2,pointMag2,pointMag2,pointMag2},{pointMag3,pointMag3,pointMag3,pointMag3} };


		//PointBarter pointBar;
		//pointBar.heightTempl = {};
		//pointBar.widthTempl = {};
		//pointBar.nameOfItem = "ItemBar";
		//pointBar.page = 0;
		//pointBar.point.y = 4;
		//pointBar.point.x = 2;
		//pointBar.isFoundInRaid = false;

		//PointBarter pointBar1;
		//pointBar1.heightTempl = {};
		//pointBar1.widthTempl = {};
		//pointBar1.nameOfItem = "ItemBar1";
		//pointBar1.page = 1;
		//pointBar1.point.y = 2;
		//pointBar1.point.x = 4;
		//pointBar1.isFoundInRaid = true;

		//PointBarter pointBar2;
		//pointBar2.heightTempl = {};
		//pointBar2.widthTempl = {};
		//pointBar2.nameOfItem = "ItemBar2";
		//pointBar2.page = 2;
		//pointBar2.point.y = 22;
		//pointBar2.point.x = 4;
		//pointBar2.isFoundInRaid = false;

		//PointBarter pointBar3;
		//pointBar3.heightTempl = {};
		//pointBar3.widthTempl = {};
		//pointBar3.nameOfItem = "ItemBar3";
		//pointBar3.page = 3;
		//pointBar3.point.y = 23;
		//pointBar3.point.x = 4;
		//pointBar3.isFoundInRaid = true;

		//vector<vector<PointBarter>> vecBar{ {pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar},{pointBar1,pointBar1,pointBar1,pointBar1,pointBar1},{pointBar2,pointBar2,pointBar2,pointBar2,pointBar2,pointBar2},{pointBar3,pointBar3,pointBar3,pointBar3}, {pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar,pointBar} };

		//POINT point;
		//point.y = 2;
		//point.x = 4;

		//vector<POINT> toclear{ point, point,point,point,point,point,point,point };


		//std::vector<std::vector<PointItem*>> result = combineVectors(vecAmmo, vecMag, vecBar);

		////for (const auto& row : result) {
		//	for (PointItem* item : result[0]) {
		//		if (PointAmmunition* ammo = dynamic_cast<PointAmmunition*>(item)) {
		//			// item is a PointAmmunition object, so we can access its members and methods through the ammo pointer
		//			cout << ammo->page << " " << ammo->nameOfItem << " " << ammo->stackSize << endl;
		//		}
		//		else if (PointMagazine* mag = dynamic_cast<PointMagazine*>(item)) {
		//			// item is a PointMagazine object, so we can access its members and methods through the mag pointer
		//			cout << mag->page << " " << mag->nameOfItem << " " << mag->fillStatus << endl;
		//		}
		//		else if (PointBarter* barter = dynamic_cast<PointBarter*>(item)) {
		//			// item is a PointBarter object, so we can access its members and methods through the barter pointer
		//			cout << barter->page << " " << barter->nameOfItem << " " << barter->isFoundInRaid << endl;
		//		}
		//		/*else {
		//			cout << item->page << " " << item->nameOfItem << endl;
		//		}*/
		//	}
		//	cout << "\n" << endl;
		////}
		//	std::vector<PointItem*> test2 = result[0];
		//
		//	shared_ptr<std::vector<PointItem*>> clear = make_shared< std::vector<PointItem*>>(test2);
		//	shared_ptr<std::vector<POINT>> to_clear = make_shared< std::vector<POINT>>(toclear);

		//	deleteMatchingPoints_test(test2, to_clear);

		//	std::vector<PointItem*> updatedClear = *clear;

		//	//result[0] = New;

		//	

		//	for (PointItem* item : test2) {
		//		if (PointAmmunition* ammo = dynamic_cast<PointAmmunition*>(item)) {
		//			// item is a PointAmmunition object, so we can access its members and methods through the ammo pointer
		//			cout << ammo->page << " " << ammo->nameOfItem << " " << ammo->stackSize << endl;
		//		}
		//		else if (PointMagazine* mag = dynamic_cast<PointMagazine*>(item)) {
		//			// item is a PointMagazine object, so we can access its members and methods through the mag pointer
		//			cout << mag->page << " " << mag->nameOfItem << " " << mag->fillStatus << endl;
		//		}
		//		else if (PointBarter* barter = dynamic_cast<PointBarter*>(item)) {
		//			// item is a PointBarter object, so we can access its members and methods through the barter pointer
		//			cout << barter->page << " " << barter->nameOfItem << " " << barter->isFoundInRaid << endl;
		//		}
		//		/*else {
		//			cout << item->page << " " << item->nameOfItem << endl;
		//		}*/
		//	}
		//	cout << "\n" << endl;

		/*for (vector<PointItem*> in : result) {
^^			for (PointItem* point : in) {
				cout << point->page << " " << point->nameOfItem << endl;
			}
			cout <<  "\n" << endl;
		}*/


		//Mat templ;+
		//Mat templ1;

		////Mat MatScreen = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_3.png");
		//
		///*vector<POINT> ReturnPoints;*/
		//vector<POINT> ReturnPoints;
		//templ = imread("ObjectImages/SortingTable.png");
		//templ1 = imread("ObjectImages/EmptySquare.png");
		//const char* image_window = "Source Image";
		//namedWindow(image_window, WINDOW_AUTOSIZE);
		///*const char* image_window2 = "Source Image2222222222";
		//namedWindow(image_window2, WINDOW_AUTOSIZE);*/

		//TemplateMatching::templateMatchingItems("CaseImages/JunkCase.png", 0.88, false, false, "BP", ReturnPoints, MatScreen);

		//ReturnPoints = Matching::removeDuplicates(ReturnPoints);

		//cout << endl;
		//for (POINT point : ReturnPoints) {
		//	cout << point.y << " " << point.x << endl;
		//}

		//POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.99);
		//point.y = (templ.rows / 2) + point.y;
		//point.x = (templ.cols / 2) + point.x;

		////Mouse::MoverPOINTandPress(point);

		//Sleep(200);

		//POINT pointA, pointB;

		//pointA.y = (templ.rows / 2) + ReturnPoints[0].y;
		//pointA.x = (templ.cols / 2) + ReturnPoints[0].x;

		//pointB.y = MatScreen.rows / 2;
		//pointB.x = MatScreen.cols / 2;

		////Mouse::MouseMoveAtoB(pointA, pointB);

		//cout << MatScreen.cols << " " << MatScreen.rows;



		/*Sleep(40);

		Mat MatScreen = getMat(hWND);

		vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ1, 0.99);



		findFreeSlots_test findFreeSlots1;
		vector<vector<POINT>> FinalResult = findFreeSlots1.findeSlots(ReturnPoints);

		findFreeSlots1.Print_Out_Case_EmptySlots();*/

		/*shared_ptr<vector<vector<POINT>>> ptr_vector = make_shared<vector<vector<POINT>>>(FinalResult);

		Check_for_Space_test check_Space;
		check_Space.check_for_Space(ptr_vector, 2);*/



		//ItemsProcessing::AmmunitionProcess();




		/*Mat MatScreen1 = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_3.png");

		vector<POINT> ReturnPoints1 = TemplateMatching::templateMatchingObjects_Vector(MatScreen1, templ1, 0.99999);


		findFreeSlots1.findeSlots(ReturnPoints1);

		findFreeSlots1.Print_Out_Case_EmptySlots();*/

		/*for (int i = 0; i < ReturnPoints.size(); i++) {
			cout << ReturnPoints[i].y << " " << ReturnPoints[i].x << "----2 - " << i << endl;
		}*/


		//cv::Rect rec; 

		//rec.height = templ.cols;
		//rec.width = templ.rows;
		//rec.x = ReturnPoints[0].x;
		//rec.y = ReturnPoints[0].y;

		/*ColorMatching::colorMatching(rec, MatScreen);*/


		//TemplateMatching::templateMatchingItems("CaseImages/AmmoCase.png", 0.90, false, false, "amo", ReturnPoints1, MatScreen);

		///*cout << ReturnPoints[0].y << " " << ReturnPoints[0].x << endl;
		//cout << ReturnPoints1[0].y << " " << ReturnPoints1[0].x << endl;*/

		//POINT pointA{};
		//POINT pointB{};

		//pointB.y = (templ1.rows / 2) + ReturnPoints1[0].y;
		//pointB.x = (templ1.cols / 2) + ReturnPoints1[0].x;



		///*unordered_set<int> unSet;
		//vector<POINT> result;
		//for (POINT point : ReturnPoints) {
		//	int x_minus_1 = point.x - 1;
		//	int x_plus_1 = point.x + 1;
		//	if (unSet.find(point.x) == unSet.end() && unSet.find(x_minus_1) == unSet.end() && unSet.find(x_plus_1) == unSet.end()) {
		//		result.push_back(point);
		//		unSet.insert(point.x);
		//		unSet.insert(x_minus_1);
		//		unSet.insert(x_plus_1);
		//	}
		//}*/


		/*unordered_set<pair<int, int>, pair_hash> unSet;
		vector<POINT> result;
		for (POINT& point : ReturnPoints) {
			int x_minus_1 = point.x - 1;
			int x_plus_1 = point.x + 1;
			int y_minus_1 = point.y - 1;
			int y_plus_1 = point.y + 1;
			pair<int, int> point_x = make_pair(point.x, point.y);
			pair<int, int> point_x_minus_1 = make_pair(x_minus_1, point.y);
			pair<int, int> point_x_plus_1 = make_pair(x_plus_1, point.y);
			pair<int, int> point_y = make_pair(point.x, point.y);
			pair<int, int> point_y_minus_1 = make_pair(point.x, y_minus_1);
			pair<int, int> point_y_plus_1 = make_pair(point.x, y_plus_1);
			if (unSet.find(point_x) == unSet.end() && unSet.find(point_x_minus_1) == unSet.end() && unSet.find(point_x_plus_1) == unSet.end()
				&& unSet.find(point_y) == unSet.end() && unSet.find(point_y_minus_1) == unSet.end() && unSet.find(point_y_plus_1) == unSet.end()) {
				result.push_back(point);
				unSet.insert(point_x);
				unSet.insert(point_x_minus_1);
				unSet.insert(point_x_plus_1);
				unSet.insert(point_y);
				unSet.insert(point_y_minus_1);
				unSet.insert(point_y_plus_1);
			}
		}




		for (int i = 0; i < result.size(); i++) {
			cout << result[i].y << " " << result[i].x << " ---- " << i << endl;
		}

		vector<vector<POINT>> JunkCase;
		vector<POINT> temp;
		unordered_set<int> unset;

		for (POINT point : result) {
			if (unset.find(point.y) == unset.end()) {
				unset.insert(point.y);

				for (POINT pointIN : result) {

					if (point.y == pointIN.y) {
						temp.push_back(pointIN);
					}
				}

				std::sort(temp.begin(), temp.end(), comparePoints);
				JunkCase.push_back(temp);
				temp.clear();
			}

		}




		for (int i = 0; i < JunkCase.size(); i++) {
			int count = 0;
			int length = 0;
			string str = {};
			string strIE = {};
			string strER = {};

			if (JunkCase[i].size() == 0)
				break;

			for (POINT point : JunkCase[i]) {
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

		cout << ReturnPoints.size() << endl;*/

		//for (int i = 0; i < result.size(); i++) {
		//	pointA.y = (templ.rows / 2) + result[i].y;
		//	pointA.x = (templ.cols / 2) + result[i].x;

		//	Mouse::MouseMoveAtoB(pointA, pointB);
		//}

		//cout << "------" << endl;
		//
		//Rect Rec(ReturnPoints[0].x + 45, ReturnPoints[0].y + 46, templ.cols - 45, templ.rows - 46);
		////Rect Rec(ReturnPoints[0].x , ReturnPoints[0].y , templ.cols, templ.rows );

		//Mat Roi2;
		//Mat Roi = MatScreen(Rec);


		/*Mat temp = imread("ObjectImages/FoundInRaid/FoundInRaid-Blue.png");
		if (TemplateMatching::templateMatchingBool(Roi, temp, 0.99)) {
			cout << "found in raid" << endl;
		}*/

		/*Mat blacktext = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_5.png");

		cv::imshow(image_window, blacktext);

		TextMatching::txttest(blacktext);*/

		/*MatScreen = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_5.png");*/

		/*const string str = TextMatching::textMatching(MatScreen, Rec);

		cout << str << endl;*/


		//const char test = '-';
		///*if (str[9] == test) {
		//	cout << "test" << endl;
		//}*/

		//int i1 = -1;
		//for (int i = 0; i < str.length(); i++) {
		//	i1++;
		//	cout << str[i] << " --- " << i1 << endl;
		//}

		//cout << str[str.back() - 1] << "<------ " << i1 << endl;

		/*cout << "123" << endl;*/
		//imshow(image_window, Roi);
		///*imshow(image_window2, Roi2);*/
		//waitKey(0);


		//cv::cvtColor(Roi, Roi, cv::COLOR_BGR2HSV);

		//if (!ReturnPoints[0].y <= 500) {
		//	/*Roi2 = Roi + cv::Scalar(-17, -17, -17);*/
		//	Roi2 = Roi + cv::Scalar(-20, -20, -20);
		//	cout << "hey" << endl;
		//}

		//int i{}, i2{}, i3{};
		//while (true)
		//{
		//	i--;
		//	i2--;
		//	i3--;
		//	Roi2 = Roi + cv::Scalar(i, i2, i3);	

		//	color = TemplateMatching::ColorMatching(Rec, Roi2);

		//	system("cls");
		//	cout << color << " " << "color " << i << " " << i2 << " " << i3 <<  endl;
		//	if (color == 0)// Green -34 / Blue -64 / 
		//		break;
		//}

		/*color = TemplateMatching::ColorMatching(Rec, Roi);

		cout << color << " " << "color" << endl;*/

		/*CaseMatching::THICCcase();*/
	//}

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/

	}
	
}

bool comparePoints(const POINT& a, const POINT& b) {
	return a.x < b.x;
}
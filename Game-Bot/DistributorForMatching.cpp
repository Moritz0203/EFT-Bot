#pragma once
#include "DistributorForMatching.h"
#include "TemplateMatching.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include "getMat.h"
using namespace cv;
using namespace std;

struct pair_hash {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		return hash<T1>()(p.first) ^ hash<T2>()(p.second);
	}
};

__forceinline bool Matching::checkSecondLastChar(string& tagCase) {
	tagCase.erase(remove(tagCase.begin(), tagCase.end(), ' '), tagCase.end());
	int length = tagCase.length();
	
	if (!tagCase.empty()) {
		tagCase.pop_back();
	}

	if (length >= 2) {
		return (tagCase[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - 2] != '/');
	}
	return false;
}

vector<POINT> Matching::removeDuplicates(vector<POINT>& points) {
	unordered_set<pair<int, int>, pair_hash> unSet;
	vector<POINT> result;
	for (POINT& point : points) {
		bool shouldInsert = true;
		for (int i = -20; i <= 20; i++) {
			pair<int, int> point_x = make_pair(point.x + i, point.y);
			pair<int, int> point_y = make_pair(point.x, point.y + i);
			if (unSet.find(point_x) != unSet.end() || unSet.find(point_y) != unSet.end()) {
				shouldInsert = false;
				break;
			}
		}
		if (shouldInsert) {
			result.push_back(point);
			for (int i = -20; i <= 20; i++) {
				pair<int, int> point_x = make_pair(point.x + i, point.y);
				pair<int, int> point_y = make_pair(point.x, point.y + i);
				unSet.insert(point_x);
				unSet.insert(point_y);
			}
		}
	}

	for (POINT& point : result) {
		point.x += 1200;
	}

	return result;
}

//vector<PointAmmunition> Matching::removeDuplicatesPage(vector<PointAmmunition>& points) {
//	unordered_set<pair<int, int>, pair_hash> unSet;
//	vector<PointAmmunition> result;
//
//	for (PointAmmunition& pointAmmunition : points) {
//		bool shouldInsert = true;
//		for (int i = -10; i <= 10; i++) {
//			pair<int, int> point_x = make_pair(pointAmmunition.point.x + i, pointAmmunition.point.y);
//			pair<int, int> point_y = make_pair(pointAmmunition.point.x, pointAmmunition.point.y + i);
//			if (unSet.find(point_x) != unSet.end() || unSet.find(point_y) != unSet.end()) {
//				shouldInsert = false;
//				break;
//			}
//		}
//		if (shouldInsert) {
//			result.push_back(pointAmmunition);
//			for (int i = -10; i <= 10; i++) {
//				pair<int, int> point_x = make_pair(pointAmmunition.point.x + i, pointAmmunition.point.y);
//				pair<int, int> point_y = make_pair(pointAmmunition.point.x, pointAmmunition.point.y + i);
//				unSet.insert(point_x);
//				unSet.insert(point_y);
//			}
//		}
//	}
//	return result;
//}


//void Matching::AmmunitionMatching(vector<PathNameThreshold> input) {
//	//cout << "amo matching" << endl;
//	Mat templ;
//	Mat MatScreen;
//	GetMat getMat;
//	//const char* image_window = "Ammunition Image";
//	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();
//
//	vector<POINT> ReturnDataAM;
//	vector<POINT> ReturnDataAM_Clean;
//	vector<PointAmmunition> pointAmmunitionTemp;
//
//
//	int count = 0;
//	for (int i1 = 0; i1 < MatScreenVector.size(); i1++) {
//			
//		Rect Rec(1200, 0, MatScreenVector[i1].cols - 1200, MatScreenVector[i1].rows);
//		MatScreen = MatScreenVector[i1](Rec);
//		
//		for (int i = 0; i < input.size(); i++) {
//			ReturnDataAM = TemplateMatching::templateMatchingItems(input[i].Path, input[i].Threshold, false, true, input[i].Name, MatScreen);
//
//			templ = imread(input[i].Path);
//			if (!ReturnDataAM.empty()) {
//				ReturnDataAM_Clean = removeDuplicates(ReturnDataAM);
//
//				for (int i2 = 0; i2 < ReturnDataAM_Clean.size(); i2++) {
//					const Rect Rec(ReturnDataAM_Clean[i2].x + 44, ReturnDataAM_Clean[i2].y + 48, templ.cols - 44, templ.rows - 48);
//					const string stackSize = "2"/*TextMatching::textMatching(arrayMatScreen[i1], Rec)*/;
//					const int stackSizeConvertet = stoi(stackSize);
//					pointAmmunitionTemp.emplace_back(ReturnDataAM_Clean[i2], input[i].Name, templ.rows, templ.cols, i1, 1, stackSizeConvertet);
//				}
//				ReturnDataAM.clear();
//				ReturnDataAM_Clean.clear();
//			}
//		}
//		
//		pointAmmunitionTemp = removeDuplicatesPage(pointAmmunitionTemp);
//
//		for (PointAmmunition &pointAM : pointAmmunitionTemp) {
//			PointAmmunition::pointAmmunition_NC[i1].emplace_back(pointAM);
//		}
//
//		pointAmmunitionTemp.clear();
//		//cout << "--------------- " << ++count << endl;
//	}
//	//cout << "mamo done" << endl;
//}


void Matching::CaseMatching(vector<PathNameThreshold> input) {
	Mat templ;
	GetMat getMat;

	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();
	//const char* image_window = "Case Image";

	vector<POINT> ReturnDataCase;
	vector<POINT> ReturnDataCase_Clean;
	vector<vector<POINT>> freeSlots_empty{};
	vector<PointCaseInStash> pointCasetempStashTemp;
	vector<PointMedical> PointMedical_empty{};
	int page = 0;

	for (Mat MatScreen : MatScreenVector) {

		Rect Rec(1200, 0, MatScreen.cols - 1200, MatScreen.rows);
		Mat MatScreenTemp = MatScreen(Rec);

		for (int i = 0; i < input.size(); i++) {

			ReturnDataCase = TemplateMatching::templateMatchingItems(input[i].Path, input[i].Threshold, false, true, input[i].Name, MatScreenTemp);

			templ = imread(input[i].Path);
			if (!ReturnDataCase.empty()) {
				ReturnDataCase_Clean = removeDuplicates(ReturnDataCase);

				for (int i3 = 0; i3 < ReturnDataCase_Clean.size(); i3++) {
					double rows = templ.rows;
					rows -= rows / 3.0;
					const Rect Rec(ReturnDataCase_Clean[i3].x + 2, ReturnDataCase_Clean[i3].y, rows, 12);
					string tagCase = TextMatching::textMatching(MatScreen, Rec);

					if (checkSecondLastChar(tagCase)) {
						pointCasetempStashTemp.emplace_back(ReturnDataCase_Clean[i3], input[i].Name, tagCase, templ.rows, templ.cols, page, PointMedical_empty);
					}
				}
				ReturnDataCase.clear();
				ReturnDataCase_Clean.clear();
			}
		}
		PointCaseInStash::pointCaseInStash_NC.emplace_back(pointCasetempStashTemp);
		pointCasetempStashTemp.clear();
		page++;
	}
}

void Matching::MedicalMatching_OneScreen(vector<PathNameThresholdItemSizeMaxHP> input, shared_ptr<vector<PointMedical>> ptr_MedicalVec, Mat MatScreen) {
	Mat templ;
	vector<POINT> ReturnDataMedical;
	vector<POINT> ReturnDataMedical_Clean;

	Rect Rec(730, 300, MatScreen.cols - 1460, MatScreen.rows - 600);
	Mat MatScreenTemp = MatScreen(Rec);

	for (int i = 0; i < input.size(); i++) {

		ReturnDataMedical = TemplateMatching::templateMatchingItems(input[i].Path, input[i].Threshold, false, true, input[i].Name, MatScreenTemp);

		templ = imread(input[i].Path);
		if (!ReturnDataMedical.empty()) {
			ReturnDataMedical_Clean = removeDuplicates(ReturnDataMedical);

			for (int i3 = 0; i3 < ReturnDataMedical_Clean.size(); i3++) {
				double rows = templ.rows;
				rows -= rows / 3.0;
				const Rect Rec(ReturnDataMedical_Clean[i3].x + 2, ReturnDataMedical_Clean[i3].y, rows, 12);
				string tagCase = TextMatching::textMatching(MatScreen, Rec);

				if (checkSecondLastChar(tagCase)) {
					ptr_MedicalVec->emplace_back(ReturnDataMedical_Clean[i3], input[i].Name, templ.rows, templ.cols, NULL, input[i].ItemSize, 10, input[i].MaxHp);
				}
			}
		}
	}
}


//std::array<std::string, 2> FoundInRaid{
//	"ObjectImages/FoundInRaid/FoundInRaid-Blue.png",
//	"ObjectImages/FoundInRaid/FoundInRaid-Red.png"
//};

//void Matching::BarterMatching(vector<PathNameThresholdItemSize> input, vector<vector<PointBarter>> &input_vec) {
//	const int sizeFoundInRaid = sizeof(FoundInRaid) / sizeof(String);
//	Mat templ;
//	Mat MatScreen;
//	GetMat getMat;
//	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();
//
//	vector<POINT> ReturnDataBA;
//	vector<POINT> ReturnDataBA_Clean;
//	vector<PointBarter> pointBarterTemp;
//
//	int count = 0;
//	for (int i1 = 0; i1 < MatScreenVector.size(); i1++) {
//		Rect Rec(1200, 0, MatScreenVector[i1].cols - 1200, MatScreenVector[i1].rows);
//		MatScreen = MatScreenVector[i1](Rec);
//
//		for (int i = 0; i < input.size(); i++) {
//			ReturnDataBA = TemplateMatching::templateMatchingItems(input[i].Path, input[i].Threshold, false, true, input[i].Name, MatScreen);
//
//			templ = imread(input[i].Path);
//			if (!ReturnDataBA.empty()) {
//				ReturnDataBA_Clean = removeDuplicates(ReturnDataBA);
//
//				for (int i3 = 0; i3 < ReturnDataBA_Clean.size(); i3++) {
//					const Rect Rec(ReturnDataBA_Clean[i3].x + 45, ReturnDataBA_Clean[i3].y + 46, templ.cols - 45, templ.rows - 46);
//					
//					for (int i4 = 0; i4 < sizeFoundInRaid; i4++) {
//						Mat temp = imread(FoundInRaid[i4]);
//						if (TemplateMatching::templateMatchingBool(MatScreenVector[i1](Rec), temp, 0.99)) {
//							pointBarterTemp.emplace_back(ReturnDataBA_Clean[i3], input[i].Name, templ.rows, templ.cols, i1, input[i].ItemSize, true);
//							break;
//						}
//						else {
//							pointBarterTemp.emplace_back(ReturnDataBA_Clean[i3], input[i].Name, templ.rows, templ.cols, i1, input[i].ItemSize, false); 
//							break;
//						}
//					}
//				}
//				ReturnDataBA.clear();
//				ReturnDataBA_Clean.clear();
//			}
//		}
//
//		for (PointBarter& pointAM : pointBarterTemp) {
//			input_vec[i1].emplace_back(pointAM);
//		}
//
//		pointBarterTemp.clear();
//	}
//	cout << input_vec.size() << endl;
//}
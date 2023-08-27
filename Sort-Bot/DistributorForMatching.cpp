#pragma once
#include "DistributorForMatching.h"
#include "TemplateMatching.h"
#include "PointGlobalVector.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
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
		for (int i = -10; i <= 10; i++) {
			pair<int, int> point_x = make_pair(point.x + i, point.y);
			pair<int, int> point_y = make_pair(point.x, point.y + i);
			if (unSet.find(point_x) != unSet.end() || unSet.find(point_y) != unSet.end()) {
				shouldInsert = false;
				break;
			}
		}
		if (shouldInsert) {
			result.push_back(point);
			for (int i = -10; i <= 10; i++) {
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

vector<PointAmmunition> Matching::removeDuplicatesPage(vector<PointAmmunition>& points) {
	unordered_set<pair<int, int>, pair_hash> unSet;
	vector<PointAmmunition> result;

	for (PointAmmunition& pointAmmunition : points) {
		bool shouldInsert = true;
		for (int i = -10; i <= 10; i++) {
			pair<int, int> point_x = make_pair(pointAmmunition.point.x + i, pointAmmunition.point.y);
			pair<int, int> point_y = make_pair(pointAmmunition.point.x, pointAmmunition.point.y + i);
			if (unSet.find(point_x) != unSet.end() || unSet.find(point_y) != unSet.end()) {
				shouldInsert = false;
				break;
			}
		}
		if (shouldInsert) {
			result.push_back(pointAmmunition);
			for (int i = -10; i <= 10; i++) {
				pair<int, int> point_x = make_pair(pointAmmunition.point.x + i, pointAmmunition.point.y);
				pair<int, int> point_y = make_pair(pointAmmunition.point.x, pointAmmunition.point.y + i);
				unSet.insert(point_x);
				unSet.insert(point_y);
			}
		}
	}
	return result;
}


void Matching::AmmunitionMatching(vector<PathNameThreshold> input) {
	//cout << "amo matching" << endl;
	Mat templ;
	Mat MatScreen;
	GetMat getMat;
	//const char* image_window = "Ammunition Image";
	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	vector<POINT> ReturnDataAM;
	vector<POINT> ReturnDataAM_Clean;
	vector<PointAmmunition> pointAmmunitionTemp;

	PointAmmunition::pointAmmunition_NC.resize(MatScreenVector.size());

	int count = 0;
	for (int i1 = 0; i1 < MatScreenVector.size(); i1++) {

		Rect Rec(1200, 0, MatScreenVector[i1].cols - 1200, MatScreenVector[i1].rows);
		MatScreen = MatScreenVector[i1](Rec);
		
		for (int i = 0; i < input.size(); i++) {
			ReturnDataAM = TemplateMatching::templateMatchingItems(input[i].Path, input[i].Threshold, false, true, input[i].Name, MatScreen);

			templ = imread(input[i].Path);
			if (!ReturnDataAM.empty()) {
				ReturnDataAM_Clean = removeDuplicates(ReturnDataAM);

				for (int i2 = 0; i2 < ReturnDataAM_Clean.size(); i2++) {
					const Rect Rec(ReturnDataAM_Clean[i2].x + 44, ReturnDataAM_Clean[i2].y + 48, templ.cols - 44, templ.rows - 48);
					const string stackSize = "2"/*TextMatching::textMatching(arrayMatScreen[i1], Rec)*/;
					const int stackSizeConvertet = stoi(stackSize);
					pointAmmunitionTemp.emplace_back(ReturnDataAM_Clean[i2], input[i].Name, templ.rows, templ.cols, i1, 1, stackSizeConvertet);
				}
				ReturnDataAM.clear();
				ReturnDataAM_Clean.clear();
			}
		}
		
		pointAmmunitionTemp = removeDuplicatesPage(pointAmmunitionTemp);

		for (PointAmmunition &pointAM : pointAmmunitionTemp) {
			PointAmmunition::pointAmmunition_NC[i1].emplace_back(pointAM);
		}

		pointAmmunitionTemp.clear();
		//cout << "--------------- " << ++count << endl;
	}
	//cout << "mamo done" << endl;
}


void Matching::CaseMatching(vector<PathNameThreshold> input) {
	Mat templ;
	GetMat getMat;

	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();
	//const char* image_window = "Case Image";

	vector<POINT> ReturnDataCase;
	vector<POINT> ReturnDataCase_Clean;
	vector<vector<POINT>> freeSlots_empty{};
	vector<PointCaseInStash> pointCasetempStashTemp;
	int identyfierAsHEX_ST = 0x00;
	Prefix prefix;
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
						pointCasetempStashTemp.emplace_back(ReturnDataCase_Clean[i3], input[i].Name, tagCase, templ.rows, templ.cols, page, identyfierAsHEX_ST, freeSlots_empty, prefix);
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

namespace Magazine {
	std::array<std::string, 8> Magazine{
		//MP
			"itemImages/MagazineImgas/4.6HK/MP7.png",
			//NATO
				"itemImages/MagazineImgas/5.56NATO/MAG5-60.png",
				"itemImages/MagazineImgas/5.56NATO/PMAG-D60.png",
				"itemImages/MagazineImgas/7.62NARO/PMAG.png",
				"itemImages/MagazineImgas/7.62NARO/SLR.png",
				//RUS
					"itemImages/MagazineImgas/7.62RRUS/SVD.png",
					"itemImages/MagazineImgas/7.62RUS/AK30.png",
					"itemImages/MagazineImgas/7.62RUS/GEN-M3.png",

	};

	std::array<std::string, 8> NameOfItemMagazine{
		//MP
			"MP7",
			//NATO
				"MAG5-60",
				"PMAG-D60",
				"PMAG",
				"SLR",
				//RUS
					"SVD",
					"AK30",
					"GEN-M3",
	};

	std::array<double, 8> MagazineThreshold{
		//MP
			0.85,//MP7
			//NATO
				0.83,//MAG5-60
				0.83,//PMAG-D60
				0.83,//PMAG
				0.85,//SLR
				//RUS
					0.87,//SVD
					0.87,//AK30
					0.87,//GEN-M3
	};
}

void Matching::MagazineMatching(vector<PathNameThreshold> input) {
	const int sizeString = sizeof(Magazine::Magazine) / sizeof(string);
	Mat templ;
	GetMat getMat;
	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	vector<POINT> ReturnDataMA;
	vector<POINT> ReturnDataMA_Clean;
	vector<PointMagazine> pointMagazineTemp;
	for (int i1 = 0; i1 < MatScreenVector.size(); i1++) {
		for (int i = 0; i < sizeString; i++) {
			ReturnDataMA = TemplateMatching::templateMatchingItems(Magazine::Magazine[i], Magazine::MagazineThreshold[i], true, false, Magazine::NameOfItemMagazine[i], MatScreenVector[i1]);

			templ = imread(Magazine::Magazine[i]);
			if (!ReturnDataMA.empty()) {
				ReturnDataMA_Clean = removeDuplicates(ReturnDataMA);
				for (int i3 = 0; i3 < ReturnDataMA_Clean.size(); i3++) {
					const Rect Rec(ReturnDataMA_Clean[i3].x + 25, ReturnDataMA_Clean[i3].y + 110, templ.cols - 40, templ.rows - 110);
					const string fillStatus = TextMatching::textMatching(MatScreenVector[i1], Rec);
					const int fillStatusConvertet = stoi(fillStatus);
					pointMagazineTemp.emplace_back(ReturnDataMA_Clean[i3], Magazine::NameOfItemMagazine[i], fillStatusConvertet, templ.rows, templ.cols, i1, 2);
				}
				ReturnDataMA.clear();
				ReturnDataMA_Clean.clear();
			}
		}
		PointMagazine::pointMagazine_NC.emplace_back(pointMagazineTemp);
		pointMagazineTemp.clear();
	}
}


std::array<std::string, 2> FoundInRaid{
	"ObjectImages/FoundInRaid/FoundInRaid-Blue.png",
	"ObjectImages/FoundInRaid/FoundInRaid-Red.png"
};

void Matching::BarterMatching(vector<PathNameThresholdItemSize> input) {
	//cout << "Barter matching" << endl;
	const int sizeFoundInRaid = sizeof(FoundInRaid) / sizeof(String);
	Mat templ;
	Mat MatScreen;
	GetMat getMat;
	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	vector<POINT> ReturnDataBA;
	vector<POINT> ReturnDataBA_Clean;
	vector<PointBarter> pointBarterTemp;

	PointBarter::pointBarter_NC.resize(MatScreenVector.size());

	int count = 0;
	for (int i1 = 0; i1 < MatScreenVector.size(); i1++) {
		Rect Rec(1200, 0, MatScreenVector[i1].cols - 1200, MatScreenVector[i1].rows);
		MatScreen = MatScreenVector[i1](Rec);

		for (int i = 0; i < input.size(); i++) {
			ReturnDataBA = TemplateMatching::templateMatchingItems(input[i].Path, input[i].Threshold, false, true, input[i].Name, MatScreen);

			templ = imread(input[i].Path);
			if (!ReturnDataBA.empty()) {
				ReturnDataBA_Clean = removeDuplicates(ReturnDataBA);

				for (int i3 = 0; i3 < ReturnDataBA_Clean.size(); i3++) {
					const Rect Rec(ReturnDataBA_Clean[i3].x + 45, ReturnDataBA_Clean[i3].y + 46, templ.cols - 45, templ.rows - 46);
					for (int i4 = 0; i4 < sizeFoundInRaid; i4++) {
						Mat temp = imread(FoundInRaid[i4]);
						if (TemplateMatching::templateMatchingBool(MatScreenVector[i1](Rec), temp, 0.99))
							pointBarterTemp.emplace_back(ReturnDataBA_Clean[i3], input[i].Name, true, templ.rows, templ.cols, i1, input[i].ItemSize);
						else
							pointBarterTemp.emplace_back(ReturnDataBA_Clean[i3], input[i].Name, false, templ.rows, templ.cols, i1, input[i].ItemSize);
					}
				}
				ReturnDataBA.clear();
				ReturnDataBA_Clean.clear();
			}
		}

		for (PointBarter& pointAM : pointBarterTemp) {
			PointBarter::pointBarter_NC[i1].emplace_back(pointAM);
		}

		pointBarterTemp.clear();
		//cout << "--------------- " << ++count << endl;
	}
	//cout << "Barter done" << endl;
}
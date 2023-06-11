#pragma once
#include "ItemsProcessing.h"
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Checks.h"
#include "DistributorForMatching.h"
#include "getMat.h"
#include "PointGlobalVector.h"
#include <set>
using namespace std;
using namespace cv;

static Matching matching;

namespace AmmunitionVector {
	const vector<PathNameThreshold> Nato762 {
		{ "itemImages/AmmunitionImages/7.62NATO/M80.png", "M80", 0.90 },//M80
		{ "itemImages/AmmunitionImages/7.62NATO/M62.png",		"M62",			0.87 },//M62
		{ "itemImages/AmmunitionImages/7.62NATO/M61.png",		"M61",			0.89 },//M61
		{ "itemImages/AmmunitionImages/7.62NATO/M993.png",		"M993",			0.90 },//M993
		{ "itemImages/AmmunitionImages/7.62NATO/BCPFMJ.png",	"BCPFMJ",		0.84 },//BCPFMJ
		{ "itemImages/AmmunitionImages/7.62NATO/TCWSP.png",		"TCWSP",		0.86 },//TCWSP
		{ "itemImages/AmmunitionImages/7.62NATO/UltraNosi.png", "UltraNosi",    0.88 },//UltraNosi
	};

	const vector<PathNameThreshold> Nato556 {
		{ "itemImages/AmmunitionImages/5.56NATO/FMJ.png", "FMJ", 0.94 },//FMJ
		{ "itemImages/AmmunitionImages/5.56NATO/HP.png",		"HP",			0.94 },//HP
		{ "itemImages/AmmunitionImages/5.56NATO/M855.png",		"M855",			0.95 },//M855
		{ "itemImages/AmmunitionImages/5.56NATO/M855A1.png",	"M855A1",		0.95 },//M855A1
		{ "itemImages/AmmunitionImages/5.56NATO/M856.png",		"M856",			0.95 },//M856
		{ "itemImages/AmmunitionImages/5.56NATO/M856A1.png",	"M856A1",		0.95 },//M856A1
		{ "itemImages/AmmunitionImages/5.56NATO/M995.png",		"M995",			0.96 },//M995
		{ "itemImages/AmmunitionImages/5.56NATO/RRLP.png",		"RRLP",			0.94 },//RRLP
		{ "itemImages/AmmunitionImages/5.56NATO/SOST.png",		"SOST",			0.94 },//SOST
		{ "itemImages/AmmunitionImages/5.56NATO/Warmage.png",	"Warmage",		0.94 },//Warmage
	};

	const vector<PathNameThreshold> Rus762 {
		{ "itemImages/AmmunitionImages/7.62RUS/BP.png", "BP", 0.90 },//BP
		{ "itemImages/AmmunitionImages/7.62RUS/HP.png",			"HP",			0.90 },//HP
		{ "itemImages/AmmunitionImages/7.62RUS/MAIAP.png",		"MAIAP",		0.90 },//MAIAP
		{ "itemImages/AmmunitionImages/7.62RUS/PS.png",			"PS",			0.90 },//PS
		{ "itemImages/AmmunitionImages/7.62RUS/T45M1.png",		"T45M1",		0.90 },//T45M1
		{ "itemImages/AmmunitionImages/7.62RUS/US.png",			"US",			0.90 },//US
	};

	const vector<PathNameThreshold> Rus545 {
		{ "itemImages/AmmunitionImages/5.45RUS/7N40.png", "7N40", 0.93 },//7N40
		{ "itemImages/AmmunitionImages/5.45RUS/BP.png",			"BP",			0.93 },//BP
		{ "itemImages/AmmunitionImages/5.45RUS/BS.png",			"BS",			0.95 },//BS
		{ "itemImages/AmmunitionImages/5.45RUS/BT.png",			"BT",			0.93 },//BT
		{ "itemImages/AmmunitionImages/5.45RUS/FMJ.png",		"FMJ",			0.93 },//FMJ
		{ "itemImages/AmmunitionImages/5.45RUS/HP.png",			"HP",			0.93 },//HP
		{ "itemImages/AmmunitionImages/5.45RUS/PP.png",			"PP",			0.93 },//PP
		{ "itemImages/AmmunitionImages/5.45RUS/PPBS.png",		"PPBS",			0.93 },//PPBS
		{ "itemImages/AmmunitionImages/5.45RUS/PRS.png",		"PRS",			0.93 },//PRS
		{ "itemImages/AmmunitionImages/5.45RUS/PS.png",			"PS",			0.96 },//PS
		{ "itemImages/AmmunitionImages/5.45RUS/SP.png",			"SP",			0.93 },//SP
		{ "itemImages/AmmunitionImages/5.45RUS/T.png",			"T",			0.93 },//T
		{ "itemImages/AmmunitionImages/5.45RUS/US.png",			"US",			0.96 },//US
	};


	const array<vector<PathNameThreshold>, 4> ArrayAmmunition {
		AmmunitionVector::Nato762,
			AmmunitionVector::Nato556,
			AmmunitionVector::Rus762,
			AmmunitionVector::Rus545,
	};
}

std::vector<std::vector<PointAmmunition>> VectorInPages(const std::vector<std::vector<std::vector<PointAmmunition>>>& inputVector) {
	std::vector<std::vector<PointAmmunition>> outputVector;

	for (const std::vector<std::vector<PointAmmunition>>& innerVector1 : inputVector) {
		for (const std::vector<PointAmmunition>& innerVector2 : innerVector1) {
			for (const PointAmmunition& point : innerVector2) {
				if (point.page >= outputVector.size()) {
					outputVector.resize(point.page + 1);
				}
				outputVector[point.page].push_back(point);
			}
		}
	}

	return outputVector;
}


void ItemsProcessing::CallAll() {
	//GetMat::TakeScreenshots();

	AmmunitionProcess();
	//BarterItemsProcess();
}

void ItemsProcessing::AmmunitionProcess() {
	vector<vector<vector<PointAmmunition>>> CombinePagesVector;

	for (vector<PathNameThreshold> vec : AmmunitionVector::ArrayAmmunition) {
		matching.AmmunitionMatching(vec);
	}

	cout << PointAmmunition::pointAmmunition_NC.size() << endl;

	//PointAmmunition::pointAmmunition_NC = VectorInPages(CombinePagesVector);


	cleanUpVectorItemsAmmunition();

	for (int i = 0; i < PointAmmunition::pointAmmunition_NC.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_NC[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_NC[i][i2].point.y << " " << PointAmmunition::pointAmmunition_NC[i][i2].point.x << " " << PointAmmunition::pointAmmunition_NC[i][i2].nameOfItem << " " << PointAmmunition::pointAmmunition_NC[i][i2].page << endl;
		}
	}
	cout << "-------------- clean" << endl;
	for (int i = 0; i < PointAmmunition::pointAmmunition_C.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_C[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_C[i][i2].point.y << " " << PointAmmunition::pointAmmunition_C[i][i2].point.x << " " << PointAmmunition::pointAmmunition_C[i][i2].nameOfItem << " " << PointAmmunition::pointAmmunition_C[i][i2].page << endl;
		}
	}

	cout << "item Process done" << endl;
}

void ItemsProcessing::BarterItemsProcess() {

	//matching.BarterMatching(MatScreenVector);
	cleanUpVectorItemsBarter();
}


struct POINT_PAGE {
	POINT point;
	uint8_t page;
	bool operator<(const POINT_PAGE& other) const {
		return point.x < other.point.x || (point.x == other.point.x && (point.y < other.point.y || (point.y == other.point.y && page < other.page)));
	}
};

void ItemsProcessing::cleanUpVectorItemsAmmunition() {
	vector<PointAmmunition> temp;
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;

	temp = PointAmmunition::pointAmmunition_NC[0];
	PointAmmunition::pointAmmunition_C.emplace_back(temp);
	temp.clear();

	uint8_t iTemp = 1;
	for (uint8_t i = 1; i < PointAmmunition::pointAmmunition_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointAmmunition::pointAmmunition_NC.size())
			break;

		for (PointAmmunition pointCase : PointAmmunition::pointAmmunition_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			int multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointAmmunition::pointAmmunition_NC.size() - 1 || iTempLoop < iTemp + 2; iTempLoop++) {

				for (PointAmmunition inPointCase : PointAmmunition::pointAmmunition_NC[iTempLoop]) {
					PointAmmunition tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = tempPointCase.point.x + 1;

					//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
					cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (pointCase.nameOfItem != inPointCase.nameOfItem)
						continue;

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
							//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
							cout << "\n---------- push " << pointCase.point.y << " " << pointCase.point.x << " -- " << tempPointCase.point.y << " " << tempPointCase.point.x << " -- " << inPointCase.point.y << " " << inPointCase.point.x << " -- " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << "\n" << endl;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				temp.emplace_back(pointCase);
		}
		if (iTemp == 10) {
			for (PointAmmunition pointCase : PointAmmunition::pointAmmunition_NC[iTemp]) {
				if (pointCase.point.y >= 618) {
					temp.emplace_back(pointCase);
				}
			}
		}
		PointAmmunition::pointAmmunition_C.emplace_back(temp);
		temp.clear();
	}
}

void ItemsProcessing::cleanUpVectorItemsBarter() {
	vector<PointBarter> temp;
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;

	temp = PointBarter::pointBarter_NC[0];
	PointBarter::pointBarter_C.emplace_back(temp);
	temp.clear();

	uint8_t iTemp = 1;
	for (uint8_t i = 1; i < PointBarter::pointBarter_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointBarter::pointBarter_NC.size())
			break;

		for (PointBarter pointCase : PointBarter::pointBarter_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			uint8_t multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointBarter::pointBarter_NC.size() - 1 || iTempLoop < iTemp + 3; iTempLoop++) {

				for (PointBarter inPointCase : PointBarter::pointBarter_NC[iTempLoop]) {
					PointBarter tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = tempPointCase.point.x + 1;

					//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
					cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (pointCase.nameOfItem != inPointCase.nameOfItem)
						continue;

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
							//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
							cout << "\n---------- push " << pointCase.point.y << " " << pointCase.point.x << " -- " << tempPointCase.point.y << " " << tempPointCase.point.x << " -- " << inPointCase.point.y << " " << inPointCase.point.x << " -- " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << "\n" << endl;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				temp.emplace_back(pointCase);
		}
		if (iTemp == 10) {
			for (PointBarter pointCase : PointBarter::pointBarter_NC[iTemp]) {
				if (pointCase.point.y >= 618) {
					temp.emplace_back(pointCase);
				}
			}
		}
		PointBarter::pointBarter_C.emplace_back(temp);
		temp.clear();
	}
}



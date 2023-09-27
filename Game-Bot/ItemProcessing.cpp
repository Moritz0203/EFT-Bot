#pragma once														
#include "ItemProcessing.h"
#include "Includes.h"
#include <set>
#include "DistributorForMatching.h"
#include "getMat.h"
#include "ItemVectors.h"





void ItemProcessing::Init_Vectors() {
	GetMat getMat;
	const std::vector<cv::Mat> MatScreenVector = getMat.GetMatVector();

	PointMedical::pointMedical_NC.resize(MatScreenVector.size());
	PointMedical::pointMedical_C.resize(MatScreenVector.size());
}

void ItemProcessing::MedicalProcess() {
	Matching matching;

	/*for (vector<PathNameThresholdItemSize> vec : MedicalVector::ArrayMedical) {
		matching.MedicalMatching(vec);
	}*/

	matching.MedicalMatching(MedicalVector::Medical);

	cleanUpVectorItemsMedical();
}

void ItemProcessing::MedicalProcess_OneScreen(std::shared_ptr<vector<PointMedical>>& ptr_MedicalVec, cv::Mat MatScreen) {
	/*Matching matching;

	matching.MedicalMatching_OneScreen(MedicalVector::Medical, ptr_MedicalVec, MatScreen);*/
}


vector<vector<PointMedical>> ItemProcessing::OneItemMedicalMatching(string nameOfItem) {
	Matching matching;
	vector<vector<PointMedical>> pointMedical_NC;

	for (auto& item : MedicalVector::Medical) {
		if (item.Name == nameOfItem) {
			PathNameThresholdItemSizeMaxHP input{ item.Path , item.Name , item.FleaName , item.Threshold , item.ItemSize , item.MaxHp };
			pointMedical_NC = matching.OneItemMedicalMatching(input);
			break;
		}
	}

	return cleanUpVectorItemsMedical_Return(pointMedical_NC);
}

vector<vector<PointBarter>> ItemProcessing::OneItemBarterMatching(string nameOfItem) {
	Matching matching;
	vector<vector<PointBarter>> pointBarter_NC;
	PathNameThresholdItemSize input{};

	bool found = false;	
	for (auto& vec : ArrayName) {
		if (found)
			break;

		for (auto& item : vec) {
			if (item.Name == nameOfItem) {
				PathNameThresholdItemSize input{ item.Path , item.Name , item.FleaName , item.Threshold , item.ItemSize };
				pointBarter_NC = matching.OneItemBarterMatching(input);

				found = true;
				break;
			}
		}
	}

	return cleanUpVectorItemsBarter_Return(pointBarter_NC);
}





struct POINT_PAGE {
	POINT point;
	uint8_t page;
	bool operator<(const POINT_PAGE& other) const {
		return point.x < other.point.x || (point.x == other.point.x && (point.y < other.point.y || (point.y == other.point.y && page < other.page)));
	}
};

void ItemProcessing::cleanUpVectorItemsMedical() {
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;


	uint8_t iTemp = 0;
	for (uint8_t i = 0; i < PointMedical::pointMedical_NC.size(); i++) {
		iTemp++;

		if (iTemp == PointMedical::pointMedical_NC.size())
			break;

		for (PointMedical pointCase : PointMedical::pointMedical_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			int multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < PointMedical::pointMedical_NC.size() - 1 || iTempLoop < iTemp + 2; iTempLoop++) {

				for (PointMedical inPointCase : PointMedical::pointMedical_NC[iTempLoop]) {
					PointMedical tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = (uint16_t)tempPointCase.point.x + 1;

					//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
					//cout << pointCase.point.y << " " << pointCase.point.x << " " << tempPointCase.point.y << " " << tempPointCase.point.x << " " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << " " << multiplier << endl;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					/*if (pointCase.nameOfItem != inPointCase.nameOfItem) // NOTE: Später über eingabe regeln wie sicher der user sein munition sortig haben möchte
						continue;*/

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
							//if (pointCase.nameOfCase == "AmmoCase" && tempPointCase.nameOfCase == "AmmoCase")
							//cout << "\n---------- push " << pointCase.point.y << " " << pointCase.point.x << " -- " << tempPointCase.point.y << " " << tempPointCase.point.x << " -- " << inPointCase.point.y << " " << inPointCase.point.x << " -- " << pointCase.nameOfItem << " " << tempPointCase.nameOfItem << " " << pointCase.page << " " << tempPointCase.page << "\n" << endl;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				PointMedical::pointMedical_C[i].emplace_back(pointCase);
		}
		if (i == 0) {
			for (PointMedical pointMedical : PointMedical::pointMedical_NC[i]) {
				if (pointMedical.point.y <= 400) {
					PointMedical::pointMedical_C[i].emplace_back(pointMedical);
				}
			}
		}
		if (iTemp == 10) {
			for (PointMedical pointMedical : PointMedical::pointMedical_NC[iTemp]) {
				if (pointMedical.point.y >= 618) {
					PointMedical::pointMedical_C[i].emplace_back(pointMedical);
				}
			}
		}
	}
}


vector<vector<PointMedical>> ItemProcessing::cleanUpVectorItemsMedical_Return(vector<vector<PointMedical>>& pointMedical_NC) {
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;
	vector<vector<PointMedical>> pointMedical_C;
	pointMedical_C.resize(pointMedical_NC.size());


	uint8_t iTemp = 0;
	for (uint8_t i = 0; i < pointMedical_NC.size(); i++) {
		iTemp++;

		if (iTemp == pointMedical_NC.size())
			break;

		for (PointMedical pointCase : pointMedical_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			int multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < pointMedical_NC.size() - 1 || iTempLoop < iTemp + 2; iTempLoop++) {

				for (PointMedical inPointCase : pointMedical_NC[iTempLoop]) {
					PointMedical tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = (uint16_t)tempPointCase.point.x + 1;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				pointMedical_C[i].emplace_back(pointCase);
		}
		if (i == 0) {
			for (PointMedical pointMedical : pointMedical_NC[i]) {
				if (pointMedical.point.y <= 400) {
					pointMedical_C[i].emplace_back(pointMedical);
				}
			}
		}
		if (iTemp == 10) {
			for (PointMedical pointMedical : pointMedical_NC[iTemp]) {
				if (pointMedical.point.y >= 618) {
					pointMedical_C[i].emplace_back(pointMedical);
				}
			}
		}
	}


	return pointMedical_C;
}

vector<vector<PointBarter>> ItemProcessing::cleanUpVectorItemsBarter_Return(vector<vector<PointBarter>>& pointBarter_NC) {
	POINT_PAGE point_page{};
	POINT_PAGE inPoint_page{};
	std::set<POINT_PAGE> set_POINT_PAGE;
	vector<vector<PointBarter>> pointBarter_C;
	pointBarter_C.resize(pointBarter_NC.size());


	uint8_t iTemp = 0;
	for (uint8_t i = 0; i < pointBarter_NC.size(); i++) {
		iTemp++;

		if (iTemp == pointBarter_NC.size())
			break;

		for (PointBarter pointCase : pointBarter_NC[i]) {
			point_page.page = pointCase.page;
			point_page.point = pointCase.point;

			if (set_POINT_PAGE.count(point_page) > 0)
				continue;

			bool Found = false;
			int multiplier = 1;
			for (uint8_t iTempLoop = iTemp; iTempLoop < pointBarter_NC.size() - 1 || iTempLoop < iTemp + 2; iTempLoop++) {

				for (PointBarter inPointCase : pointBarter_NC[iTempLoop]) {
					PointBarter tempPointCase = inPointCase;
					tempPointCase.point.y = tempPointCase.point.y + (343 * multiplier);
					inPoint_page.page = inPointCase.page;
					inPoint_page.point = inPointCase.point;

					uint16_t y_minus_1 = tempPointCase.point.y - 1;
					uint16_t y_plus_1 = tempPointCase.point.y + 1;
					uint16_t x_minus_1 = tempPointCase.point.x - 1;
					uint16_t x_plus_1 = (uint16_t)tempPointCase.point.x + 1;

					if (set_POINT_PAGE.count(inPoint_page) > 0)
						continue;

					if (tempPointCase.point.y == pointCase.point.y || y_minus_1 == pointCase.point.y || y_plus_1 == pointCase.point.y) {
						if (tempPointCase.point.x == pointCase.point.x || x_minus_1 == pointCase.point.x || x_plus_1 == pointCase.point.x) {
							set_POINT_PAGE.insert(inPoint_page);
							Found = true;
						}
					}
				}
				multiplier++;
			}
			if (Found)
				pointBarter_C[i].emplace_back(pointCase);
		}
		if (i == 0) {
			for (PointBarter pointBarter : pointBarter_NC[i]) {
				if (pointBarter.point.y <= 400) {
					pointBarter_C[i].emplace_back(pointBarter);
				}
			}
		}
		if (iTemp == 10) {
			for (PointBarter pointBarter : pointBarter_NC[iTemp]) {
				if (pointBarter.point.y >= 618) {
					pointBarter_C[i].emplace_back(pointBarter);
				}
			}
		}
	}


	return pointBarter_C;
}

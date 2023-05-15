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

Matching matching;

void ItemsProcessing::CallAll() {
	//GetMat::TakeScreenshots();

	AmmunitionProcess();
	//BarterItemsProcess();
}

void ItemsProcessing::AmmunitionProcess() {

	matching.AmmunitionMatching();

	for (int i = 0; i < PointAmmunition::pointAmmunition_NC.size(); i++) {
		for (int i2 = 0; i2 < PointAmmunition::pointAmmunition_NC[i].size(); i2++) {
			cout << PointAmmunition::pointAmmunition_NC[i][i2].point.y << " " << PointAmmunition::pointAmmunition_NC[i][i2].point.x << " " << PointAmmunition::pointAmmunition_NC[i][i2].nameOfItem << endl;
		}
	}

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


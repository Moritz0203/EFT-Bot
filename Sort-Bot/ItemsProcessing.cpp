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
#include "MatScreenGlobalArray.h"
#include "getMat.h"
#include "PointGlobalVector.h"
using namespace std;
using namespace cv;

Matching matching;

void ItemsProcessing::CallAll() {
	GetMat::TakeScreenshots();

	AmmunitionProcess();
	//BarterItemsProcess();
}

void ItemsProcessing::AmmunitionProcess() {

	matching.AmmunitionMatching(MatScreenArray);
	cleanUpVectorItemsAmmunition();

	for (int i = 0; i < pointAmmunition_NC.size(); i++) {
		for (int i2 = 0; i2 < pointAmmunition_NC[i].size(); i2++) {
			cout << pointAmmunition_NC[i][i2].point.y << " " << pointAmmunition_NC[i][i2].point.x << endl;
		}
	}
	cout << "--------------" << endl;
	for (int i = 0; i < pointAmmunition_C.size(); i++) {
		for (int i2 = 0; i2 < pointAmmunition_C[i].size(); i2++) {
			cout << pointAmmunition_C[i][i2].point.y << " " << pointAmmunition_C[i][i2].point.x << endl;
		}
	}

	cout << "item Process done" << endl;
}

void ItemsProcessing::BarterItemsProcess() {

	matching.BarterMatching(MatScreenArray);
	cleanUpVectorItemsBarter();
}

void ItemsProcessing::cleanUpVectorItemsBarter() {
	vector<PointBarter> temp;

	temp = pointBarter_NC[0];
	pointBarter_C.emplace_back(temp);
	temp.clear();

	int iTemp = 1;
	for (int i = 1; i < pointBarter_NC.size(); i++) {
		iTemp++;

		if (iTemp == pointBarter_NC.size())
			break;

		for (PointBarter pointBA : pointBarter_NC[i]) {
			for (PointBarter inPointBA : pointBarter_NC[iTemp]) {
				PointBarter tempPointBA = inPointBA;
				tempPointBA.point.y = tempPointBA.point.y + 343;

				int x_minus_1 = inPointBA.point.x - 1;
				int x_plus_1 = inPointBA.point.x + 1;

				if (inPointBA.point.y == pointBA.point.y) {
					if (inPointBA.point.x == pointBA.point.x || x_minus_1 == pointBA.point.x || x_plus_1 == pointBA.point.x) {
						temp.emplace_back(pointBA);
					}
				}
			}
		}
		if (iTemp == 10) {
			for (PointBarter pointBA : pointBarter_NC[iTemp]) {
				if (pointBA.point.y >= 618) {
					temp.emplace_back(pointBA);
				}
			}
		}
		pointBarter_C.emplace_back(temp);
		temp.clear();
	}
}

void ItemsProcessing::cleanUpVectorItemsAmmunition() {
	vector<PointAmmunition> temp;

	temp = pointAmmunition_NC[0];
	pointAmmunition_C.emplace_back(temp);
	temp.clear();

	int iTemp = 1;
	for (int i = 1; i < pointAmmunition_NC.size(); i++) {
		iTemp++;

		if (iTemp == pointAmmunition_NC.size())
			break;

		for (PointAmmunition pointAM : pointAmmunition_NC[i]) {
			for (PointAmmunition inPointAM : pointAmmunition_NC[iTemp]) {
				PointAmmunition tempPointAM = inPointAM;
				tempPointAM.point.y = tempPointAM.point.y + 343;

				int x_minus_1 = tempPointAM.point.x - 1;
				int x_plus_1 = tempPointAM.point.x + 1;

				if (tempPointAM.point.y == pointAM.point.y) {
					if (tempPointAM.point.x == pointAM.point.x || x_minus_1 == pointAM.point.x || x_plus_1 == pointAM.point.x) {
						temp.emplace_back(pointAM);
					}
				}
			}
		}
		if (iTemp == 10) {
			for (PointAmmunition pointAM : pointAmmunition_NC[iTemp]) {
				if (pointAM.point.y >= 618) {
					temp.emplace_back(pointAM);
				}
			}
		}
		pointAmmunition_C.emplace_back(temp);
		temp.clear();
	}
}


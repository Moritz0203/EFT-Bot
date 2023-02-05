#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "StartUp.h"
using namespace std;
using namespace cv;


namespace ItemsProcessing {
	void cleanUpVectorItemsAmmunition();
	void cleanUpVectorItemsBarter();

	void AmmunitionProcess() {
		array<Mat, 11> ReturntMatScreen;

		StartUp::CheckScrollbarPositions();
		Sleep(10);
		ReturntMatScreen = StartUp::TakeScreenshots();

		Matching::AmmunitionMatching(ReturntMatScreen);
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

	void BarterItemsProcess() {
		array<Mat, 11> ReturntMatScreen;

		StartUp::CheckScrollbarPositions();
		ReturntMatScreen = StartUp::TakeScreenshots();

		Matching::BarterMatching(ReturntMatScreen);
		cleanUpVectorItemsBarter();
	}





	void cleanUpVectorItemsAmmunition() {
		vector<PointAmmunition> temp;

		temp = pointAmmunition_NC[0];
		pointAmmunition_C.emplace_back(temp);
		temp.clear();

		/*pointAmmunition_NC.emplace_back(temp);*/


		unordered_set<int> unset;
		int iTemp = 1;
		for (int i = 1; i < pointAmmunition_NC.size(); i++) {
			iTemp++;

			if (iTemp == pointAmmunition_NC.size())
				break;

			/*cout << pointAmmunition_NC.size() << endl;*/
			for (PointAmmunition pointAM : pointAmmunition_NC[i]) {
				cout << "first " << pointAM.point.y << " " << pointAM.point.x << endl;
				

				/*cout << i << " " << iTemp << endl;*/


				/*if (pointAmmunition_NC[iTemp].size() == 0)
					temp.emplace_back(pointAM);*/

				for (PointAmmunition inPointAM : pointAmmunition_NC[iTemp]) {
					cout << "---second " << inPointAM.point.y << " " << inPointAM.point.x << endl;
					

					PointAmmunition tempPointAM = inPointAM;
					tempPointAM.point.y = tempPointAM.point.y + 343;

					cout << "---second " << tempPointAM.point.y << endl;
					int x_minus_1 = tempPointAM.point.x - 1;
					int x_plus_1 = tempPointAM.point.x + 1;

					/*int y_plus_1 = tempPointAM.point.y + 1;
					int y_plus_2 = tempPointAM.point.y + 2;
					int y_plus_3 = tempPointAM.point.y + 3;
					int y_plus_4 = tempPointAM.point.y + 4;
					int y_plus_5 = tempPointAM.point.y + 5;*/

					if (tempPointAM.point.y == pointAM.point.y) {
						if (tempPointAM.point.x == pointAM.point.x || x_minus_1 == pointAM.point.x || x_plus_1 == pointAM.point.x) {



							//unset.insert(x_minus_1);

							//unset.insert(x_plus_1);

							//unset.insert(tempPointAM.point.x);


							temp.emplace_back(pointAM);
							cout << "------in " << tempPointAM.point.x << endl;
						}
					}

				}
				cout << endl;
			}
			if (iTemp == 10) {
				for (PointAmmunition pointAM : pointAmmunition_NC[iTemp]) {
					if (pointAM.point.y >= 618) {
						temp.emplace_back(pointAM);
					}
				}
			}
			pointAmmunition_C.emplace_back(temp);
			unset.clear();
			temp.clear();
		}


		//618


		//int iTemp = 1;
		//for (int i = 1; i < pointAmmunition_NC.size(); i++) {// Loop the vector
		//	iTemp++;

		//	if (iTemp == pointAmmunition_NC.size())
		//		break;

		//	for (int i2 = 0; i2 < pointAmmunition_NC[i].size(); i2++) {//Loop through the vector of vector 
		//		unordered_set<int> unset;
		//		for (int i3 = 0; i3 < pointAmmunition_NC[iTemp].size(); i3++) {//Loop through the next vector of vector  
		//			bool FoundDuplicate = false;

		//			POINT pointLookForLast = pointAmmunition_NC[i][i2].point;
		//			pointLookForLast.y = 340 + pointLookForLast.y;
		//			POINT pointTempGround = pointAmmunition_NC[iTemp][i3].point;
		//			pointTempGround.y = 340 + pointTempGround.y;

		//			
		//			int x_minus_1 = pointTempGround.x - 1;
		//			int x_plus_1 = pointTempGround.x + 1;

		//			if (pointLookForLast.y == pointAmmunition_NC[iTemp][i3].point.y && pointLookForLast.x == pointAmmunition_NC[iTemp][i3].point.x)
		//				break;

		//			for (int i4 = 0; i4 < 6; i4++) {//To run pointTemp from 340 to 345 and compare with the current point in the next vector of vector 
		//				POINT pointTemp = pointTempGround;
		//				pointTemp.y = pointTemp.y + i4;

		//				if (pointAmmunition_NC[i][i2].point.y == pointTemp.y && unset.find(pointTempGround.x) == unset.end() && unset.find(x_minus_1) == unset.end() && unset.find(x_plus_1) == unset.end()) {//Check if pointTemp is equal to the current point in the next vector of vector
		//					unset.insert(pointTempGround.x);
		//					unset.insert(x_minus_1);
		//					unset.insert(x_plus_1);
		//					FoundDuplicate = true;
		//					break;
		//				}
		//			}

		//			if (FoundDuplicate == true) {//If a duplicate was found the point that was compared is pushed to temp
		//				temp.emplace_back(pointAmmunition_NC[i][i2]);
		//			}
		//		}
		//	}
		//	pointAmmunition_C.emplace_back(temp);
		//	temp.clear();
		//}
	}










	void cleanUpVectorItemsBarter() {
		vector<PointBarter> temp;
		if (!pointBarter_NC.size() >= 1)
			return;

		temp = pointBarter_NC[0];
		pointBarter_C.emplace_back(temp);
		temp.clear();

		pointBarter_NC.emplace_back(temp);

		int iTemp = 1;
		for (int i = 1; i < pointBarter_NC.size(); i++) {// Loop the vector
			iTemp++;

			if (iTemp == pointBarter_NC.size())
				break;

			for (int i2 = 0; i2 < pointBarter_NC[i].size(); i2++) {//Loop through the vector of vector 

				for (int i3 = 0; i3 < pointBarter_NC[iTemp].size(); i3++) {//Loop through the next vector of vector  
					bool FoundDuplicate = false;

					POINT pointLookForLast = pointBarter_NC[i][i2].point;
					pointLookForLast.y = 340 + pointLookForLast.y;
					POINT pointTempGround = pointBarter_NC[iTemp][i3].point;
					pointTempGround.y = 340 + pointTempGround.y;

					if (pointLookForLast.y == pointBarter_NC[iTemp][i3].point.y && pointLookForLast.x == pointBarter_NC[iTemp][i3].point.x)
						break;

					for (int i4 = 0; i4 < 6; i4++) {//To run pointTemp from 340 to 345 and compare with the current point in the next vector of vector 
						POINT pointTemp = pointTempGround;
						pointTemp.y = pointTemp.y + i4;

						if (pointBarter_NC[i][i2].point.y == pointTemp.y && pointBarter_NC[i][i2].point.x == pointTemp.x) {//Check if pointTemp is equal to the current point in the next vector of vector
							FoundDuplicate = true;
							break;
						}
					}

					if (FoundDuplicate == true) {//If a duplicate was found the point that was compared is pushed to temp
						temp.emplace_back(pointBarter_NC[i][i2]);
					}
				}
			}
			if (!temp.empty()) {
				pointBarter_C.emplace_back(temp);
				temp.clear();
			}
			else {
				pointBarter_C.emplace_back(temp);
				temp.clear();
			}
		}
	}
}
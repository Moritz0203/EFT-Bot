//#include <iostream>
//#include <vector>
//#include <conio.h>
//#include <windows.h>
//#include "TemplateMatching.h"
//using namespace std;
//
//namespace cleanVector {
//	void cleanUpVector(vector<vector<POINT>>& PointVectorTemp, vector<vector<POINT>>& PointVectorCleanUp) {
//		vector<POINT> temp;
//		if (!PointVectorTemp.size() >= 1)
//			return;
//
//		temp = PointVectorTemp[0];
//		PointVectorCleanUp.push_back(temp);
//		temp.clear();
//
//		PointVectorTemp.push_back(temp);
//
//		int iTemp = 1;
//		for (int i = 1; i < PointVectorTemp.size(); i++) {// Loop the vector
//			iTemp++;
//
//			if (iTemp == PointVectorTemp.size())
//				break;
//
//			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {//Loop through the vector of vector 
//
//				for (int i3 = 0; i3 < PointVectorTemp[iTemp].size(); i3++) {//Loop through the next vector of vector  
//					bool FoundDuplicate = false;
//
//					POINT pointLookForLast = PointVectorTemp[i][i2];
//					pointLookForLast.y = 340 + pointLookForLast.y;
//					POINT pointTempGround = PointVectorTemp[iTemp][i3];
//					pointTempGround.y = 340 + pointTempGround.y;
//
//					if (pointLookForLast.y == PointVectorTemp[iTemp][i3].y && pointLookForLast.x == PointVectorTemp[iTemp][i3].x)
//						break;
//
//					for (int i4 = 0; i4 < 6; i4++) {//To run pointTemp from 340 to 345 and compare with the current point in the next vector of vector 
//						POINT pointTemp = pointTempGround;
//						pointTemp.y = pointTemp.y + i4;
//
//						if (PointVectorTemp[i][i2].y == pointTemp.y && PointVectorTemp[i][i2].x == pointTemp.x) {//Check if pointTemp is equal to the current point in the next vector of vector
//							FoundDuplicate = true;
//							break;
//						}
//					}
//
//					if (FoundDuplicate == true) {//If a duplicate was found the point that was compared is pushed to temp
//						temp.push_back(PointVectorTemp[i][i2]);
//					}
//				}
//			}
//			if (!temp.empty()) {
//				PointVectorCleanUp.push_back(temp);
//				temp.clear();
//			}
//			else {
//				PointVectorCleanUp.push_back(temp);
//				temp.clear();
//			}
//		}
//	}
//}

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "getMat.h"
#include "InputMT.h"
#include "DistributorForMatching.h"
#include "globalvector.h"
using namespace std;
using namespace cv;




namespace StartUp {
	void CheckForFails();
	void CheckScrollbarPositions();
	void Magic();
	void cleanUpVector(vector<vector<POINT>> &PointVectorTemp, vector<vector<POINT>> &PointVectorCleanUp);
	array<Mat, 11> TakeScreenshots();

	void Entrance() {

		CheckForFails();

		CheckScrollbarPositions();

		Magic();
		
	}

	void CheckForFails() {
		Mat MatScreen;
		Mat templ;
		POINT pointMouse = {};
		pointMouse.y = 729;
		pointMouse.x = 961;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);

		templ = imread("ObjectImages/Banner.png");
		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.98);
		if (point.y || point.x != 0)
			Mouse::MoverPOINTandPress(pointMouse); //729 961
	}

	void CheckScrollbarPositions() {
		Mat MatScreen;
		Mat templ;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);

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

	array<Mat, 11> TakeScreenshots() {
		Mat MatScreen;
		array<Mat, 11> ReturnMatScreen;

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later

		POINT point{};
		point.y = 171;
		point.x = 1903;
		Mouse::MoverPOINTandPress(point);

		int size = sizeof(ReturnMatScreen) / sizeof(Mat);
		for (int i = 0; i < size; i++) {
			Sleep(500);
			ReturnMatScreen[i] = getMat(hWND);
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
		}

		return ReturnMatScreen;
	}

	bool checkSecondLastChar(const string tagCase) {
		int length = tagCase.length();
		if (length >= 2) {
			return (tagCase[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - 2] != '-');
		}
		return false;
	}

	vector<vector<POINT>> PointVectorTemp;
	vector<vector<POINT>> PointVectorCleanUp;

	void Magic() {
		array<Mat, 11> ReturntMatScreen;
		vector<POINT> ReturnPoints;
		ReturntMatScreen = TakeScreenshots();
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);

		int size = sizeof(ReturntMatScreen) / sizeof(Mat);
		for (int i = 0; i < size; i++) {
			imshow(image_window, ReturntMatScreen[i]);
			waitKey(0);
		}


		for (int i = 0; i < 7; i++) {// 5 must later be size 
			ReturnPoints = Matching::AmmunitionMatching(ReturntMatScreen[i]);
			if (!ReturnPoints.empty()) {
				PointVectorTemp.push_back(ReturnPoints);
				ReturnPoints.clear();
			}
			else {
				PointVectorTemp.push_back(ReturnPoints);
				ReturnPoints.clear();
			}
			cout << "-----------------------------------------------------------------------------------\n";
		}

		
		cleanUpVector(PointVectorTemp, PointVectorCleanUp);


		cout << "Not Clean\n";
		for (int i = 0; i < PointVectorTemp.size(); i++) {
			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {
				cout << PointVectorTemp[i][i2].y << " " << PointVectorTemp[i][i2].x << endl;
			}
		}

		cout << "Clean\n";
		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
			for (int i2 = 0; i2 < PointVectorCleanUp[i].size(); i2++) {
				cout << "---- " << PointVectorCleanUp[i][i2].y << " " << PointVectorCleanUp[i][i2].x << endl;
			}
			cout << PointVectorCleanUp[i].size() << endl;
		}
		cout << endl;
		cout << PointVectorTemp.size() << endl;
		cout << PointVectorCleanUp.size() << endl; 
		
	}


	void cleanUpVector(vector<vector<POINT>> &PointVectorTemp, vector<vector<POINT>> &PointVectorCleanUp) {
		vector<POINT> temp;
		if (!PointVectorTemp.size() >= 1) 	
			return;
	
		temp = PointVectorTemp[0];
		PointVectorCleanUp.push_back(temp);
		temp.clear();

		PointVectorTemp.push_back(temp);

		int iTemp = 1;
		for (int i = 1; i < PointVectorTemp.size(); i++) {// Loop the vector
			iTemp++;

			if (iTemp == PointVectorTemp.size())
				break;

			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {//Loop through the vector of vector 
			
				for (int i3 = 0; i3 < PointVectorTemp[iTemp].size(); i3++) {//Loop through the next vector of vector  
					bool FoundDuplicate = false;

					POINT pointLookForLast = PointVectorTemp[i][i2];
					pointLookForLast.y = 340 + pointLookForLast.y;
					POINT pointTempGround = PointVectorTemp[iTemp][i3];
					pointTempGround.y = 340 + pointTempGround.y;

					if (pointLookForLast.y == PointVectorTemp[iTemp][i3].y && pointLookForLast.x == PointVectorTemp[iTemp][i3].x)
						break;

					for (int i4 = 0; i4 < 6; i4++) {//To run pointTemp from 340 to 345 and compare with the current point in the next vector of vector 
						POINT pointTemp = pointTempGround;
						pointTemp.y = pointTemp.y + i4;

						if (PointVectorTemp[i][i2].y == pointTemp.y && PointVectorTemp[i][i2].x == pointTemp.x) {//Check if pointTemp is equal to the current point in the next vector of vector
							FoundDuplicate = true;
							break;
						}
					}

					if (FoundDuplicate == true) {//If a duplicate was found the point that was compared is pushed to temp
						temp.push_back(PointVectorTemp[i][i2]);
					}
				}
			}
			if (!temp.empty()) {
				PointVectorCleanUp.push_back(temp);
				temp.clear();
			}
			else {
				PointVectorCleanUp.push_back(temp);
				temp.clear();
			}
		}
	}

	void cleanUpVectorOnParameters(vector<vector<PointCaseInStash>>& PointVectorTemp, vector<vector<PointCaseInStash>>& PointVectorCleanUp) {
		vector<PointCaseInStash> temp;
		if (!PointVectorTemp.size() >= 1)
			return;

		temp = PointVectorTemp[0];
		PointVectorCleanUp.emplace_back(temp);
		temp.clear();

		PointVectorTemp.emplace_back(temp);

		int iTemp = 1;
		for (int i = 1; i < PointVectorTemp.size(); i++) {// Loop the vector
			iTemp++;

			if (iTemp == PointVectorTemp.size())
				break;

			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {//Loop through the vector of vector 

				for (int i3 = 0; i3 < PointVectorTemp[iTemp].size(); i3++) {//Loop through the next vector of vector  
					bool FoundDuplicate = false;

					POINT pointLookForLast = PointVectorTemp[i][i2].point;
					pointLookForLast.y = 340 + pointLookForLast.y;
					POINT pointTempGround = PointVectorTemp[iTemp][i3].point;
					pointTempGround.y = 340 + pointTempGround.y;

					if (pointLookForLast.y == PointVectorTemp[iTemp][i3].point.y && pointLookForLast.x == PointVectorTemp[iTemp][i3].point.x)
						break;

					for (int i4 = 0; i4 < 6; i4++) {//To run pointTemp from 340 to 345 and compare with the current point in the next vector of vector 
						POINT pointTemp = pointTempGround;
						pointTemp.y = pointTemp.y + i4;

						if (PointVectorTemp[i][i2].point.y == pointTemp.y && PointVectorTemp[i][i2].point.x == pointTemp.x) {//Check if pointTemp is equal to the current point in the next vector of vector
							FoundDuplicate = true;
							break;
						}
					}

					if (FoundDuplicate == true) {//If a duplicate was found the point that was compared is pushed to temp
						temp.emplace_back(PointVectorTemp[i][i2]);
					}
				}
			}
			if (!temp.empty()) {
				PointVectorCleanUp.emplace_back(temp);
				temp.clear();
			}
			else {
				PointVectorCleanUp.emplace_back(temp);
				temp.clear();
			}
		}
	}
}
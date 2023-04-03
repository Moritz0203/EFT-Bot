#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "getMat.h"
#include "InputMK.h"
#include "DistributorForMatching.h"
using namespace std;
using namespace cv;



namespace Checks {
	void CheckForFails();
	array<Mat, 11> TakeScreenshots();

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
			Sleep(200);
			ReturnMatScreen[i] = getMat(hWND);
			Sleep(200);
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
		}

		return ReturnMatScreen;
	}
}

class checksPublic {
public:
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
};

class findFreeSlots {
	vector<vector<POINT>> FinalResults;
	vector<POINT> Clean_ReturnPoints;

	vector<vector<POINT>> SortINrows(vector<POINT> vector_Input) {
		vector<vector<POINT>> vector_return;
		vector<POINT> temp;
		unordered_set<int> unset;

		for (POINT point : vector_Input) {
			if (unset.find(point.y) == unset.end()) {
				unset.insert(point.y);

				for (POINT pointIN : vector_Input) {

					if (point.y == pointIN.y) {
						temp.push_back(pointIN);
					}
				}

				std::sort(temp.begin(), temp.end(), comparePoints);
				vector_return.push_back(temp);
				temp.clear();
			}
		}
		return vector_return;
	}

	static bool comparePoints(const POINT& a, const POINT& b) {
		return a.x < b.x;
	}


public:
	template <typename T>
	void findeSlots(shared_ptr<T> case_shared_ptr) { //parent case must be open to use this function
		Mat MatScreen;
		Mat templ = imread("ObjectImages/EmptySquare.png");
		int freeSlots = {};

		Mouse::MoverPOINTandPressTwoTimes(case_shared_ptr->point);

		HWND hWND = FindeWindow();
		SetForegroundWindow(hWND);
		Sleep(5);//Delete later
		MatScreen = getMat(hWND);

		vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ, 0.99999);

		Clean_ReturnPoints = Matching::removeDuplicates(ReturnPoints);

		FinalResults = SortINrows(Clean_ReturnPoints);

		case_shared_ptr->freeSlots = FinalResults;
	}

	void Print_Out_Case_EmptySlots() {
		if (!FinalResults.empty()) {
			for (int i = 0; i < FinalResults.size(); i++) {
				if (FinalResults[i].size() == 0) {
					cout << "       |->";
					cout << " Lines: " << std::to_string(i) << " Total slots: " << Clean_ReturnPoints.size() - 1 << endl;
					break;
				}

				int count = 0;
				int length = 0;
				string str = {};
				string strIE = {};
				string strER = {};

				for (POINT point : FinalResults[i]) {
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
			FinalResults.clear();
		}
		else {
			cout << "You must first call the function: findFreeSlots::findSlots()." << endl;
		}
	}
};
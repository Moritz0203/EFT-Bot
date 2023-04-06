//#include "StartUp.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_set>
#include <utility>
#include <functional>
#include "ItemMoving.h"
#include "InitializeMovPrefix.h"
using namespace std;

//external controllers for applications / ECFA
//Rick and Morty Staffel 4 - Folge 4

struct pair_hash {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		return hash<T1>()(p.first) ^ hash<T2>()(p.second);
	}
};

struct SpecsForItem {
	int columns;
	int rows;
};

bool comparePoints(const POINT& a, const POINT& b);
bool Vertical(shared_ptr<vector<vector<POINT>>> ptr_vector, SpecsForItem specsForItem);
bool Horizontal(shared_ptr<vector<vector<POINT>>> ptr_vector, SpecsForItem specsForItem);
void remove_points(std::shared_ptr<std::vector<std::vector<POINT>>> &ptr_vector, std::vector<std::shared_ptr<POINT>> &vector_ptr_LookUp);
bool CheckColumn(shared_ptr<vector<POINT>> ptr_vector_row, int rows, vector<shared_ptr<POINT>>& vector_ptr_LookUp, int x_FistLook_lastRow);
bool Check_for_Space(shared_ptr<vector<vector<POINT>>> ptr_vector, int ItemSize);



class findFreeSlots_test{
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
	vector<vector<POINT>> findeSlots(vector<POINT> ReturnPoints) { //parent case must be open to use this function
		//Mat MatScreen;
		//Mat templ = imread("ObjectImages/EmptySquare.png");
		//int freeSlots = {};

		//Mouse::MoverPOINTandPressTwoTimes(case_shared_ptr->point);

		//HWND hWND = FindeWindow();
		//SetForegroundWindow(hWND);
		//Sleep(5);//Delete later
		//MatScreen = getMat(hWND);

		/*vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ, 0.99999);*/

		Clean_ReturnPoints = Matching::removeDuplicates(ReturnPoints);

		return FinalResults = SortINrows(Clean_ReturnPoints);

		/*case_shared_ptr->freeSlots = FinalResults;*/
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



bool Vertical(shared_ptr<vector<vector<POINT>>> ptr_vector, SpecsForItem specsForItem) {
	vector<shared_ptr<POINT>> vector_ptr_LookUp;
	shared_ptr<vector<POINT>> ptr_vector_row;
	bool break_tryNew = false;
	
	for (int i = 0; i < ptr_vector->size(); i++) {
		ptr_vector_row = make_shared<vector<POINT>>((*ptr_vector)[i]);

		cout << "index -> " << i << endl;
		bool checkColumn = CheckColumn(ptr_vector_row, specsForItem.columns, vector_ptr_LookUp, NULL);

		if (checkColumn) {
			cout << "--- Reuckgabewert ist true ---\n" << endl;
		} else {
			cout << "--- Reuckgabewert ist false ---\n" << endl;
		}
		

		if (checkColumn == true || break_tryNew != false) {
			int index = 0;
			int index_ptr = i;

			cout << "    --- Inner Check ---" << endl;

			for (int i2 = 1; i2 < specsForItem.rows; i2++) {
				ptr_vector_row = make_shared<vector<POINT>>((*ptr_vector)[index_ptr++]);
				int x_FirstLook_lastRow = vector_ptr_LookUp[index]->x;

				cout << "    --- Index ->" << i2 << endl;

				index += specsForItem.columns;

				if (!CheckColumn(ptr_vector_row, specsForItem.columns, vector_ptr_LookUp, x_FirstLook_lastRow)) {
					break_tryNew = true;
					break;
				}
			}

			if (break_tryNew == false) {
				remove_points(ptr_vector, vector_ptr_LookUp);
				return true;
			}	
		}
		else {
			vector_ptr_LookUp.clear();
		}
	}
	return false;
}

bool Horizontal(shared_ptr<vector<vector<POINT>>> ptr_vector, SpecsForItem specsForItem) {
	vector<shared_ptr<POINT>> vector_ptr_LookUp;
	shared_ptr<vector<POINT>> ptr_vector_row;
	bool break_tryNew = false;

	for (int i = 0; i < ptr_vector->size(); i++) {
		ptr_vector_row = make_shared<vector<POINT>>((*ptr_vector)[i]);

		if (CheckColumn(ptr_vector_row, specsForItem.columns, vector_ptr_LookUp, NULL) || break_tryNew != false) {
			int index = 0;
			int index_ptr = i;

			for (int i2 = 1; i2 <= specsForItem.rows; i2++) {
				ptr_vector_row = make_shared<vector<POINT>>((*ptr_vector)[index_ptr++]);
				int x_FirstLook_lastRow = vector_ptr_LookUp[index]->x;
				index += specsForItem.columns;

				if (!CheckColumn(ptr_vector_row, specsForItem.columns, vector_ptr_LookUp, x_FirstLook_lastRow)) {
					break_tryNew = true;
					break;
				}
			}

			if (break_tryNew == false) {
				remove_points(ptr_vector, vector_ptr_LookUp);
				return true;
			}
		}
		else {
			vector_ptr_LookUp.clear();
		}
	}
	return false;
}


void remove_points(std::shared_ptr<std::vector<std::vector<POINT>>> &ptr_vector, std::vector<std::shared_ptr<POINT>> &vector_ptr_LookUp) {
	for (vector<POINT> vector_point : (*ptr_vector)) {
		for (shared_ptr<POINT> remuve_point : vector_ptr_LookUp) {
			vector_point.erase(std::remove_if(vector_point.begin(), vector_point.end(), [&](const POINT& p) {  return p.x == remuve_point->x && p.y == remuve_point->y;  }), vector_point.end());
		}
	}
	ptr_vector->shrink_to_fit();
}


bool CheckColumn(shared_ptr<vector<POINT>> ptr_vector_row, int column, vector<shared_ptr<POINT>> &vector_ptr_LookUp, int x_FistLook_lastRow) {
	shared_ptr<POINT> ptr_LookUp;
	shared_ptr<POINT> ptr_LookUp_In;
	vector<POINT> vector_row = (*ptr_vector_row);
	cout << "column size -> " << column << endl;
	cout << "vector row size -> " << vector_row.size() << endl;

	for (int i = 0; i < vector_row.size(); i++) {
		POINT temp_lookUp;
		ptr_LookUp = make_shared<POINT>(vector_row[i]);

		cout << "Berechnung -> " << ptr_LookUp->x << " ";

		temp_lookUp.x = ptr_LookUp->x + 63; // weil jedes empty space immer 63 pixel auseinader ist.

		cout << temp_lookUp.x << endl;
		int count_foundet = 2;

		vector_ptr_LookUp.push_back(ptr_LookUp);

		int i_in = i + 1;
		for (; i_in < vector_row.size(); i_in++) {

			ptr_LookUp_In = make_shared<POINT>(vector_row[i_in]);

			cout << "Points vergleichen ->     " << temp_lookUp.x << " <- -- -> " << ptr_LookUp_In->x << endl;

			if (temp_lookUp.x == ptr_LookUp_In->x) {
				cout << "--- Die Points sind gleich\n" << endl;
				if (count_foundet > column) {
					cout << "true --- Funktion Check Column ende" << endl;
					return true;
				}
				else {
					temp_lookUp.x += 63; // weil jedes empty space immer 63 pixel auseinader ist.
					count_foundet++;
					vector_ptr_LookUp.push_back(ptr_LookUp_In);
				}
			}
			else
				cout << "--- Points sind nicht gleich\n" << endl; break;
		}
	}
}



bool Check_for_Space(shared_ptr<vector<vector<POINT>>> ptr_vector, int ItemSize) {
	//switch (ItemSize)
	//{
	//case 6:
		SpecsForItem SixSlotsVertical(2, 3);
		SpecsForItem SixSlotsHorizontal(3, 2);

		if (Vertical(ptr_vector, SixSlotsVertical)) {
			cout << "es ist genug platz vor handen" << endl;
			return true; // genug Platz vor handen
		}
		//else if (Horizontal(ptr_vector, SixSlotsHorizontal)) {
		//	cout << "es ist genug platz vor handen" << endl;
		//	return true; // genug Platz vor handen
		//}
		else {
			//Do something : wenn beides fehlschlägt
			cout << "beides fehlgeschlagen" << endl;
			return false;
		}
	//}
	

}





int main() {
	
	
  /*cout << "//    ___ ___ _____         ___  ___  ___ _____         ___  ___ _____  " << endl;
	cout << "//   | __| __|_   _|  ___  / __|/ _ \| _ \_   _|  ___  | _ )/ _ \_   _| " << endl;
	cout << "//   | _|| _|  | |   |___| \__ \ (_) |   / | |   |___| | _ \ (_) || |   " << endl;
	cout << "//   |___|_|   |_|      _  |___/\___/|_|_\_|_|_ _      |___/\___/ |_|   " << endl;
	cout << "//                     | |__ _  _  | __/ __| __/_\                      " << endl;
	cout << "//                     | '_ \ || | | _| (__| _/ _ \                     " << endl;
	cout << "//                     |_.__/\_, | |___\___|_/_/ \_\                    " << endl;
	cout << "//                           |__/                                       " << endl;*/

	cout << "Welcome to EFT-SORT-BOT" << endl;
	cout << "by ECFA" << endl;
	cout << endl;
		
	
	/*InitializeMovPrefix::Initialize();*/



	/*HWND hWND = FindeWindow();
	SetForegroundWindow(hWND);
	Sleep(100);
	Mat MatScreen = getMat(hWND);*/
	

	string Start = "test";
	

	/*if (Start == "start") {
		StartUp::Entrance();
	}*/
	if (Start == "test") {
		/*ItemMoving::AmmunitionMoving();*/

		Mat templ;
		Mat templ1;

		Mat MatScreen = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_3.png");
		
		/*vector<POINT> ReturnPoints;*/
		//vector<POINT> ReturnPoints;
		/*templ = imread("CaseImages/HolodilnickCase.png");*/
		templ1 = imread("ObjectImages/EmptySquare.png");
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);
		/*const char* image_window2 = "Source Image2222222222";
		namedWindow(image_window2, WINDOW_AUTOSIZE);*/

		//TemplateMatching::templateMatchingItems("ObjectImages/EmptySquare.png", 0.99999, false, false, "BP", ReturnPoints, MatScreen);

		vector<POINT> ReturnPoints = TemplateMatching::templateMatchingObjects_Vector(MatScreen, templ1, 0.99999);

		

		findFreeSlots_test findFreeSlots1;
		vector<vector<POINT>> FinalResult = findFreeSlots1.findeSlots(ReturnPoints);

		findFreeSlots1.Print_Out_Case_EmptySlots();

		shared_ptr<vector<vector<POINT>>> ptr_vector = make_shared<vector<vector<POINT>>>(FinalResult);

		cout << Check_for_Space(ptr_vector, 6) << endl;








		/*Mat MatScreen1 = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_3.png");

		vector<POINT> ReturnPoints1 = TemplateMatching::templateMatchingObjects_Vector(MatScreen1, templ1, 0.99999);


		findFreeSlots1.findeSlots(ReturnPoints1);

		findFreeSlots1.Print_Out_Case_EmptySlots();*/

		/*for (int i = 0; i < ReturnPoints.size(); i++) {
			cout << ReturnPoints[i].y << " " << ReturnPoints[i].x << "----2 - " << i << endl;
		}*/

		
		//cv::Rect rec; 

		//rec.height = templ.cols;
		//rec.width = templ.rows;
		//rec.x = ReturnPoints[0].x;
		//rec.y = ReturnPoints[0].y;

		/*ColorMatching::colorMatching(rec, MatScreen);*/


		//TemplateMatching::templateMatchingItems("CaseImages/AmmoCase.png", 0.90, false, false, "amo", ReturnPoints1, MatScreen);

		///*cout << ReturnPoints[0].y << " " << ReturnPoints[0].x << endl;
		//cout << ReturnPoints1[0].y << " " << ReturnPoints1[0].x << endl;*/

		//POINT pointA{};
		//POINT pointB{};

		//pointB.y = (templ1.rows / 2) + ReturnPoints1[0].y;
		//pointB.x = (templ1.cols / 2) + ReturnPoints1[0].x;



		///*unordered_set<int> unSet;
		//vector<POINT> result;
		//for (POINT point : ReturnPoints) {
		//	int x_minus_1 = point.x - 1;
		//	int x_plus_1 = point.x + 1;
		//	if (unSet.find(point.x) == unSet.end() && unSet.find(x_minus_1) == unSet.end() && unSet.find(x_plus_1) == unSet.end()) {
		//		result.push_back(point);
		//		unSet.insert(point.x);
		//		unSet.insert(x_minus_1);
		//		unSet.insert(x_plus_1);
		//	}
		//}*/


		/*unordered_set<pair<int, int>, pair_hash> unSet;
		vector<POINT> result;
		for (POINT& point : ReturnPoints) {
			int x_minus_1 = point.x - 1;
			int x_plus_1 = point.x + 1;
			int y_minus_1 = point.y - 1;
			int y_plus_1 = point.y + 1;
			pair<int, int> point_x = make_pair(point.x, point.y);
			pair<int, int> point_x_minus_1 = make_pair(x_minus_1, point.y);
			pair<int, int> point_x_plus_1 = make_pair(x_plus_1, point.y);
			pair<int, int> point_y = make_pair(point.x, point.y);
			pair<int, int> point_y_minus_1 = make_pair(point.x, y_minus_1);
			pair<int, int> point_y_plus_1 = make_pair(point.x, y_plus_1);
			if (unSet.find(point_x) == unSet.end() && unSet.find(point_x_minus_1) == unSet.end() && unSet.find(point_x_plus_1) == unSet.end()
				&& unSet.find(point_y) == unSet.end() && unSet.find(point_y_minus_1) == unSet.end() && unSet.find(point_y_plus_1) == unSet.end()) {
				result.push_back(point);
				unSet.insert(point_x);
				unSet.insert(point_x_minus_1);
				unSet.insert(point_x_plus_1);
				unSet.insert(point_y);
				unSet.insert(point_y_minus_1);
				unSet.insert(point_y_plus_1);
			}
		}




		for (int i = 0; i < result.size(); i++) {
			cout << result[i].y << " " << result[i].x << " ---- " << i << endl;
		}

		vector<vector<POINT>> JunkCase;
		vector<POINT> temp;
		unordered_set<int> unset;

		for (POINT point : result) {
			if (unset.find(point.y) == unset.end()) {
				unset.insert(point.y);

				for (POINT pointIN : result) {

					if (point.y == pointIN.y) {
						temp.push_back(pointIN);
					}
				}
				
				std::sort(temp.begin(), temp.end(), comparePoints);
				JunkCase.push_back(temp);
				temp.clear();
			}
			
		}
			
		

		
		for (int i = 0; i < JunkCase.size(); i++) {
			int count = 0;
			int length = 0;
			string str = {};
			string strIE = {};
			string strER = {};
			
			if (JunkCase[i].size() == 0)
				break;

			for (POINT point : JunkCase[i]) {
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
		
		cout << ReturnPoints.size() << endl;*/

		//for (int i = 0; i < result.size(); i++) {
		//	pointA.y = (templ.rows / 2) + result[i].y;
		//	pointA.x = (templ.cols / 2) + result[i].x;

		//	Mouse::MouseMoveAtoB(pointA, pointB);
		//}
		
		//cout << "------" << endl;
		//
		//Rect Rec(ReturnPoints[0].x + 45, ReturnPoints[0].y + 46, templ.cols - 45, templ.rows - 46);
		////Rect Rec(ReturnPoints[0].x , ReturnPoints[0].y , templ.cols, templ.rows );

		//Mat Roi2;
		//Mat Roi = MatScreen(Rec);
	

		/*Mat temp = imread("ObjectImages/FoundInRaid/FoundInRaid-Blue.png");
		if (TemplateMatching::templateMatchingBool(Roi, temp, 0.99)) {
			cout << "found in raid" << endl;
		}*/

		/*Mat blacktext = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_5.png");

		cv::imshow(image_window, blacktext);

		TextMatching::txttest(blacktext);*/

		/*MatScreen = imread("C:/Users/morit/OneDrive/Desktop/EFT-Sort-Bot/Images/Screenshot_5.png");*/

		/*const string str = TextMatching::textMatching(MatScreen, Rec);

		cout << str << endl;*/


		//const char test = '-';
		///*if (str[9] == test) {
		//	cout << "test" << endl;
		//}*/

		//int i1 = -1;
		//for (int i = 0; i < str.length(); i++) {
		//	i1++;
		//	cout << str[i] << " --- " << i1 << endl;
		//}

		//cout << str[str.back() - 1] << "<------ " << i1 << endl;

		/*cout << "123" << endl;*/
		//imshow(image_window, Roi);
		///*imshow(image_window2, Roi2);*/
		//waitKey(0);
		
		
		//cv::cvtColor(Roi, Roi, cv::COLOR_BGR2HSV);

		//if (!ReturnPoints[0].y <= 500) {
		//	/*Roi2 = Roi + cv::Scalar(-17, -17, -17);*/
		//	Roi2 = Roi + cv::Scalar(-20, -20, -20);
		//	cout << "hey" << endl;
		//}

		//int i{}, i2{}, i3{};
		//while (true)
		//{
		//	i--;
		//	i2--;
		//	i3--;
		//	Roi2 = Roi + cv::Scalar(i, i2, i3);	

		//	color = TemplateMatching::ColorMatching(Rec, Roi2);

		//	system("cls");
		//	cout << color << " " << "color " << i << " " << i2 << " " << i3 <<  endl;
		//	if (color == 0)// Green -34 / Blue -64 / 
		//		break;
		//}

		/*color = TemplateMatching::ColorMatching(Rec, Roi);
		
		cout << color << " " << "color" << endl;*/

		/*CaseMatching::THICCcase();*/
	}

	/*for (int i = 0; i < Returner.size(); i++) {
			cout << Returner[i].y << " " << Returner[i].x << endl;
	}*/


	
}

bool comparePoints(const POINT& a, const POINT& b) {
	return a.x < b.x;
}
#include "getMat.h"
#include "StartUp.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

//external controllers for applications / ECFA
void startFunktion(vector<POINT> &Returner, Mat MatScreen);
void CheckForFails();
void CheckScrollbarPositions();
void Magic();
void cleanUpVector();
array<Mat, 11> TakeScreenshots();


int main() {

	CheckForFails();

	CheckScrollbarPositions();

	Magic();

	//vector<POINT> Returner;
	//
	//
	//HWND hWND = FindeWindow();
	//SetForegroundWindow(hWND);
	//Sleep(100);
	//Mat MatScreen = getMat(hWND);
	//

	//string Start;
	//cin >> Start;

	//if (Start == "start") {
	//	/*startFunktion(Returner, MatScreen);*/
	//	StartUp::Entrance();
	//}
	//if (Start == "test") {
	//	
	//	/*const char* image_window = "Source Image";
	//	namedWindow(image_window, WINDOW_AUTOSIZE);*/
	//	Mat templ = imread("ObjectImages/Intel.png");

	//	/*int width = templ.cols / 2;
	//	int height = templ.rows / 2;*/
	//	
	//	TemplateMatching::templateMatchingItems("", "ObjectImages/Weapon.png", 0.90, false, false, "Intel", Returner, MatScreen);   // 807  464  122    div1  343  div2  342     1Solt

	//																																// 814  471  128    div1  343  div2  343     1Slot
	//																																
	//																																// 500  157         div1  343                2Solt

	//																																// 535  192         div1  343                3Slot
	//	/*cout << point.y + height << " " << point.x + width << endl;*/

	//	/*point.y = height + point.y;
	//	point.x = width + point.x;*/

	//	
	//	/*Mat img_display;
	//	img.copyTo(img_display);
	//	imshow(image_window, img);
	//	waitKey(0);*/


	//}

	//for (int i = 0; i < Returner.size(); i++) {
	//		cout << Returner[i].y << " " << Returner[i].x << endl;
	//}
}

void startFunktion(vector<POINT> &Returner, Mat MatScreen) {
	Returner = Matching::AmmunitionMatching(MatScreen);
}


	

	void Entrance() {



		CheckForFails();

		CheckScrollbarPositions();

		Magic();
		/*const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);*/



		/*int size = sizeof(ReturntMatScreen) / sizeof(Mat);
		for (int i = 0; i < size; i++) {
			imshow(image_window, ReturntMatScreen[i]);
			waitKey(0);
		}*/
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
			Sleep(250);
			ReturnMatScreen[i] = getMat(hWND);
			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
			Keyboard::KeyboardInput(keyforInput);
		}

		return ReturnMatScreen;
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
			waitKey(200);
		}



		for (int i = 0; i < 5; i++) {
			ReturnPoints = Matching::AmmunitionMatching(ReturntMatScreen[i]);
			if ( !ReturnPoints.empty()) {
				PointVectorTemp.push_back(ReturnPoints);
				cout << " -----------------------------------------------------------------------------------\n";
			}
		}
		

		cleanUpVector();
		cout << "Not Clean\n";
		for (int i = 0; i < PointVectorTemp.size(); i++) {
			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {
				cout << PointVectorTemp[i][i2].y << " " << PointVectorTemp[i][i2].x << endl;
			}
		}

		cout << "Clean\n";
		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
			for (int i2 = 0; i2 < PointVectorCleanUp[i].size(); i2++) {
				cout << PointVectorCleanUp[i][i2].y << " " << PointVectorCleanUp[i][i2].x << endl;
			}
		}
	}


	void cleanUpVector() {
		vector<POINT> temp;
		if (!PointVectorTemp.size() >= 1)
			return;

		temp = PointVectorTemp[0];
		PointVectorCleanUp.push_back(temp);
		temp.clear();

		int iTemp = 1;
		for (int i = 1; i < PointVectorTemp.size(); i++ ) {// Loop the vector
			iTemp++;

			if (iTemp == PointVectorTemp.size())
				break;
			
			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {//Loop through the vector of vector 
				
				for (int i3 = 0; i3 < PointVectorTemp[iTemp].size(); i3++) {//Loop through the next vector of vector  
					bool FoundDuplicate = false;
					
					POINT pointLookForLast = PointVectorTemp[i][i2];
					pointLookForLast.y + 340;
					POINT pointTempGround = PointVectorTemp[iTemp][i3];
					pointTempGround.y = 340 + pointTempGround.y;

					if (pointLookForLast.y == PointVectorTemp[iTemp][i3].y && pointLookForLast.x == PointVectorTemp[iTemp][i3].x)
						break;

					for (int i4 = 0; i4 < 6; i4++) {//To run pointTemp from 340 to 345 and compare with the current point in the next vector  
						POINT pointTemp = pointTempGround;
						pointTemp.y = pointTemp.y + i4;

						if (PointVectorTemp[i][i2].y == pointTemp.y && PointVectorTemp[i][i2].x == pointTemp.x) {//Check if pointTemp is equal to the current point in the next vector
							FoundDuplicate = true;	   
							break;																					
						} 	                                                                                          
					}
				
					if (FoundDuplicate == true) {//If a duplicate was found the point that was compared is pushed to temp
						temp.push_back(PointVectorTemp[i][i2]);
					}	
				}
				
				if (!temp.empty()) {
					PointVectorCleanUp.push_back(temp);
					temp.clear();
				}	
			}
		}
	}


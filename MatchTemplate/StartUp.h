#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "InputMT.h"
#include "DistributorForMatching.h"
using namespace std;
using namespace cv;




//namespace StartUp {
//	void CheckForFails();
//	void CheckScrollbarPositions();
//	void Magic();
//	void cleanUpVector();
//	array<Mat, 11> TakeScreenshots();
//
//	void Entrance() {
//
//		
//
//		CheckForFails();
//
//		CheckScrollbarPositions();
//
//		Magic();
//		/*const char* image_window = "Source Image";
//		namedWindow(image_window, WINDOW_AUTOSIZE);*/
//
//		
//
//		/*int size = sizeof(ReturntMatScreen) / sizeof(Mat);
//		for (int i = 0; i < size; i++) {
//			imshow(image_window, ReturntMatScreen[i]);
//			waitKey(0);
//		}*/
//	}
//
//	void CheckForFails() {
//		Mat MatScreen;
//		Mat templ;
//		POINT pointMouse = {};
//		pointMouse.y = 729;
//		pointMouse.x = 961;
//
//		HWND hWND = FindeWindow();
//		SetForegroundWindow(hWND);
//		Sleep(5);//Delete later
//		MatScreen = getMat(hWND);
//
//		templ = imread("ObjectImages/Banner.png");
//		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.98);
//		if (point.y || point.x != 0)
//			Mouse::MoverPOINTandPress(pointMouse); //729 961
//	}
//
//	void CheckScrollbarPositions() {
//		Mat MatScreen;
//		Mat templ;
//
//		HWND hWND = FindeWindow();
//		SetForegroundWindow(hWND);
//		Sleep(5);//Delete later
//		MatScreen = getMat(hWND);
//
//		templ = imread("ObjectImages/scrollbar.png");
//		POINT point = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
//		if (point.y > 79) {// Later with screen resolution
//			point.y = (templ.rows / 2) + point.y;
//			point.x = (templ.cols / 2) + point.x;
//			Mouse::MoverPOINTandPress(point);
//			int keyforInput = 0x21;// virtual-key code for the "PAGE UP KEY" key
//			Keyboard::KeyboardInput(keyforInput);
//		}
//	}
//
//	array<Mat, 11> TakeScreenshots() {
//		Mat MatScreen;
//		array<Mat, 11> ReturnMatScreen;
//
//		HWND hWND = FindeWindow();
//		SetForegroundWindow(hWND);
//		Sleep(5);//Delete later
//
//		POINT point{};
//		point.y = 171;
//		point.x = 1903;
//		Mouse::MoverPOINTandPress(point);
//
//		int size = sizeof(ReturnMatScreen) / sizeof(Mat);
//		for (int i = 0; i < size; i++) {
//			Sleep(250);
//			ReturnMatScreen[i] = getMat(hWND);
//			int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
//			Keyboard::KeyboardInput(keyforInput);
//		}
//
//		return ReturnMatScreen;
//	}
//
//	vector<vector<POINT>> PointVectorTemp;
//	vector<vector<POINT>> PointVectorCleanUp;
//
//	void Magic() {
//		array<Mat, 11> ReturntMatScreen;
//		vector<POINT> ReturnPoints;
//		ReturntMatScreen = TakeScreenshots();
//		const char* image_window = "Source Image";
//		namedWindow(image_window, WINDOW_AUTOSIZE);
//
//
//
//		int size = sizeof(ReturntMatScreen) / sizeof(Mat);
//		for (int i = 0; i < size; i++) {
//			imshow(image_window, ReturntMatScreen[i]);
//			waitKey(200);
//		}
//
//		
//
//		for ( int i = 0; i < size; i++) {
//			ReturnPoints.clear();
//			ReturnPoints = Matching::AmmunitionMatching(ReturntMatScreen[i]);
//			if (ReturnPoints[i].y != 0 || ReturnPoints[i].x != 0) {
//				PointVectorTemp.push_back(ReturnPoints);
//				cout << " her \n";
//			}
//
//			/*if (!ReturnPoints.empty())*/
//				
//		}
//
//		cleanUpVector();
//		
//		for (int i = 0; i < PointVectorTemp.size(); i++) {
//			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {
//				cout << PointVectorTemp[i][i2].y << PointVectorTemp[i][i2].x << endl;
//			}
//		}
//
//		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
//			for (int i2 = 0; i2 < PointVectorCleanUp[i].size(); i2++) {
//				cout << PointVectorCleanUp[i][i2].y << PointVectorCleanUp[i][i2].x << endl;
//			}
//		}
//	}
//
//
//
//
//	void cleanUpVector() {
//		if (!PointVectorTemp.size() >= 1)
//			return;
//
//		PointVectorCleanUp[1] = PointVectorTemp[1];
//		for (int i = 0; i < PointVectorTemp.size(); i++) {//Um denn Main vector zu durchlaufen
//			for (int i2 = 0; i2 < PointVectorTemp[i].size(); i2++) {//Um in dem Main vector die einzelnen zu druchlaufen 
//				POINT pointTemp = PointVectorTemp[i][i2];
//				
//				int iTemp = i;
//				iTemp++;
//				for (int i3 = 0; i3 < PointVectorTemp[iTemp].size(); i3++) {//Um das nächste teil im Main vector zu druchlaufen 
//					bool FoundDuplicate;
//					for (int i4 = 0; i4 < 6; i4++) {//Um Point temp von 340 bis 345 zu druch lauf und mit dem aktuellen point im nächsten Main vector so vergleichen 
//						pointTemp.y + 340 + i4;
//						if (pointTemp.y == PointVectorTemp[iTemp][i3].y && pointTemp.x == PointVectorTemp[iTemp][i3].x) {	// Checken ob pointTemp gleich dem aktuellen Point im nächsten Main vector nicht entspreicht wenn ja dann soll der aktuelle punkt 
//							FoundDuplicate = true;	 																		// in denn entgültigen vector of vector gepusht werden wenn er aber gleich ist soll er nicht gespeichert werden und es wird der nachste punkt 
//						}																									// in dem nächsten Main vector probiert so lange bist jeder punkt mit jedem punkt verglichen wurde
//						else
//							continue;
//					}
//					if (FoundDuplicate != true)
//						PointVectorCleanUp[iTemp].push_back(PointVectorTemp[iTemp][i3]);
//				}
//			}
//		}
//	}
//
//}



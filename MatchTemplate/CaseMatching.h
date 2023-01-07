#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "StartUp.h"
using namespace std;
using namespace cv;
//
//
//
//namespace CaseMatching
//{
//	void OpenCaseAndTakeScreen(vector<POINT> tempPoints, Mat templ, std::string NameOfCase, int page);
//	void MatchingCaseInCase(vector<Mat>& MatScreenVector, vector<POINT> tempPoints, int page);
//	void MoveTopBarTHICCcase();
//
//	vector<vector<POINT>> PointVectorTemp;
//	vector<vector<POINT>> PointVectorCleanUp;
//
//	vector<vector<PointCaseInStash>> pointCaseInStash;
//	vector<vector<PointCaseInCase>> pointCaseInCase;
//
//	void THICCcase() {
//		Mat templ;
//		array<Mat, 11> ReturntMatScreen;
//		vector<POINT> ReturnPoints;
//
//		StartUp::CheckScrollbarPositions();
//		ReturntMatScreen = StartUp::TakeScreenshots();
//
//		templ = imread("ObjectImages/THICCcase.png");
//		String NameOfCase = "THICCcase";
//
//		for (int i = 0; i < 8; i++) {// 5 must later be size 
//			TemplateMatching::templateMatchingItems("ObjectImages/THICCcase.png", 0.92, false, false, NameOfCase, ReturnPoints, ReturntMatScreen[i]);
//			if (!ReturnPoints.empty()) {
//				PointVectorTemp.push_back(ReturnPoints);
//				ReturnPoints.clear();
//			}
//			else {
//				PointVectorTemp.push_back(ReturnPoints);
//				ReturnPoints.clear();
//			}
//			cout << "-----------------------------------------------------------------------------------\n";
//		}
//
//		StartUp::cleanUpVector(PointVectorTemp, PointVectorCleanUp);
//
//		cout << "Clean\n";
//		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
//			for (int i2 = 0; i2 < PointVectorCleanUp[i].size(); i2++) {
//				cout << "---- " << PointVectorCleanUp[i][i2].y << " " << PointVectorCleanUp[i][i2].x << endl;
//			}
//			cout << PointVectorCleanUp[i].size() << endl;
//		}
//
//		StartUp::CheckScrollbarPositions();
//
//		
//		int page = 0;
//		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
//			if (!PointVectorCleanUp[i].size() == 0) {
//				int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
//				Keyboard::KeyboardInput(keyforInput);
//				Sleep(500);
//				OpenCaseAndTakeScreen(PointVectorCleanUp[i], templ, NameOfCase, page);
//				break;
//			}
//			else {
//				int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
//				Keyboard::KeyboardInput(keyforInput);
//				Sleep(500);
//			}
//			page++;
//		}
//
//		for (int i = 0; i < pointCaseInStash.size(); i++) {
//			for (int i2 = 0; i2 < pointCaseInStash[i].size(); i2++) {
//				cout << pointCaseInStash[i][i2].point.y << " " << pointCaseInStash[i][i2].point.x << " " << pointCaseInStash[i][i2].nameOfCase << " " << pointCaseInStash[i][i2].color << " " << pointCaseInStash[i][i2].page << endl;
//			}
//		}
//
//		PointVectorTemp.clear();
//		PointVectorCleanUp.clear();
//	}
//
//
//	void ItemsCase() {
//		Mat templ;
//		array<Mat, 11> ReturntMatScreen;
//		vector<POINT> ReturnPoints;
//		ReturntMatScreen = StartUp::TakeScreenshots();
//		templ = imread("ObjectImages/ItemsCase.png");
//		String NameOfCase = "ItemsCase";
//
//		for (int i = 0; i < 7; i++) {// 5 must later be size 
//			TemplateMatching::templateMatchingItems("ObjectImages/ItemsCase.png", 0.90, false, false, NameOfCase, ReturnPoints, ReturntMatScreen[i]);
//			if (!ReturnPoints.empty()) {
//				PointVectorTemp.push_back(ReturnPoints);
//				ReturnPoints.clear();
//			}
//			else {
//				PointVectorTemp.push_back(ReturnPoints);
//				ReturnPoints.clear();
//			}
//			cout << "-----------------------------------------------------------------------------------\n";
//		}
//
//		StartUp::cleanUpVector(PointVectorTemp, PointVectorCleanUp);
//		StartUp::CheckScrollbarPositions();
//
//		int page = 0;
//		for (int i = 0; i < PointVectorCleanUp.size(); i++) {
//			if (!PointVectorCleanUp[i].size() == 0) {
//				OpenCaseAndTakeScreen(PointVectorCleanUp[i], templ, NameOfCase, page);
//			}
//			else {
//				int keyforInput = 0x28;// virtual-key code for the "DOWN ARROW" key
//				Keyboard::KeyboardInput(keyforInput);
//			}
//			page++;
//		}
//		PointVectorTemp.clear();
//		PointVectorCleanUp.clear();
//	}
//	
//
//	
//
//	class OtherCasesClass {
//		vector<vector<PointCaseInStash>> PointCaseInStasTemp;
//		vector<vector<PointCaseInStash>> PointCaseInStasCleanUp;
//
//		std::array<std::string, 8> Cases{
//			"itemImages/CaseImages/AmmoCase.png",
//			"itemImages/CaseImages/GrenadCase.png",
//			"itemImages/CaseImages/HolodilnickCase.png",
//			"itemImages/CaseImages/MagCase.png",
//			"itemImages/CaseImages/MedCase.png",
//			"itemImages/CaseImages/MoneyCase.png",
//			"itemImages/CaseImages/JunkCase.png",
//			"itemImages/CaseImages/WeaponsCase.png",
//		};
//
//		std::array<std::string, 8> NameOfItemCases{
//			"AmmoCase",
//			"GrenadCase",
//			"HolodilnickCase",
//			"MagCase",
//			"MedCase",
//			"MoneyCase",
//			"JunkCase",
//			"WeaponsCase",
//		};
//
//		std::array<double, 8> CasesThreshold{
//			0.90,//AmmoCase
//			0.90,//GrenadCase
//			0.90,//HolodilnickCase
//			0.90,//MagCase
//			0.90,//MedCase
//			0.90,//MoneyCase
//			0.90,//JunkCase
//			0.90,//WeaponsCase
//		};
//
//		void OtherCases() {
//			PointCaseInStash pointCasetempStash;
//			vector<PointCaseInStash> pointCasetempStashVector;
//			array<Mat, 11> ReturntMatScreen;
//
//			StartUp::CheckScrollbarPositions();
//			ReturntMatScreen = StartUp::TakeScreenshots();
//			
//			Color color{};
//			Mat templ;
//
//			vector<POINT> ReturnDataCase;
//			int size = sizeof(Cases) / sizeof(string);
//			for (int i = 0; i < 7; i++) {// 5 must later be size 
//				for (int i2 = 0; i2 < size; i2++) {
//					TemplateMatching::templateMatchingItems(Cases[i2], CasesThreshold[i2], false, false, NameOfItemCases[i2], ReturnDataCase, ReturntMatScreen[i]);
//					templ = imread(Cases[i2]);
//
//					if (!ReturnDataCase.empty()) {
//						for (int i3 = 0; i3 < ReturnDataCase.size(); i3++) {
//							Rect Rec(ReturnDataCase[i3].x, ReturnDataCase[i3].y, templ.cols, templ.rows);
//							color = TemplateMatching::ColorMatching(Rec, ReturntMatScreen[i]);
//							pointCasetempStashVector.emplace_back(ReturnDataCase[i3], NameOfItemCases[i2], color, templ.rows, templ.cols, i);
//						}
//						ReturnDataCase.clear();
//					}
//				}
//				PointCaseInStasTemp.emplace_back(pointCasetempStashVector);
//				pointCasetempStashVector.clear();
//				cout << "-----------------------------------------------------------------------------------\n";
//			}
//
//			StartUp::cleanUpVectorOnParameters(PointCaseInStasTemp, PointCaseInStasCleanUp);
//		}
//	};
//	
//
//
//	void OpenCaseAndTakeScreen(vector<POINT> tempPoints, Mat templ, std::string NameOfCase, int page) {
//		Color color;
//		Mat MatScreen;
//		vector<PointCaseInStash> pointCasetempStash;
//		vector<Mat> MatScreenVector;
//
//
//		HWND hWND = FindeWindow();
//		SetForegroundWindow(hWND);
//		Sleep(5);//Delete later
//		MatScreen = getMat(hWND);
//
//		const char* image_window = "Source Image";
//		namedWindow(image_window, WINDOW_AUTOSIZE);
//		for (int i = 0; i < tempPoints.size(); i++) {
//			Rect Rec(tempPoints[i].x, tempPoints[i].y, templ.cols, templ.rows);
//			color = TemplateMatching::ColorMatching(Rec, MatScreen);
//			pointCasetempStash.emplace_back(tempPoints[i], NameOfCase, color, templ.rows, templ.cols, page);
//
//
//			Mat Roi = MatScreen(Rec);
//			imshow(image_window, Roi);
//			waitKey(0);
//		}
//
//
//
//
//		pointCaseInStash.emplace_back(pointCasetempStash);
//		pointCasetempStash.clear();
//
//
//		// testen 
//		POINT point{};
//		for (int i = 0; i < pointCasetempStash.size(); i++) {
//			point.y = (pointCasetempStash[i].heightTempl / 2) + pointCasetempStash[i].point.y;
//			point.x = (pointCasetempStash[i].widthTempl / 2) + pointCasetempStash[i].point.x;
//			Mouse::MoverPOINTandPressTwoTimes(point);
//
//			if (NameOfCase == "THICCcase") {
//				MoveTopBarTHICCcase();
//			}
//
//			HWND hWND = FindeWindow();
//			SetForegroundWindow(hWND);
//			MatScreenVector.push_back(getMat(hWND));
//
//			int keyforInput = 0x1B;// virtual-key code for the "ESC button" key
//			Keyboard::KeyboardInput(keyforInput);
//		}
//
//		/*MatchingCaseInCase(MatScreenVector, tempPoints, page);*/
//
//	}
//
//
//	std::array<std::string, 6> CasesInCase{
//		"itemImages/CaseImages/AmmoCase.png",
//		"itemImages/CaseImages/GrenadCase.png",
//		"itemImages/CaseImages/HolodilnickCase.png",
//		"itemImages/CaseImages/MagCase.png",
//		"itemImages/CaseImages/MedCase.png",
//		"itemImages/CaseImages/MoneyCase.png",
//	};
//
//	std::array<std::string, 6> NameOfItemCasesInCase{
//		"AmmoCase",
//		"GrenadCase",
//		"HolodilnickCase",
//		"MagCase",
//		"MedCase",
//		"MoneyCase",
//	};
//
//	std::array<double, 6> CasesInCaseThreshold{
//		0.90,//AmmoCase
//		0.90,//GrenadCase
//		0.90,//HolodilnickCase
//		0.90,//MagCase
//		0.90,//MedCase
//		0.90,//MoneyCase
//	};
//
//	void MatchingCaseInCase(vector<Mat> &MatScreenVector, vector<POINT> tempPoints, int page) {
//		string  filename, templatename;
//		double	threshold;
//		int size = sizeof(CasesInCase) / sizeof(string);
//		vector<PointCaseInCase> pointCaseInCasetemp;
//		Mat templ;
//		Color color{};
//
//		vector<POINT> ReturnDataCase;
//		for (int i = 0; i < MatScreenVector.size(); i++) {
//			for (int i2 = 0; i2 < size; i2++) {
//				threshold = CasesInCaseThreshold[i2];
//				templatename = CasesInCase[i2];
//				templ = imread(CasesInCase[i2]);
//
//				TemplateMatching::templateMatchingItems(templatename, threshold, false, true, NameOfItemCasesInCase[i], ReturnDataCase, MatScreenVector[i]);
//
//				for (int i3 = 0; i3 < ReturnDataCase.size(); i3++) {
//					Rect Rec(ReturnDataCase[i3].x, ReturnDataCase[i3].y, templ.cols, templ.rows);
//
//					color = TemplateMatching::ColorMatching(Rec, MatScreenVector[i]);
//					pointCaseInCasetemp.emplace_back(ReturnDataCase[i3], tempPoints[i], NameOfItemCasesInCase[i], color, templ.rows, templ.cols, page);
//				}
//			}
//			pointCaseInCase.emplace_back(pointCaseInCasetemp);
//			pointCaseInCasetemp.clear();
//		}
//		
//	}
//
//	void MoveTopBarTHICCcase() {
//		Mat MatScreen;
//		Mat templ;
//
//		HWND hWND = FindeWindow();
//		SetForegroundWindow(hWND);
//		MatScreen = getMat(hWND);
//
//		templ = imread("ObjectImages/THICCtopBar.png");
//		POINT pointA = TemplateMatching::templateMatchingObjects(MatScreen, templ, 0.70);
//		pointA.y = (templ.rows / 2) + pointA.y;
//		pointA.x = (templ.cols / 2) + pointA.x;
//
//		POINT pointB{};
//		pointB.x = pointA.x - 200;
//		Mouse::MouseMoveAtoB(pointA, pointB);
//	}
//};
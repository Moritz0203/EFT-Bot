#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Point.h"
using namespace std;
using namespace cv;

class TemplateMatching {
public:
	static inline int templateMatchingItems(string templatename, double threshold, bool MabyHasInsurance, bool RoiNeed,
		string NameOfItem, vector<POINT>& ReturnData, Mat MatScreen)
	{
		int height = {}, width = {};
		const char* image_window = "Source Image";
		const char* Test = "Item Image";
		int match_method = 5;
		Mat result;
		Mat img;


		img = MatScreen;
		Mat templ = cv::imread(templatename);
		if (img.empty() || templ.empty())
		{
			cout << "Error reading file(s) in templateMatching Funkion!" << endl;
			return false;
		}
		namedWindow(image_window, WINDOW_AUTOSIZE);
		/*namedWindow(Test, WINDOW_AUTOSIZE);*/


		Mat img_display;
		img.copyTo(img_display);

		int StartY = 0, StartX = 0;
		if (MabyHasInsurance == true) {
			StartY = 2; StartX = 2;
			width = templ.cols - 4;
			height = templ.rows - 35;
		}
		else if (RoiNeed == true) {
			width = templ.cols - 1;
			height = templ.rows - 20;
		}
		else {
			width = templ.cols - 0;
			height = templ.rows - 0;
		}

		Rect Rec(StartY, StartX, width, height);
		Mat Roi = templ(Rec);
		/*imshow(Test, Roi);*/

		matchTemplate(img, Roi,result, match_method);
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;

		int count = 0;
		POINT PointReturn{};
		cout << NameOfItem << endl;
		while (true)
		{
			minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
			if (maxVal >= threshold)
			{
				matchLoc = maxLoc;
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);
				/*cv::line(img_display, matchLoc, Point(0 , 0), CV_RGB(0, 255, 0), 1);*/
				cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(img.cols / 2, 0), CV_RGB(0, 255, 0), 1);
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
					PointReturn.y = matchLoc.y;
					PointReturn.x = matchLoc.x;
					ReturnData.push_back(PointReturn);
					count++;
				}
				else
					return false;
			}
			else
				break;
		}
		cout << count << endl;
		cv::imshow(image_window, img_display);

		waitKey(1);
		return templ.cols, templ.rows;
	};

public:
	static POINT templateMatchingObjects(Mat MatScreen, Mat templ, double threshold) {
		int height = {}, width = {};
		const char* image_window = "Source Image";
		const char* Test = "Item Image";
		int match_method = 5;
		Mat result;
		POINT PointReturn = {};

		/*if (MatScreen.empty() || templ.empty())
		{
			cout << "Error reading file(s) in templateMatching Funkion!" << endl;
		}*/
		namedWindow(image_window, WINDOW_AUTOSIZE);
		/*namedWindow(Test, WINDOW_AUTOSIZE);*/

		Mat img_display;
		MatScreen.copyTo(img_display);

		//imshow(Test, templ);

		matchTemplate(MatScreen, templ, result, match_method);
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;

		while (true)
		{
			minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
			if (maxVal >= threshold)
			{
				matchLoc = maxLoc;
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);
				cv::line(img_display, matchLoc, Point(0, 0), CV_RGB(0, 255, 0), 1);
				/*cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(MatScreen.cols / 2, 0), CV_RGB(0, 255, 0), 1);*/
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
					PointReturn.y = matchLoc.y;
					PointReturn.x = matchLoc.x;
				}
			}
			else
				break;
		}
		cv::imshow(image_window, img_display);

		waitKey(200);

		return PointReturn;

	};
	
	

public:
	static Color ColorMatching(Rect Rec, Mat MatScreen) {
		array<cv::Scalar, 7> ScalarLow{
			cv::Scalar(150, 230, 80), /*redLow*/
			//cv::Scalar(0, 60, 150), /*redLow    if more leight*/
			cv::Scalar(48, 195, 195), /*orangshLow*/
			cv::Scalar(28, 197, 215), /*greenLow*/
			cv::Scalar(23, 230, 248), /*blueLow*/
			//cv::Scalar(27, 227, 255), /*purpleLow*/

			cv::Scalar(0, 10, 10), /*purpleLow*/

			cv::Scalar(20, 227, 255), /*pinkLow*/
			cv::Scalar(27, 229, 254), /*grayLow */
		};

		array<cv::Scalar, 7> ScalarHigh{
			cv::Scalar(200, 280, 130), /*redHigh     1*/
			//cv::Scalar(280, 280, 280), /*redHigh     1*/
			cv::Scalar(55, 200, 200), /*orangshHigh  2*/
			cv::Scalar(33, 202, 220), /*greenHigh    3*/
			cv::Scalar(30, 240, 255), /*blueHigh*    4*/
			//cv::Scalar(30, 233, 260), /*purpleHigh   5*/

			cv::Scalar(300, 300, 300), /*purpleHigh   5*/

			cv::Scalar(27, 228, 260), /*pinkHigh     6*/
			cv::Scalar(28, 230, 255), /*grayHigh     7*/
		};
		int count = 1;
		for (int i = 0; i < 7; i++) {
			bool found = GetColor(MatScreen, ScalarLow[i], ScalarHigh[i], Rec, count++);
			if (found == true) {
				switch (i)
				{
				case 0:
					return Color::RED;
				case 1:
					return Color::ORANGSH;
				case 2:
					return Color::GREEN;
				case 3:
					return Color::BLUE;
				case 4:
					return Color::PURPLE;
				case 5:
					return Color::PINK;
				case 6:
					return Color::GRAY;					
				}
				break;
			}
		}
		return Color::NOCOLOR;
	};
	
	static bool GetColor(Mat MatScreen, cv::Scalar low, cv::Scalar high, Rect Rec, int count) {
		Mat Roi = MatScreen/*(Rec)*/;
		Mat Output;

		/*cvtColor(Roi, Roi, cv::COLOR_RGB2BGR);*/
		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);

		cv::cvtColor(Roi, Roi, cv::COLOR_BGR2HSV);

		cv::inRange(Roi, low, high, Output);

		imshow(image_window, Output);
		waitKey(0);
		
		int x1 = countNonZero(Output);
		
		cout << endl;
		cout << "---- " << x1 << " " << count <<endl;

		if (x1 >= 420)
			return true;

		return false;
	}
};

class TextMatching {
public:
	
}; 
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "Point.h"
using namespace std;
using namespace cv;

class TemplateMatching {
public:
	static inline int templateMatchingItems(string filename, string templatename, double threshold, bool MabyHasInsurance, bool RoiNeed,
		string NameOfItem, vector<POINT>& ReturnData, Mat MatScreen)
	{
		int height = {}, width = {};
		const char* image_window = "Source Image";
		const char* Test = "Item Image";
		int match_method = 5;
		Mat result;
		Mat img;

		img = cv::imread(filename);

		if (!MatScreen.empty()) {
			img = MatScreen;
		}

		Mat templ = cv::imread(templatename);
		if (img.empty() || templ.empty())
		{
			cout << "Error reading file(s) in templateMatching Funkion!" << endl;
			return false;
		}
		namedWindow(image_window, WINDOW_AUTOSIZE);
		namedWindow(Test, WINDOW_AUTOSIZE);


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
		imshow(Test, Roi);

		matchTemplate(img, Roi, result, match_method);
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
			cv::Scalar(0, 0, 100), /*redLow*/
			cv::Scalar(5, 55, 100), /*orangshLow*/
			cv::Scalar(10, 100, 70), /*greenLow*/
			cv::Scalar(80, 100, 0), /*blueLow*/
			cv::Scalar(100, 0, 40), /*purpleLow*/
			cv::Scalar(50, 0, 100), /*pinkLow*/
			cv::Scalar(100, 100, 100), /*grayLow */
		};

		array<cv::Scalar, 7> ScalarHigh{
			cv::Scalar(10, 10, 110), /*redHigh*/
			cv::Scalar(15, 65, 110), /*orangshHigh*/
			cv::Scalar(20, 110, 80), /*greenHigh*/
			cv::Scalar(90, 110, 10), /*blueHigh*/
			cv::Scalar(110, 10, 50), /*purpleHigh*/
			cv::Scalar(60, 10, 110), /*pinkHigh*/
			cv::Scalar(110, 110, 110), /*grayHigh*/
		};

		for (int i = 0; i < 7; i++) {
			if (GetColor(MatScreen, ScalarLow[i], ScalarHigh[i], Rec)) {
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
				default:
					return Color::NOCOLOR;
				}
				break;
			}
		}
	};

	static bool GetColor(Mat MatScreen, cv::Scalar low, cv::Scalar high, Rect Rec) {
		Mat Roi = MatScreen(Rec);
		Mat Output;

		cv::inRange(Roi, low, high, Output);

		int x1 = countNonZero(Output);
		if (x1 > 200)
			return false;

		return true;
	}
};
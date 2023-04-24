#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "PointGlobalVector.h"
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
			height = templ.rows - 25;
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

		/*int count = 0;*/
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
				//cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(img.cols / 2, 0), CV_RGB(0, 255, 0), 1);
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
					PointReturn.y = matchLoc.y;
					PointReturn.x = matchLoc.x;
					ReturnData.push_back(PointReturn);
					/*count++;*/
				}
				else
					return false;
			}
			else
				break;
		}
		/*cout << count << endl;*/
		cv::imshow(image_window, img_display);

		waitKey(0);
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

		namedWindow(image_window, WINDOW_AUTOSIZE);

		Mat img_display;
		MatScreen.copyTo(img_display);

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
		/*cv::imshow(image_window, img_display);

		waitKey(0);*/

		return PointReturn;
	};

public:
	static vector<POINT> templateMatchingObjects_Vector(Mat MatScreen, Mat templ, double threshold) {
		int height = {}, width = {};
		int match_method = 5;
		Mat result;
		vector<POINT> PointReturn = {};

		Mat img_display;
		MatScreen.copyTo(img_display);

		const char* image_window = "Source Image";
		namedWindow(image_window, WINDOW_AUTOSIZE);

		matchTemplate(MatScreen, templ, result, match_method);
		double minVal; double maxVal; Point minLoc; Point maxLoc;
		Point matchLoc;
		POINT temp = {};

		while (true)
		{
			minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
			if (maxVal >= threshold)
			{
				matchLoc = maxLoc;
				cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);
				//cv::line(img_display, matchLoc, Point(0, 0), CV_RGB(0, 255, 0), 1);
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
					temp.y = matchLoc.y;
					temp.x = matchLoc.x;
					PointReturn.push_back(temp);
				}
			}
			else
				break;
		}

		cv::imshow(image_window, img_display);

		waitKey(0);

		return PointReturn;
	};

public:
	static bool templateMatchingBool(Mat MatScreen, Mat templ, double threshold) {
		int height = {}, width = {};
		int match_method = 5;
		Mat result;
			
		Mat img_display;
		MatScreen.copyTo(img_display);

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
				floodFill(result, matchLoc, 0); //mark drawn blob
				if (matchLoc.y && matchLoc.x != 0) {
					return true;
				}
			}
			else
				break;
		}
		return false;
	};
};


class TextMatching {
public:
	static const string textMatching(Mat MatScreen, Rect Rec)
	{
		Mat Roi = MatScreen(Rec);
		std::unique_ptr<tesseract::TessBaseAPI> tess(new tesseract::TessBaseAPI());
		tess->Init(nullptr, "eng");

		tess->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);

		tess->SetImage(Roi.data, Roi.cols, Roi.rows, Roi.channels(), Roi.step1());
		tess->SetSourceResolution(70);

		std::unique_ptr<char[]> txt(tess->GetUTF8Text());

		if (!not txt) {
			const string str = txt.get();
			return str;
		}
	}
};


class ColorMatching {

public:
	template <typename T>
	static bool colorMatching(Rect Rec, Mat MatScreen, shared_ptr<vector<vector<T>>> shared_vector_ptr) {
		bool found = GetColor(MatScreen, cv::Scalar(0, 100, 60)/*greenLow*/, cv::Scalar(120, 200, 200)/*greenHigh*/, Rec);

		if (found == true)
			return true;

		return false;
	};

private:
	static bool GetColor(Mat MatScreen, cv::Scalar low, cv::Scalar high, Rect Rec) {
		Mat Roi = MatScreen(Rec);
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
		cout << "---- " << x1 << endl;

		if (x1 >= 420)
			return true;

		return false;
	}
};
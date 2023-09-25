#pragma once
#include "TemplateMatching.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <tesseract/baseapi.h>
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace cv;

#define DebugImage1 (1)

vector<POINT> TemplateMatching::templateMatchingItems(string templatename, double threshold, bool MabyHasInsurance, bool RoiNeed, string NameOfItem, Mat MatScreen) {
	vector<POINT> ReturnData;
	int height = {}, width = {};

#if DebugImage1
	const char* image_window = "Source Image";
	const char* Test = "Item Image";
#endif 

	int match_method = 5;
	Mat result;
	Mat img;

	img = MatScreen;
	Mat templ = cv::imread(templatename);
	if (MatScreen.empty() || templ.empty())
		cout << "Error reading file(s) in templateMatching Funkion!" << endl;


#if DebugImage1
	namedWindow(image_window, WINDOW_AUTOSIZE);
	namedWindow(Test, WINDOW_AUTOSIZE);
#endif 

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

#if DebugImage1
	imshow(Test, Roi);
#endif 

	matchTemplate(img, Roi, result, match_method);
	double minVal; double maxVal; Point minLoc; Point maxLoc;
	Point matchLoc;

#if DebugImage1
	int count = 0;
#endif 

	POINT PointReturn{};
	bool test = true;

	//cout << NameOfItem << endl;

	while (true)
	{
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		if (maxVal >= threshold)
		{
			/*if (test == true) {
				test = false;
			}*/

			matchLoc = maxLoc;
			cv::rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), CV_RGB(0, 255, 0), 1);
			/*cv::line(img_display, matchLoc, Point(0 , 0), CV_RGB(0, 255, 0), 1);*/
			//cv::line(img_display, Point(matchLoc.x + templ.cols / 2, matchLoc.y), Point(img.cols / 2, 0), CV_RGB(0, 255, 0), 1);
			floodFill(result, matchLoc, 0); //mark drawn blob
			if (matchLoc.y && matchLoc.x != 0) {
				//cout << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
				PointReturn.y = matchLoc.y;
				PointReturn.x = matchLoc.x;
				ReturnData.push_back(PointReturn);

#if DebugImage1
				count++;
#endif 
			}
			else
				break;
		}
		else
			break;
	}

#if DebugImage1
	cout << count << endl;
	cv::imshow(image_window, img_display);

	if (ReturnData.size() != 0)
		waitKey(0);
	else
		waitKey(20);
#endif 

	return ReturnData;
}


#define DebugImage2 (0)

POINT TemplateMatching::templateMatchingObjects(Mat MatScreen, Mat templ, double threshold) {
	int height = {}, width = {};

#if DebugImage2
	const char* image_window = "Source Image";
#endif

	//const char* Test = "Item Image";

	int match_method = 5;
	Mat result;
	POINT PointReturn = {};

#if DebugImage2
	namedWindow(image_window, WINDOW_AUTOSIZE);
#endif

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
				//cout << "templateMatchingObjects -- " << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
				PointReturn.y = matchLoc.y;
				PointReturn.x = matchLoc.x;
			}
		}
		else
			break;
	}

#if DebugImage2
	cv::imshow(image_window, img_display);

	waitKey(0);
#endif

	return PointReturn;
}

vector<POINT> TemplateMatching::templateMatchingObjects_Vector(Mat MatScreen, Mat templ, double threshold) {
	int height = {}, width = {};
	int match_method = 5;
	Mat result;
	vector<POINT> PointReturn = {};

	Mat img_display;
	MatScreen.copyTo(img_display);

	/*const char* image_window = "Source Image";
	namedWindow(image_window, WINDOW_AUTOSIZE);*/

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
				//cout << "templateMatchingObjects_Vector -- " << matchLoc.y << " " << matchLoc.x << " " << templ.cols << " " << templ.rows << " " << endl;
				temp.y = matchLoc.y;
				temp.x = matchLoc.x;
				PointReturn.push_back(temp);
			}
		}
		else
			break;
	}

	//cv::imshow(image_window, img_display);

	//waitKey(500);

	return PointReturn;
}

bool TemplateMatching::templateMatchingBool(Mat MatScreen, Mat templ, double threshold) {
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
}
	



const string TextMatching::textMatching(Mat MatScreen, Rect Rec) {
	Mat Roi = MatScreen(Rec);

	// Graustufen-Konvertierung
	cvtColor(Roi, Roi, cv::COLOR_BGR2GRAY);

	// Binarisierung 
	threshold(Roi, Roi, 128, 255, cv::THRESH_BINARY);

	std::unique_ptr<tesseract::TessBaseAPI> tess(new tesseract::TessBaseAPI());
	tess->Init("tessdata/", "eng");

	tess->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
	tess->SetVariable("tessedit_char_whitelist", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_|1234567890"); 
	tess->SetVariable("textord_confidence_threshold", "75");

	tess->SetImage(Roi.data, Roi.cols, Roi.rows, Roi.channels(), Roi.step1());
	tess->SetSourceResolution(100);

	std::unique_ptr<char[]> txt(tess->GetUTF8Text());

	if (txt) {
		const string str = txt.get();
		return str;
	}

	return "";
}

const string TextMatching::textMatching_MedicalItems(Mat MatScreen, Rect Rec) {
	Mat Roi = MatScreen(Rec);

	//// Graustufen-Konvertierung

	convertScaleAbs(Roi, Roi, 1.1, 0);// 1 | 0

	//// Binarisierung 
	//threshold(Roi, Roi, 150, 155, cv::THRESH_BINARY);

	cvtColor(Roi, Roi, cv::COLOR_BGR2GRAY);


	//cv::Mat hsvImage;
	//cv::cvtColor(Roi, hsvImage, cv::COLOR_BGR2HSV);

	//// Definiere die Farbgrenzen f�r das Rot im HSV-Farbraum
	//cv::Scalar lowerRed = cv::Scalar(0, 100, 100);     // Untere Grenze f�r Rott�ne in HSV
	//cv::Scalar upperRed = cv::Scalar(10, 255, 255); // Obere Grenze f�r Rott�ne in HSV

	//// Erstelle eine Maske f�r das Rot im Bild
	//cv::Mat maskRed;
	//cv::inRange(hsvImage, lowerRed, upperRed, maskRed);

	//// Setze den roten Bereich im Bild auf Wei�
	//Roi.setTo(cv::Scalar(255, 255, 255), maskRed);


	//const char* image_window = "Source Image";
	//namedWindow(image_window, WINDOW_AUTOSIZE);
	//imshow(image_window, Roi);
	//waitKey(0);

	std::unique_ptr<tesseract::TessBaseAPI> tess(new tesseract::TessBaseAPI());
	tess->Init("tessdata/", "eng");

	tess->SetVariable("fontconfig_use", "tessdata/font.oft");
	tess->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
	tess->SetVariable("tessedit_char_whitelist", "/1234567890");
	tess->SetVariable("textord_confidence_threshold", "75");

	tess->SetImage(Roi.data, Roi.cols, Roi.rows, Roi.channels(), Roi.step1());
	tess->SetSourceResolution(100);

	std::unique_ptr<char[]> txt(tess->GetUTF8Text());

	if (txt) {
		const string str = txt.get();
		return str;
	}

	return "";
}

const string TextMatching::textMatching_ItemName(Mat MatScreen, Rect Rec) {
	Mat Roi = MatScreen(Rec);

	convertScaleAbs(Roi, Roi, 1.1, 0);// 1 | 0

	cvtColor(Roi, Roi, cv::COLOR_BGR2GRAY);

	const char* image_window = "Source Image";
	namedWindow(image_window, WINDOW_AUTOSIZE);
	imshow(image_window, Roi);
	waitKey(0);

	std::unique_ptr<tesseract::TessBaseAPI> tess(new tesseract::TessBaseAPI());
	tess->Init("tessdata/", "eng");

	tess->SetVariable("fontconfig_use", "tessdata/font.oft");
	tess->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
	tess->SetVariable("tessedit_char_whitelist", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-().1234567890\"");
	tess->SetVariable("textord_confidence_threshold", "75");

	tess->SetImage(Roi.data, Roi.cols, Roi.rows, Roi.channels(), Roi.step1());
	tess->SetSourceResolution(100);

	std::unique_ptr<char[]> txt(tess->GetUTF8Text());

	if (txt) {
		const string str = txt.get();
		return str;
	}

	return "";
}



bool ColorMatching::GetColor(Mat MatScreen, cv::Scalar low, cv::Scalar high, Rect Rec) {
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

template <typename T>
static bool ColorMatching::colorMatching(Rect Rec, Mat MatScreen, shared_ptr<vector<vector<T>>> shared_vector_ptr) {
	bool found = GetColor(MatScreen, cv::Scalar(0, 100, 60)/*greenLow*/, cv::Scalar(120, 200, 200)/*greenHigh*/, Rec);

	if (found == true)
		return true;

	return false;
}

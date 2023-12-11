#pragma once
#include "Includes.h"
using namespace cv;
using namespace std;

class TemplateMatching {
public:
	static vector<POINT> templateMatchingItems(string templatename, double threshold, bool MabyHasInsurance, bool RoiNeed, string NameOfItem, Mat MatScreen);

	static POINT templateMatchingObjects(Mat MatScreen, Mat templ, double threshold);

	static vector<POINT> templateMatchingObjects_Vector(Mat MatScreen, Mat templ, double threshold);

	static bool templateMatchingBool(Mat MatScreen, Mat templ, double threshold);
};


struct TextMatching {
	static const string textMatching(Mat MatScreen, Rect Rec);
	static const string textMatching_MedicalItems(Mat MatScreen, Rect Rec);
	static const string textMatching_ItemName(Mat MatScreen, Rect Rec);
	static const int textMatching_OnlyNumbers(Mat MatScreen, Rect Rec);
	static const std::tm textMatching_OnlyNumbers_Time(Mat MatScreen, Rect Rec);
};


class ColorMatching {
	static bool GetColor(Mat MatScreen, cv::Scalar low, cv::Scalar high, Rect Rec);

public:
	template <typename T>
	static bool colorMatching(Rect Rec, Mat MatScreen, shared_ptr<vector<vector<T>>> shared_vector_ptr);
};
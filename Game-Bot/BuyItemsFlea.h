#pragma once
#include "Includes.h"

struct ItemNamePathThreshold {
	string Path;
	string Name;
	string FleaName;
	double Threshold;
};

class SecurityCheck {
	string ExtraktSpaceAndNewlines(string input);
	bool FailSafeDefault(ItemNamePathThreshold& pathNameThreshold, HWND hWND, cv::Mat MatScreen);
	bool FailSafeWithMatching(ItemNamePathThreshold& pathNameThreshold, vector<POINT>& vecItemsToClick, cv::Mat MatScreen, cv::Rect Rec, HWND hWND);
	void ExtraktNameFromSecurityCheck(ItemNamePathThreshold& pathNameThreshold, cv::Mat MatScreen);
	void ClickItemsAndConfirm(vector<POINT> vecItemsToClick, cv::Mat templ, HWND hWND, cv::Rect Rec, int ShiftX);

public:
	bool MakeSecurityCheck();
};

class BuyItemsFlea {
	void TranslateNameAndPasteIn(const char* nameOfItem);
	void TranslateNameAndPasteIn_Medical(const char* nameOfItem);
	void BuyItem(uint8_t quantity);

	SecurityCheck securityCheck;

public:
	bool BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity, bool IsMedical);
};
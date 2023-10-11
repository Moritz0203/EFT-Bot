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
	void BuyItem(int quantity);

	SecurityCheck securityCheck;
	bool ExplicitlyMoreItems = false;

public:
	void OpenFlea(HWND hWND);
	void CloseFlea(HWND hWND);

	bool BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity, bool IsMedical);
	vector<PointItem> EasyBuyItemsAPI(string nameOfItem, uint8_t quantity);

	BuyItemsFlea(bool explicitlyMoreItems) {
		this->ExplicitlyMoreItems = explicitlyMoreItems;
	}

	BuyItemsFlea() {};
};
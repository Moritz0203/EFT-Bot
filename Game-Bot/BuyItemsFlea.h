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

	uint8_t OutOfTrys = 5;

public:
	bool MakeSecurityCheck();
};

class BuyItemsFlea {
	void TranslateNameAndPasteIn(const char* nameOfItem);
	void TranslateNameAndPasteIn_Medical(const char* nameOfItem);
	void BuyItem();

	uint8_t quantity = 0;
	SecurityCheck securityCheck;

public:
	bool BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity, bool IsMedical);
};

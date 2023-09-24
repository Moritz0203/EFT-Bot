#pragma once
#include "Includes.h"

struct InternelNameToFleaName {
	const char* InternelName;
	const char* FleaName;
};

class BuyItemsFlea {
	void TranslateNameAndPasteIn(const char* nameOfItem);
	void BuyItem(uint8_t quantity);
	void MakeSecurityCheck();

public:
	bool BuyItemsFleaOperator(const char* nameOfItem, uint8_t quantity);
};


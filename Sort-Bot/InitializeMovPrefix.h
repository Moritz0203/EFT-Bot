#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "MovPrefixGlobalVector.h"
#include "ItemArraysHEXtoText.h"
using namespace std;

namespace InitializeMovPrefix {
	static std::vector<MovPrefixGroup> movPrefixGroup;
	static std::vector<MovPrefixItem> movPrefixItem;

	void Initialize() {
		string settingsForMoving;

		cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
		cout << ": ";
		cin >> settingsForMoving;
		setup();
	}

	void setup() {
		vector<Prefix> prefix;

		prefix[0].tagOfCase = "Amo";

		movPrefixGroup.emplace_back(ArraysText::Rus762x39, prefix);
		movPrefixGroup.emplace_back(ArraysText::Nato762x51, prefix);
	}
}
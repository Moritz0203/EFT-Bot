#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "MovPrefixGlobalVector.h"
#include "ItemVectorHEXtoText.h"
using namespace std;

namespace InitializeMovPrefix {
	std::vector<MovPrefixGroup> movPrefixGroup;
	std::vector<MovPrefixItem> movPrefixItem;

	void setup();

	void Initialize() {
		/*string settingsForMoving;

		cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
		cout << ": ";*/
		/*cin >> settingsForMoving;*/
		setup();
	}



	void setup() {
		vector<Prefix> prefix;
		
		const string tagCase = "amo";
		Prefix InPrefix;
		InPrefix.tagOfCase = tagCase;
		InPrefix.isFull = false;

		prefix.push_back(InPrefix);
		
		movPrefixGroup.emplace_back(VectorText::Rus762x39, prefix);
		movPrefixGroup.emplace_back(VectorText::Nato762x51, prefix);

		groupedMovPrefixGroup.emplace_back(movPrefixGroup);


		for (int i = 0; i < groupedMovPrefixGroup.size(); i++) {
			for (MovPrefixGroup mov : groupedMovPrefixGroup[i]) {
				for (string out : mov.nameOfItems) {
					cout << out << " " << mov.prefix[0].tagOfCase << endl;
				}
			}
		}
	}
}
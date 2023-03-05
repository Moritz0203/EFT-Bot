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
		string settingsForMoving;

		/*cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
		cout << ": ";
		cin >> settingsForMoving;*/

		setup();
	}



	void setup() {
		vector<Prefix> prefix;
		Prefix InPrefix;
		Prefix InPrefix1;
		TagMovPrefixGroup test;

		const string tagCase = "amo1";
		InPrefix.tagOfCase = tagCase;
		InPrefix.isFull = false;

		const string tagCase1 = "amo2";
		InPrefix1.tagOfCase = tagCase1;
		InPrefix1.isFull = true;

		prefix.push_back(InPrefix);
		prefix.push_back(InPrefix1);
		
		movPrefixGroup.emplace_back(VectorText::Rus762x39, prefix);
		movPrefixGroup.emplace_back(VectorText::Nato762x51, prefix);

		test.identyfierAsHEX = 0x1;
		test.movPrefixGroup = movPrefixGroup;

		groupedMovPrefixGroup.push_back(test);

		for (TagMovPrefixGroup v1 : groupedMovPrefixGroup) {
			cout << v1.identyfierAsHEX << endl;
			for (MovPrefixGroup v2 : v1.movPrefixGroup) {
				

				for (string str : v2.nameOfItems) {
					cout << "|-> " << str << " -->   ";
					for (Prefix pre : v2.prefix) {
						cout << pre.tagOfCase << " - " << pre.isFull << ", ";
					}
					cout << endl;
				}

				
			}
		}
	}
}
#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "ItemVectorHEXtoText.h"
using namespace std;

namespace InitializeMovPrefix {
	/*std::vector<MovPrefixGroup> movPrefixGroup;
	std::vector<MovPrefixItem> movPrefixItem;*/

	/*void setup();*/
	void setup_prefix();

	void Initialize() {
		string settingsForMoving;

		cout << "start Initialize" << endl;

		/*cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
		cout << ": ";
		cin >> settingsForMoving;*/

		/*setup();*/

		setup_prefix();
		cout << "end Initialize" << endl;

	}

	void setup_prefix() {
		Prefix prefix;
		AssignPrefix assingPrefix_temp;

		prefix.isFull = false;
		for (string str : VectorText::Nato762x51) {
			prefix.nameOfItems.push_back(str);
		}
		for (string str : VectorText::Nato556x45) {
			prefix.nameOfItems.push_back(str);
		}

		for (string str : prefix.nameOfItems) {
			cout << str << endl;
		}

		assingPrefix_temp.prefix = prefix;
		assingPrefix_temp.tagOfCase = "AMO-1|";

		AssignPrefix::assignPrefix.push_back(assingPrefix_temp);


		prefix.isFull = false;
		prefix.nameOfItems = VectorText::Rus762x39;

		for (string str : VectorText::Rus762x39) {
			prefix.nameOfItems.push_back(str);
		}
		for (string str : VectorText::Rus545x39) {
			prefix.nameOfItems.push_back(str);
		}


		for (string str : prefix.nameOfItems) {
			cout << str << endl;
		}

		assingPrefix_temp.prefix = prefix;
		assingPrefix_temp.tagOfCase = "AMO-2|";

		AssignPrefix::assignPrefix.push_back(assingPrefix_temp);
	}

	/*void setup() {
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

		test.identyfierAsHEX = 0x01;
		test.movPrefixGroup = movPrefixGroup;

		groupedMovPrefixGroup.push_back(test);

		for (TagMovPrefixGroup v1 : groupedMovPrefixGroup) {
			cout << "Identyfier ->   0x" << hex << v1.identyfierAsHEX << "   = Ammunition" << endl;
			for (MovPrefixGroup v2 : v1.movPrefixGroup) {

				for (string str : v2.nameOfItems) {
					int length = 15 - str.length();
					
					cout << "                 |-> " << str;
					for (int i = 0; i < length; i++) {
						cout << " ";
					}
					cout << "-->    ";

					for (Prefix pre : v2.prefix) {
						cout << pre.tagOfCase << " - " << pre.isFull << ", ";
					}
					cout << endl;
				}
			}
		}
	}*/
}
#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

namespace InitializeMovPrefix {
	
	void Initialize() {
		string settingsForMoving;

		cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
		cout << ": ";
		cin >> settingsForMoving;

	}

}
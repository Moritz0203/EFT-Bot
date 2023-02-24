#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include "MovPrefixGlobalVector.h"
using namespace std;

namespace InitializeMovPrefix {
	
	void Initialize() {
		string settingsForMoving;

		cout << "Do you want to keep the default settings for moving the items or set your own \n( type 'yes' for I want to keep them, type 'no' to change them or type 'view' to see the default settings ). \n" << endl;
		cout << ": ";
		cin >> settingsForMoving;
	}

	void setup() {
		
	}

	std::array<std::string, 7> Rus762x25{
		"TTAKBS",
		"TTFMJ43",
		"TTLRN",
		"TTLRNPC",
		"TTP",
		"TTPst",
		"TTPT"
	};

	std::array<std::string, 5> Nato762x35{
		"BlackoutAP",
		"BlackoutBCPFMJ",
		"BlackoutM62Tracer",
		"BlackoutV-Max",
		"Whisper"
	};

	std::array<std::string, 6> Rus762x39{
		"BP",
		"HP",
		"MAIAP",
		"PS",
		"T45M1",
		"US"
	};

	std::array<std::string, 7> Nato762x51{
		"M80",
		"M62",
		"M61",
		"M993",
		"BCPFMJ",
		"TCWSP",
		"UltraNosi"
	};

	std::array<std::string, 6> Rus762x54R{
		"RBS",
		"RBT",
		"RLPS",
		"RPS",
		"RSNB",
		"RT-46M"
	};
}
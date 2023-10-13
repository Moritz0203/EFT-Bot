#pragma once
#include "Includes.h"

typedef enum e_pouch_version {
	Waist = 0,
	Alpha = 1,
	Beta = 2,
	Epsilon = 3,
	Gamma = 4,
	Kappa = 5,
	Default_Pouch = 10,
}pouch_version;

struct PathNameThresholdSlots {
	const char* Path;
	const char* Name;
	const double Threshold;
	const uint8_t Slots;
};


class PouchProcessing {
	const vector<PathNameThresholdSlots> PouchVector{
		{"CaseImages/Waist_Pouch.png",				"Waist",	0.90, 4 },//Waist
		{"CaseImages/Secure_container_Alpha.png",	"Alpha",	0.90, 4 },//Alpha
		{"CaseImages/Secure_container_Beta.png",	"Beta",		0.90, 6 },//Beta
		{"CaseImages/Secure_container_Epsilon.png", "Epsilon",	0.90, 8 },//Epsilon
		{"CaseImages/Secure_container_Gamma.png",	"Gamma",	0.90, 9 },//Gamma
		{"CaseImages/Secure_container_Kappa.png",	"Kappa",	0.90, 12},//Kappa
	};

	pouch_version Pouch_Version = Default_Pouch;
	static bool FirstStart;

	void ShiftOutItems(uint8_t rows, uint8_t cols);
	void Pouch_FirstStart();
	void PouchItemCheck();

public:
	void PouchMatching();
	void PouchOperator();

	PouchProcessing(pouch_version Pouch){
		this->Pouch_Version = Pouch;
	}
};
#pragma once
#include "Includes.h"	

typedef enum e_map {
	Interchange = 0,
	Woods = 1,
	Shoreline = 2,
	Default = 10,
}Map;

struct MapDependeces {
	const char* MapImagePath;
	const char* MapName;
	const double Threshold;
	const std::tm LowerTimeLimit;
	const std::tm UpperTimeLimite;
};

class OueueProcessing {

	const vector<MapDependeces> MapVector{
		{"ObjectImages/Interchange.png",	"Interchange",	0.90, { 0, 30, 6 }, { 0, 0, 19 }},//Interchange
		{"ObjectImages/Woods.png",			"Woods",		0.90, { 0, 0, 0 },	{ 0, 0, 0 }},//Woods
		{"ObjectImages/Shoreline.png",		"Shoreline",	0.90, { 0, 0, 21 }, { 0, 0, 5 }},//Shoreline
	};

	void ClickNextButton();	
	void ClickReadyButton();
	void ClickEscapeFromTarkov();
	void ClickOnMap();
	void SelectTime();
	void Incurance();

	Map _Map = Default;
	bool _Incurance = false;

public:

	OueueProcessing(Map map, bool insure) {
		this->_Map = map;
		this->_Incurance = insure;
	}	

	void OueueProcess();
};


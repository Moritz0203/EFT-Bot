#pragma once
#include "Includes.h"	

typedef enum e_map {
	Interchange = 0,
	Woods = 1,
	Shoreline = 2,
	Default = 10,
}Map;

struct MapDependeces {
	const char* Path;
	const char* MapName;
	const double Threshold;
	const std::tm LowerTimeLimit;
	const std::tm UpperTimeLimite;
	const bool NoTimeLimit;
};

class OueueProcessing {

	const vector<MapDependeces> MapVector{
		{"ObjectImages/Interchange.png",	"Interchange",	0.90, { 0, 30, 6 }, { 0, 0, 19 }, false },//Interchange
		{"ObjectImages/Woods.png",			"Woods",		0.90, { 0, 0, 0 },	{ 0, 0, 0 },  true  },//Woods
		{"ObjectImages/Shoreline.png",		"Shoreline",	0.90, { 0, 0, 21 }, { 0, 0, 5 },  false},//Shoreline
	};

	void ClickNextButton();	
	void ClickReadyButton();
	void ClickEscapeFromTarkov();
	void ClickOnMap();
	void SelectTime();
	void Incurance();
	
	bool IsTimeInRange(const std::tm& timeToCheck, const std::tm& start, const std::tm& end) {
		std::tm tempTimeToCheck = timeToCheck;
		std::tm tempStartTime = start;
		std::tm tempEndTime = end;

		std::time_t time = std::mktime(&tempTimeToCheck);
		std::time_t startTime = std::mktime(&tempStartTime);
		std::time_t endTime = std::mktime(&tempEndTime);

		return (time >= startTime && time <= endTime);
	}

	Map MapToRun = Default;
	bool NeedIncurance = false;

public:

	OueueProcessing(Map map, bool insure) {
		this->MapToRun = map;
		this->NeedIncurance = insure;
	}	

	void OueueProcess();
};


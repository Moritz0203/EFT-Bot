#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Includes.h"
#include "Walk.h"

typedef enum e_HealthSystem_InGame {
	Light_Bleeding = 0,
	Heavy_Bleeding = 1,
	Fracture = 2,
	Pain = 3,
	Dehydration = 4,
	Starvation = 5,
}HealthSystem_InGame;

struct HealthDependences {
	const HealthSystem_InGame HealthType;
	const char* Path;
	const char* Name;
	const double Threshold;
	std::vector<std::shared_ptr<void>> ItemsBest;
	std::vector<std::shared_ptr<void>> ItemsSecond;
	bool HaveItem;
	int waitTime; // In seconds
};

struct ItemDependence {
	const HealthSystem_InGame HealthType;
	std::vector<string> ItemsBest; // If empty use ItemsSecond
	std::vector<string> ItemsSecond;
};

enum ErrorCodes_Health {
	ThreadAlreadyRunning_H = 1,
	ThreadNotRunning_H = 2,
};
extern ErrorCodes_Health ErrorCodes_H;

class Health {
	
	std::vector<HealthDependences> HealthDependencesList {
		{ Light_Bleeding, "ObjectImages/Health/Light_Bleeding.png", "Light_Bleeding", 0.97, {}, {}, false, 8 },
		{ Heavy_Bleeding, "ObjectImages/Health/Heavy_Bleeding.png", "Heavy_Bleeding", 0.97, {}, {}, false, 8 },
		{ Fracture,		  "ObjectImages/Health/Fracture.png",		"Fracture",       0.97, {}, {}, false, 8 },
		{ Pain,			  "ObjectImages/Health/Pain.png",			"Pain",			  0.97, {}, {}, false, 0 },
		{ Dehydration,	  "ObjectImages/Health/Dehydration.png",    "Dehydration",    0.97, {}, {}, false, 5 },
		{ Starvation,	  "ObjectImages/Health/Starvation.png",		"Starvation",     0.97, {}, {}, false, 6 },
	};

	shared_ptr<Walk> walkObject_ptr;

	void DistributorHealth();
	void HealthWorker();

	void CheckHealth();
	void DoProcess(HealthSystem_InGame thingToDo);

	bool MedicalItemCheck(PointMedical pointMedical);

public:

	Health(std::shared_ptr<vector<PointMedical>> medicalItemVec_ptr, std::shared_ptr<vector<PointBarter>> barterItemVec_ptr, shared_ptr<Walk> walkObject_ptr);

	int StartHealthSystem();
	int StopHealthSystem();

};
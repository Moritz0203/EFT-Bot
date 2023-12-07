#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Includes.h"


typedef enum e_HealthSystem_InGame {
	Light_Bleeding = 0,
	Heavy_Bleeding = 1,
	Fracture = 2,
	Pain = 3,
	Dehydration = 4,
	Starvation = 5,
}HealthSystem_InGame;

struct HealthDependences {
	const HealthSystem_InGame Health;
	const char* Path;
	const char* Name;
	const double Threshold;
	std::vector<std::shared_ptr<void>> ItemsBest;
	std::vector<std::shared_ptr<void>> Items;
	bool HaveItem;
};

struct ItemDependence {
	const HealthSystem_InGame Health;
	std::vector<string> ItemsBest; // If empty use Items
	std::vector<string> Items;
};


namespace ItemDependences_Vec {
	
	std::vector<ItemDependence> ItemDependencesList{
		{ Light_Bleeding, { "ArmyBandage", "Bandage" }, { "AFAK", "AI2", "CarKit", "Grizzly", "IFAK", "Salewa" } },
		{ Heavy_Bleeding, { "CAT", "Esmarch", "Hemostatic" }, { "AFAK", "CarKit", "Grizzly", "IFAK", "Salewa" } },
		{ Fracture,		  { "AluSplint", "Splint" }, { "Grizzly", "Surv12" } },
		{ Pain,			  { }, { } },
		{ Dehydration,	  { "AppleJuice", "Aquamari", "EmergencyWaterRation", "GrandJuice", "GreenTea", "HotRod", "Kvass", "MaxEnergy", "Milk",	"Pineapple", "RatCola", "TarCola", "VitaJuice", "Water" }, { "Peas" } },
		{ Starvation,	  { "Alyonka", "BigTushonka", "Condmilk", "Crackers", "Croutons", "Emeyla", "Herring", "Humpback", "Iskra", "Mayo", "MRE", "Oatflakes", "Peas", "Saury", "Slickers", "Sprats", "Squash", "Tushonka" }, { "AppleJuice", "Aquamari", "GrandJuice", "Kvass", "MaxEnergy", "Milk", "Pineapple", "VitaJuice" } },
	};

}



class Health {
	
	std::vector<HealthDependences> HealthDependencesList{
		{ Light_Bleeding, "Health/Light_Bleeding.png", "Light_Bleeding", 0.90, {}, {}, false },
		{ Heavy_Bleeding, "Health/Heavy_Bleeding.png", "Heavy_Bleeding", 0.90, {}, {}, false },
		{ Fracture,		  "Health/Fracture.png",	   "Fracture",       0.90, {}, {}, false },
		{ Pain,			  "Health/Pain.png",		   "Pain",		     0.90, {}, {}, false },
		{ Dehydration,	  "Health/Dehydration.png",    "Dehydration",    0.90, {}, {}, false },
		{ Starvation,	  "Health/Starvation.png",	   "Starvation",     0.90, {}, {}, false },
	};

public:

	Health(std::shared_ptr<vector<PointMedical>> medicalItemVec_ptr, std::shared_ptr<vector<PointBarter>> barterItemVec_ptr) {
		
	
	}
};
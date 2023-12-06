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
	std::vector<std::shared_ptr<void>> Items;
	bool HaveItem;
};

struct ItemDependence {
	const HealthSystem_InGame Health;
	std::vector<string> Items;
};


namespace ItemDependences_Vec {
	
	std::vector<ItemDependence> ItemDependencesList{
		{ Light_Bleeding, {} },
		{ Heavy_Bleeding, {} },
		{ Fracture,		  {} },
		{ Pain,			  {} },
		{ Dehydration,	  {} },
		{ Starvation,	  {} },
	};

}


class Health {
	
	std::vector<HealthDependences> HealthDependencesList{
		{ Light_Bleeding, "Health/Light_Bleeding.png", "Light_Bleeding", 0.90, {}, false },
		{ Heavy_Bleeding, "Health/Heavy_Bleeding.png", "Heavy_Bleeding", 0.90, {}, false },
		{ Fracture,		  "Health/Fracture.png",	   "Fracture",       0.90, {}, false },
		{ Pain,			  "Health/Pain.png",		   "Pain",		     0.90, {}, false },
		{ Dehydration,	  "Health/Dehydration.png",    "Dehydration",    0.90, {}, false },
		{ Starvation,	  "Health/Starvation.png",	   "Starvation",     0.90, {}, false },
	};

public:

	Health(std::shared_ptr<vector<PointMedical>> medicalItemVec_ptr, std::shared_ptr<vector<PointBarter>> barterItemVec_ptr) {
		
	
	}
};
#pragma once
#include <vector>
#include <string>
#include <memory>

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
	bool HaveItem = false;
};


class Health {

	

};
#include "GameControler.h"
#include "StashObject.h"
#include "getMat.h"
#include "Walk.h"
#include "Health.h"
#include "TemplateMatching.h"



void GameControler::getDataFromServer() {
	// NOTE: Later it needs to check server for any updates on MoveType and MovingCondition
	this->moveType = MoveType::MOVE_TYPE_RANDOM;
	this->movingCondition = MovingCondition::MOVING_CONDITION_SPRINT;
}


void GameControler::Controler() {
	Walk walk(false, moveType, movingCondition);

	std::shared_ptr<Walk> walkPtr = std::make_shared<Walk>(walk);
	std::shared_ptr<vector<PointMedical>> medicalPtr = std::make_shared<vector<PointMedical>>(Pouch::pouch.ItemsInPouch_Medical);
	std::shared_ptr<vector<PointBarter>> barterPtr = std::make_shared<vector<PointBarter>>(Pouch::pouch.ItemsInPouch_Barter);
	
	Health health(medicalPtr, barterPtr, walkPtr);

	walk.StartMoving();
	health.StartHealthSystem();

	// NOTE: Later it needs to check server for any updates on MoveType and MovingCondition
	HWND hWND = GetMat::FindeWindow();
	while (true) {

		std::this_thread::sleep_for(std::chrono::seconds(15));

		cv::Mat MatScreen = GetMat::getMat(hWND);

		if (TemplateMatching::templateMatchingBool(MatScreen, imread("ObjectImages/EXP.png"), 0.95)) {
			walk.StopMoving();
			health.StopHealthSystem();
			break;
		}
	}
}
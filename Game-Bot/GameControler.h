#pragma once
#include "Walk.h"



class GameControler {
	MoveType moveType;
	MovingCondition movingCondition;

	void getDataFromServer();

public:

	GameControler() {
		getDataFromServer();
	}
	
	void Controler();
};
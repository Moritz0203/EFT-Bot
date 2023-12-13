#pragma once


class GameControler {
	MoveType moveType{ MoveType::MOVE_TYPE_NONE };
	MovingCondition movingCondition{ MovingCondition::MOVING_CONDITION_NONE };

	void getDataFromServer();

public:

	GameControler() {
		getDataFromServer();
	}
	
	void Controler();
};


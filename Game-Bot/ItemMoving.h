#pragma once
#include "MovPrefix.h"


class ItemMoving {
	void MovFromStash(PointerStack& prefix);
	void MovFromCase(PointerStack& prefix);

	//void MovingProcessing(vector<MovPrefix> input);

	uint8_t lastPage = 0;
public:

	void MovingOperator();
};
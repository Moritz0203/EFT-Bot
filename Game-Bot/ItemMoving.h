#pragma once
#include "MovPrefix.h"


class ItemMoving {
	void MovFromStash(MovPrefix& prefix);
	void MovFromCase(MovPrefix& prefix);

	void MovingProcessing(vector<MovPrefix> input);

	uint8_t lastPage = 0;
public:

	void MovingOperator();
};
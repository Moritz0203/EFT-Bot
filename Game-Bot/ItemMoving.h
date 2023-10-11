#pragma once
#include "MovPrefix.h"


class ItemMoving {
	void MovFromCase(PointerStack prefix);

	uint8_t lastPage = 0;
public:
	void MovFromStash(PointerStack prefix);

	void MovOneItem(MovPrefix& movPrefix);

	void MovingOperator();
};
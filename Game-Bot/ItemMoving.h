#pragma once
#include "MovPrefix.h"


class ItemMoving {
	void MovFromStash(PointerStack& prefix);
	void MovFromCase(PointerStack& prefix);

	uint8_t lastPage = 0;
public:

	void MovOneItem(MovPrefix& movPrefix);

	void MovingOperator();
};